// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "POEEnemySimple.generated.h"

class UWidgetComponent;
class UPOECombatAttributeSet;
class UPOEAbilitySystemComponent;

UCLASS()
class POESTUDY_API APOEEnemySimple : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APOEEnemySimple();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "POE")
	TObjectPtr<UPOEAbilitySystemComponent> AbilitySystemComp;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "POE", meta=(AllowPrivateAccess))
	TObjectPtr<UPOECombatAttributeSet> CombatAttributeSet;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "POE")
	TObjectPtr<UWidgetComponent> AttributesWidgetComp;
};
