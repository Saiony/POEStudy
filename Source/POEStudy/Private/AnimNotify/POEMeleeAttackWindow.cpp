// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotify/POEMeleeAttackWindow.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AnimNotify/POEAttackWindowData.h"

void UPOEMeleeAttackWindow::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{	
	AActor* Owner = MeshComp->GetOwner();
	if (!Owner)
	{
		UE_LOG(LogTemp, Error, TEXT("Owner is null"));
		return;
	}

	const auto ASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Owner);
	if (!ASC)
	{
		UE_LOG(LogTemp, Error, TEXT("ASC is null"));	
		return;
	}
	
	auto AttackWindowData = NewObject<UPOEAttackWindowData>(Owner);
	AttackWindowData->Init(Socket, TraceShapeType, TraceSizeA, TraceSizeB);
	
	FGameplayEventData EventData;
	EventData.OptionalObject = AttackWindowData;
	
	ASC->HandleGameplayEvent(FGameplayTag::RequestGameplayTag(FName("AN.AttackWindowStart")), &EventData);
}

void UPOEMeleeAttackWindow::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
	const FAnimNotifyEventReference& EventReference)
{
	AActor* Owner = MeshComp ? MeshComp->GetOwner() : nullptr;
	if (!Owner)
	{
		UE_LOG(LogTemp, Error, TEXT("NotifyEnd: Owner is null"));
		return;
	}

	const auto ASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Owner);
	if (!ASC)
	{
		UE_LOG(LogTemp, Error, TEXT("NotifyEnd: ASC is null"));
		return;
	}

	FGameplayEventData EventData;
	ASC->HandleGameplayEvent(FGameplayTag::RequestGameplayTag(FName("AN.AttackWindowEnd")), &EventData);

	Super::NotifyEnd(MeshComp, Animation, EventReference);
}