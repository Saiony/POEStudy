// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "AbilityTask_DoRotateToMouseHit.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoRotateToMouseHitFinished);


/**
 * 
 */
UCLASS()
class POESTUDY_API UAbilityTask_DoRotateToMouseHit : public UAbilityTask
{
	GENERATED_BODY()
	
	float Duration;
	
	bool LockZAxis;

protected:
	virtual void Activate() override;
	
public:
	UPROPERTY(BlueprintAssignable)
	FDoRotateToMouseHitFinished OnFinished;

	UFUNCTION(BlueprintCallable, Category = "Ability|Tasks", meta = (HidePin = "OwningAbility", DefaultToSelf = "OwningAbility"))
	static UAbilityTask_DoRotateToMouseHit* DoRotateToMouseHit(UGameplayAbility* OwningAbility, float Duration, bool LockZAxis = true);
	
	UFUNCTION()
	void OnRotateFinished();
};
