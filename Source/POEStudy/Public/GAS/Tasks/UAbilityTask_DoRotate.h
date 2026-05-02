// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "UAbilityTask_DoRotate.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoRotateFinished);


/**
 * 
 */
UCLASS()
class POESTUDY_API UUAbilityTask_DoRotate : public UAbilityTask
{
	GENERATED_BODY()
	
	FRotator StartRotation;
	FRotator TargetRotation;
	float Duration;
	float ElapsedTime = 0.f;
	
	UPROPERTY()
	TObjectPtr<AActor> Actor;
	
protected:	
	virtual void Activate() override;
	
public:
	UPROPERTY(BlueprintAssignable)
	FDoRotateFinished OnFinished;

	UFUNCTION(BlueprintCallable, Category = "Ability|Tasks", meta = (HidePin = "OwningAbility", DefaultToSelf = "OwningAbility"))
	static UUAbilityTask_DoRotate* DoRotate(UGameplayAbility* OwningAbility, FRotator TargetRotation, float Duration);

	virtual void TickTask(float DeltaTime) override;
};
