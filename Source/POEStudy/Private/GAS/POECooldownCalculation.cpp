// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/POECooldownCalculation.h"

#include "GAS/POEGameplayAbility.h"

float UPOECooldownCalculation::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	const auto GA = Cast<UPOEGameplayAbility>(Spec.GetContext().GetAbility());

	if(!GA)
	{
		UE_LOG(LogTemp, Error, TEXT("Couldn't fetch Gameplay Ability on BaseCalculation"))
		return 0;
	}

	return GA->CoolDown;	
}
