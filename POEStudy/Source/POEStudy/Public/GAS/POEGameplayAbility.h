// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "POEGameplayAbility.generated.h"

class APOEStudyCharacter;
class APOEStudyPlayerController;

/**
 * 
 */
UCLASS()
class POESTUDY_API UPOEGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	float Cost;

	UPROPERTY(EditDefaultsOnly)
	float CoolDown;
	
	UFUNCTION(BlueprintCallable, Category = "Ability")
	APOEStudyCharacter* GetPOECharacterFromActorInfo() const;

	UFUNCTION(BlueprintCallable, Category = "Ability")
	APOEStudyPlayerController* GetPOEPlayerControllerFromActorInfo() const;
	
	UFUNCTION(BlueprintCallable, Category = "Ability")
	FVector ClampDestination(const FVector& Origin, const FVector& Destination, float MaxDistance) const;
};
