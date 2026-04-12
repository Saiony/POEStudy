// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/POEDamageCalculation.h"

#include "GAS/POEGameplayAbility.h"

float UPOEDamageCalculation::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	FAggregatorEvaluateParameters Params;
	float AttributeValue = 0.0f;
	
	GetCapturedAttributeMagnitude(DamageAttribute, Spec, Params, AttributeValue);

	return -AttributeValue;
}
