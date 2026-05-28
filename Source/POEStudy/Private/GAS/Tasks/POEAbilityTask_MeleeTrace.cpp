// Fill out your copyright notice in the Description page of Project Settings.

#include "GAS/Tasks/POEAbilityTask_MeleeTrace.h"
#include "AbilitySystemInterface.h"
#include "AnimNotify/POEAttackWindowData.h"
#include "AnimNotify/POEMeleeAttackWindow.h"
#include "Engine/OverlapResult.h"
#include "POEStudy/POEStudyCharacter.h"


static TAutoConsoleVariable<bool> CVarDebugMeleeTrace(
    TEXT("POE.Debug.MeleeTrace"),
    false,
    TEXT("Enables debug drawing for melee traces"),
    ECVF_Default
);

UPOEAbilityTask_MeleeTrace* UPOEAbilityTask_MeleeTrace::CreateMeleeTrace(UGameplayAbility* OwningAbility, const UPOEAttackWindowData* WindowData)
{
    UPOEAbilityTask_MeleeTrace* Task = NewAbilityTask<UPOEAbilityTask_MeleeTrace>(OwningAbility);
    Task->CachedWindowData = WindowData;
    Task->bTickingTask = true;
    
    return Task;
}

void UPOEAbilityTask_MeleeTrace::Activate()
{
    HitActors.Empty();
}

void UPOEAbilityTask_MeleeTrace::TickTask(float DeltaTime)
{
    Super::TickTask(DeltaTime);
    PerformTrace();
}

void UPOEAbilityTask_MeleeTrace::PerformTrace()
{
    if (!CachedWindowData)
    {
        UE_LOG(LogTemp, Error, TEXT("CachedWindowData is null"));
        return;
    }

    const APOEStudyCharacter* Character = Cast<APOEStudyCharacter>(GetAvatarActor());
    if (!Character)
    {
        UE_LOG(LogTemp, Error, TEXT("PerformTrace: Avatar actor is not APOEStudyCharacter"));
        return;
    }

    if (!Character->GetMesh())
    {
        UE_LOG(LogTemp, Error, TEXT("PerformTrace: Character mesh is null"));
        return;
    }

    UWorld* World = GetWorld();
    if (!World)
    {
        UE_LOG(LogTemp, Error, TEXT("PerformTrace: World is null"));
        return;
    }
    
    const FVector Origin = Character->GetMesh()->GetSocketLocation(CachedWindowData->Socket);
    const FQuat Rotation = Character->GetMesh()->GetSocketQuaternion(CachedWindowData->Socket);

    FCollisionQueryParams Params;
    Params.AddIgnoredActor(Character);

    TArray<UAbilitySystemComponent*> HitASCs;

    switch (CachedWindowData->TraceShape)
    {
        case EAttackTraceShape::Sphere:
        {
            TArray<FOverlapResult> Overlaps;
            World->OverlapMultiByChannel(Overlaps, Origin, FQuat::Identity, ECC_Pawn,
                                                FCollisionShape::MakeSphere(CachedWindowData->TraceSizeA), Params);
                
            for (const auto& Overlap : Overlaps)
                TryAddASC(Overlap.GetActor(), HitASCs);
                
            if (CVarDebugMeleeTrace.GetValueOnGameThread())
            {
                DrawDebugSphere(GetWorld(), Origin, CachedWindowData->TraceSizeA, 16, 
                                HitASCs.Num() > 0 ? FColor::Red : FColor::Green, false, 0.1f);
            }
                
            break;
        }
        case EAttackTraceShape::Box:
        {
            TArray<FOverlapResult> Overlaps;
            World->OverlapMultiByChannel(Overlaps, Origin, Rotation, ECC_Pawn,
                                                FCollisionShape::MakeBox(FVector(CachedWindowData->TraceSizeA)), Params);
                
            for (const auto& Overlap : Overlaps)
                TryAddASC(Overlap.GetActor(), HitASCs);
                
                if (CVarDebugMeleeTrace.GetValueOnGameThread())
                {
                    DrawDebugBox(GetWorld(), Origin, FVector(CachedWindowData->TraceSizeA), Rotation,
                   HitASCs.Num() > 0 ? FColor::Red : FColor::Green, false, 0.1f);
                }
                
            break;
        }
        case EAttackTraceShape::Line:
        {
            TArray<FHitResult> HitResults;
            const FVector End = Origin + Character->GetActorForwardVector() * CachedWindowData->TraceSizeA;
                
            World->LineTraceMultiByChannel(HitResults, Origin, End, ECC_Pawn, Params);
                
            for (const auto& HitResult : HitResults) 
                TryAddASC(HitResult.GetActor(), HitASCs);
                
                if (CVarDebugMeleeTrace.GetValueOnGameThread())
                {
                    DrawDebugLine(GetWorld(), Origin, End,
                    HitASCs.Num() > 0 ? FColor::Red : FColor::Green, false, 0.1f, 0, 1.f);
                }
                
            break;
        }
        case EAttackTraceShape::Capsule:
        {
            const FVector CapsuleCenter = Origin + Rotation.GetUpVector() * CachedWindowData->TraceSizeA;
            TArray<FOverlapResult> Overlaps;
            World->OverlapMultiByChannel(Overlaps, CapsuleCenter, Rotation, ECC_Pawn,
                                                FCollisionShape::MakeCapsule(CachedWindowData->TraceSizeB, CachedWindowData->TraceSizeA), 
                                                Params);
                
            for (const auto& Overlap : Overlaps)
                TryAddASC(Overlap.GetActor(), HitASCs);
                
            if (CVarDebugMeleeTrace.GetValueOnGameThread())
            {
                DrawDebugCapsule(GetWorld(), CapsuleCenter, CachedWindowData->TraceSizeA, CachedWindowData->TraceSizeB,
                Rotation, HitASCs.Num() > 0 ? FColor::Red : FColor::Green, false, 0.1f);
            }
                
            break;
        }
    }

    if (HitASCs.Num() > 0)
    {
        OnHitDetected.Broadcast(HitASCs);
    }
}

void UPOEAbilityTask_MeleeTrace::TryAddASC(AActor* HitActor, TArray<UAbilitySystemComponent*>& OutHitASCs)
{
    if (HitActors.Contains(HitActor)) //attack on this actor already registered
        return;

    const auto ASCInterface = Cast<IAbilitySystemInterface>(HitActor);
    
    if (!ASCInterface)
        return;

    auto TargetASC = ASCInterface->GetAbilitySystemComponent();
    
    HitActors.Add(HitActor);
    OutHitASCs.Add(TargetASC);
}

void UPOEAbilityTask_MeleeTrace::OnDestroy(bool AbilityEnded)
{
    HitActors.Empty();
    Super::OnDestroy(AbilityEnded);
}