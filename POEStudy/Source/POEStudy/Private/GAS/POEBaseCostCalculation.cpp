// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/POEBaseCostCalculation.h"

#include "GAS/POEGameplayAbility.h"

float UPOEBaseCostCalculation::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	const auto GA = Cast<UPOEGameplayAbility>(Spec.GetContext().GetAbility());

	if(!GA)
	{
		UE_LOG(LogTemp, Error, TEXT("Couldn't fetch Gameplay Ability on BaseCalculation"))
		return 0;
	}

	return -GA->Cost;
}
