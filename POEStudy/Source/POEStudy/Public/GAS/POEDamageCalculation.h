// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "POEDamageCalculation.generated.h"

/**
 * 
 */
UCLASS()
class POESTUDY_API UPOEDamageCalculation : public UGameplayModMagnitudeCalculation
{
	UPROPERTY(EditDefaultsOnly, Category = "Damage")
	FGameplayEffectAttributeCaptureDefinition DamageAttribute;
	
	GENERATED_BODY()
	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;
};
