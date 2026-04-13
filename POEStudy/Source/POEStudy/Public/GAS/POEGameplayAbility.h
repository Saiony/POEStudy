// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "POEGameplayAbility.generated.h"

class APOEStudyCharacter;
class APOEStudyPlayerController;

/**
 *	Defines how an ability is meant to activate.
 */
UENUM(BlueprintType)
enum class EPOEAbilityActivationPolicy : uint8
{
	// Try to activate the ability when the input is triggered.
	OnInputTriggered,

	// Continually try to activate the ability while the input is active.
	WhileInputActive,

	// Try to activate the ability when an avatar is assigned.
	OnSpawn
};


/**
 * 
 */
UCLASS()
class POESTUDY_API UPOEGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
protected:
	
	// Defines how this ability is meant to activate.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ability")
	EPOEAbilityActivationPolicy ActivationPolicy;

public:
	UPROPERTY(EditDefaultsOnly)
	float Cost;

	UPROPERTY(EditDefaultsOnly)
	float CoolDown;
	
	UPROPERTY(EditDefaultsOnly)
	float DamageMultiplier;
	
	UFUNCTION(BlueprintCallable, Category = "Ability")
	APOEStudyCharacter* GetPOECharacterFromActorInfo() const;

	UFUNCTION(BlueprintCallable, Category = "Ability")
	APOEStudyPlayerController* GetPOEPlayerControllerFromActorInfo() const;
	
	UFUNCTION(BlueprintCallable, Category = "Ability")
	FVector ClampDestination(const FVector& Origin, const FVector& Destination, float MaxDistance) const;
	
	EPOEAbilityActivationPolicy GetActivationPolicy() const { return ActivationPolicy; }
};
