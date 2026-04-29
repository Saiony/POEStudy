// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "GAS/POEAbilitySystemComponent.h"
#include "POEAttributesWidget.generated.h"


class UTextBlock;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class POESTUDY_API UPOEAttributesWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Widget")
	void InitWidget(UPOEAbilitySystemComponent* ASC);

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> HealthText;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> MaxHealthText;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> ManaText;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> MaxManaText;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> AttackSpeedText;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> StunnedText;
	
	void OnHealthChanged(const FOnAttributeChangeData& Data);
	void OnMaxHealthChanged(const FOnAttributeChangeData& Data);
	
	void OnManaChanged(const FOnAttributeChangeData& Data);
	void OnMaxManaChanged(const FOnAttributeChangeData& Data);
	
	void OnAttackSpeedChanged(const FOnAttributeChangeData& Data);
	
	void OnStunChanged(FGameplayTag GameplayTag, int32 NewCount);
};
