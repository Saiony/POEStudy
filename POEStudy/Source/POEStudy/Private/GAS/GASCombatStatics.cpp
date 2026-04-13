// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/GASCombatStatics.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "Kismet/KismetSystemLibrary.h"
#include "AbilitySystemBlueprintLibrary.h"

TArray<UAbilitySystemComponent*> UGASCombatStatics::GetActorsWithASCInSphere(const UObject* WorldContextObject, FVector Origin, float Radius, const TArray<AActor*>& IgnoredActors)
{
	TArray<AActor*> OverlappedActors;
	UKismetSystemLibrary::SphereOverlapActors(WorldContextObject, Origin, Radius, TArray<TEnumAsByte<EObjectTypeQuery>>(), 
											  APawn::StaticClass(), IgnoredActors, OverlappedActors);

	TArray<UAbilitySystemComponent*> ASCs;
	for (const auto Actor : OverlappedActors)
	{
		if (const auto ASCInterface = Cast<IAbilitySystemInterface>(Actor))
		{
			if (UAbilitySystemComponent* ASC = ASCInterface->GetAbilitySystemComponent())
			{
				ASCs.Add(ASC);
			}
		}
	}
	
	return ASCs;
}

void UGASCombatStatics::ApplyKnockback(AActor* Target, FVector Origin, float KnockbackForce)
{
	ACharacter* Character = Cast<ACharacter>(Target);
	
	if (!Character)
	{
		UE_LOG(LogTemp, Error, TEXT("Target must be a Character in order to apply knockback"));
		return;
	}

	const auto Direction = (Target->GetActorLocation() - Origin).GetSafeNormal();
	const auto LaunchVelocity = Direction * KnockbackForce;

	Character->LaunchCharacter(LaunchVelocity, true, true);
}

void UGASCombatStatics::ApplyEffectWithCustomDuration(UAbilitySystemComponent* InstigatorASC, UAbilitySystemComponent* TargetASC, TSubclassOf<UGameplayEffect> EffectClass, float Duration)
{
	FGameplayEffectContextHandle ContextHandle = InstigatorASC->MakeEffectContext();
	FGameplayEffectSpecHandle SpecHandle = InstigatorASC->MakeOutgoingSpec(EffectClass, 1.0f, ContextHandle);
	
	UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(SpecHandle, FGameplayTag::RequestGameplayTag("Ability.Duration"), Duration);
	InstigatorASC->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), TargetASC);
}
