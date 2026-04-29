// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/POEInputConfigDA.h"

UPOEInputConfigDA::UPOEInputConfigDA(const FObjectInitializer& ObjectInitializer)
{
}

const UInputAction* UPOEInputConfigDA::FindNativeInputActionForTag(const FGameplayTag& InputTag) const
{
	for(const FPOEInputAction& Action : NativeInputActions)
	{
		if(Action.InputAction && (Action.InputTag == InputTag))
		{
			return Action.InputAction;
		}
	}

	UE_LOG(LogTemp, Error, TEXT("Can't find NativeInputAction for InputTag [%s] on InputConfig [%s]."), *InputTag.ToString(), *GetNameSafe(this));
	return nullptr;
}

const UInputAction* UPOEInputConfigDA::FindAbilityInputActionForTag(const FGameplayTag& InputTag) const
{
	for(const FPOEInputAction& Action : AbilityInputActions)
	{
		if(Action.InputAction && (Action.InputTag == InputTag))
		{
			return Action.InputAction;
		}
	}

	UE_LOG(LogTemp, Error, TEXT("Can't find AbilityInputAction for InputTag [%s] on InputConfig [%s]."), *InputTag.ToString(), *GetNameSafe(this));
	return nullptr;
}
