// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "POECombatAttributeSet.generated.h"

//Epic Game's recommended macro for AttributeSet
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

class UPOECombatAttributeSet;
DECLARE_MULTICAST_DELEGATE_ThreeParams(FOnStaminaChanged, UPOECombatAttributeSet*, float, float);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnStaminaChangedDynamic, UPOECombatAttributeSet*, OwningComp, float, NewStamina, float, Delta);

DECLARE_MULTICAST_DELEGATE_FourParams(FOnHealthChanged, AActor*, UPOECombatAttributeSet*, float, float);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnHealthChangedDynamic, AActor*, InstigatorActor, UPOECombatAttributeSet*, OwningComp, float, NewHealth, float, Delta);


UCLASS()
class POESTUDY_API UPOECombatAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Health = 100;
	ATTRIBUTE_ACCESSORS(UPOECombatAttributeSet, Health);	
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData MaxHealth = 100;
	ATTRIBUTE_ACCESSORS(UPOECombatAttributeSet, MaxHealth);
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Mana = 100;
	ATTRIBUTE_ACCESSORS(UPOECombatAttributeSet, Mana);	
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData MaxMana = 100;
	ATTRIBUTE_ACCESSORS(UPOECombatAttributeSet, MaxMana);
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData AttackSpeed = 1;
	ATTRIBUTE_ACCESSORS(UPOECombatAttributeSet, AttackSpeed);	
};
