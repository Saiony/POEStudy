// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/POEComboGameplayAbility.h"

#include "AbilitySystemComponent.h"

void UPOEComboGameplayAbility::OnPressCallback()
{	
	Super::OnPressCallback();
	
	if (GetAbilitySystemComponentFromActorInfo()->HasMatchingGameplayTag(FGameplayTag::RequestGameplayTag(FName("AN.ComboWindowActive"))))
	{
		//Attack(ComboIndex);
	}
}
