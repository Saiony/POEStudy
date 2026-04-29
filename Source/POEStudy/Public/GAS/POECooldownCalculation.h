// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "POECooldownCalculation.generated.h"

/**
 * 
 */
UCLASS()
class POESTUDY_API UPOECooldownCalculation : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()
	
	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;
};
