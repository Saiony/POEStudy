// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "POEComboWindow.generated.h"

/**
 * 
 */
UCLASS()
class POESTUDY_API UPOEComboWindow : public UAnimNotifyState
{
	GENERATED_BODY()
	
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> ASC;
	
	FName ComboWindowTag = FName("AN.ComboWindowActive");
	
public:
	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference) override;
	
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;	
};
