// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GASCombatStatics.generated.h"

class UGameplayEffect;
class UAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class POESTUDY_API UGASCombatStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	static TArray<UAbilitySystemComponent*> GetActorsWithASCInSphere(const UObject* WorldContextObject, FVector Origin, float Radius, const TArray<AActor*>& IgnoredActors);
	
	UFUNCTION(BlueprintCallable)
	static void ApplyKnockback(AActor* Target, FVector Origin, float KnockbackForce);
	
	UFUNCTION(BlueprintCallable)
	static void ApplyEffectWithCustomDuration(UAbilitySystemComponent* InstigatorASC, UAbilitySystemComponent* TargetASC, TSubclassOf<UGameplayEffect> EffectClass, float Duration);
};
