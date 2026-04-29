// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/TimelineComponent.h"
#include "POETweenComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class POESTUDY_API UPOETweenComponent : public UActorComponent
{
	GENERATED_BODY()

	FVector StartLocation;
	FVector TargetLocation;
	
	FOnTimelineFloat ProgressUpdate;
	
	FTimeline Timeline;
	
	float JumpHeight = 0.0f;	

public:
	UPOETweenComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void DoJump(UCurveFloat* CurveFloat, const FVector TargetPos, float Duration, float InJumpHeight);
	
	UFUNCTION()
	void TimelineTick(float Value);
};
