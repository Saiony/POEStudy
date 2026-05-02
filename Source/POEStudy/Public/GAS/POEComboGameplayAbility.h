// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "POEGameplayAbility.h"
#include "POEComboGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class POESTUDY_API UPOEComboGameplayAbility : public UPOEGameplayAbility
{
	GENERATED_BODY()
	
protected:
	void OnPressCallback() override;
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "POE")
	int32 ComboIndex = 0;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "POE")
	TArray<TObjectPtr<UAnimMontage>> ComboAnims;
	
	// UFUNCTION(BlueprintImplementableEvent, Category = "POE")
	// void Attack(int32 ComboIndex);	
};
