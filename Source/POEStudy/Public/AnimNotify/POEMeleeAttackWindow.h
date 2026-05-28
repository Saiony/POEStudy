// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "GAS/POEAbilitySystemComponent.h"
#include "POEMeleeAttackWindow.generated.h"


UENUM(BlueprintType)
enum class EAttackTraceShape : uint8
{
	Sphere,
	Box,
	Line,
	Capsule
};


/**
 * 
 */
UCLASS()
class POESTUDY_API UPOEMeleeAttackWindow : public UAnimNotifyState
{
	GENERATED_BODY()
	
	UPROPERTY()
	TObjectPtr<UPOEAbilitySystemComponent> POEASC;
	
public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack Window")
	FName Socket = FName("hand_r");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack Window")
	EAttackTraceShape TraceShapeType = EAttackTraceShape::Sphere;
	
	//Generic size for every TraceShapeType
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack Window")
	float TraceSizeA = 1;
	
	//Generic size for every TraceShapeType
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack Window")
	float TraceSizeB = 1;
	
	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference) override;
	
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;
};
