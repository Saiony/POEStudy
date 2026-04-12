// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GASCombatStatics.generated.h"

class UGameplayEffect;
/**
 * 
 */
UCLASS()
class POESTUDY_API UGASCombatStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	static void ApplyEffectToActorsInSphere(AActor* Instigator, FVector Origin, float Radius, TSubclassOf<UGameplayEffect> EffectClass, float EffectLevel = 1.0f, float KnockbackForce = 0.0f);
	
	UFUNCTION(BlueprintCallable)
	static void ApplyKnockback(AActor* Target, FVector Origin, float KnockbackForce);
};
