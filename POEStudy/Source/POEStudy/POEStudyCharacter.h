// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "Data/POEAbilityData.h"
#include "GameFramework/Character.h"
#include "GAS/POECombatAttributeSet.h"
#include "Data/POEAbilityData.h"
#include "Public/GAS/POEAbilitySystemComponent.h"
#include "POEStudyCharacter.generated.h"

class UInputMappingContext;
class UPOEInputConfigDA;
class UWidgetComponent;
class UPOEAttributesWidget;
class UPOETweenComponent;

UCLASS(Blueprintable)
class APOEStudyCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
	TArray<uint32> BindHandles;
	
	FPOEAbilitySet_GrantedHandles* GrantedHandles;

public:
	APOEStudyCharacter();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }		
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "POE")
	TObjectPtr<UPOEAbilitySystemComponent> AbilitySystemComp;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "POE", meta=(AllowPrivateAccess))
	TObjectPtr<UPOECombatAttributeSet> CombatAttributeSet;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "POE")	
	TObjectPtr<UWidgetComponent> AttributesWidgetComp;	

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "POE")
	TObjectPtr<UPOETweenComponent> TweenComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "POE")
	TObjectPtr<UPOEInputConfigDA> InputConfigDA;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "POE", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputMappingContext> DefaultMappingContext;
	
	UFUNCTION(BlueprintImplementableEvent, Category = "POE")
	void OnCharacterLanded(const FHitResult& Hit);

	virtual void Landed(const FHitResult& Hit) override;
	
	virtual void BeginPlay() override;
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void Input_AbilityInputTagPressed(FGameplayTag InputTag);
	void Input_AbilityInputTagReleased(FGameplayTag InputTag);
	
	UFUNCTION(BlueprintCallable, Category = "POE")
	void GiveAbilityWithTag(UPOEAbilityData* AbilityData, FGameplayTag InputTag);

private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;
};

