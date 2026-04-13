// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/POETweenComponent.h"

UPOETweenComponent::UPOETweenComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	ProgressUpdate.BindUFunction(this, FName("TimelineTick"));
}

void UPOETweenComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	Timeline.TickTimeline(DeltaTime);
}

void UPOETweenComponent::DoJump(UCurveFloat* CurveFloat, const FVector TargetPos, float Duration, float InJumpHeight)
{
	AActor* Owner = GetOwner();
	if (!Owner || !CurveFloat)
	{
		UE_LOG(LogTemp, Error, TEXT("Owner or CurveFloat is null"));
		return;
	}

	StartLocation = Owner->GetActorLocation();
	TargetLocation = TargetPos;
	JumpHeight = InJumpHeight;

	Timeline.Stop();	
	Timeline = FTimeline();
	
	float MinTime, MaxTime;
	CurveFloat->GetTimeRange(MinTime, MaxTime);
	float CurveLength = MaxTime - MinTime;
	
	Timeline.AddInterpFloat(CurveFloat, ProgressUpdate);		
	Timeline.SetPlayRate(CurveLength / Duration);
		
	Timeline.SetTimelineLength(MaxTime);	
	Timeline.PlayFromStart();
}

void UPOETweenComponent::TimelineTick(float Value)
{
	AActor* Owner = GetOwner();
	if (!Owner)
	{
		UE_LOG(LogTemp, Error, TEXT("Owner is null"));
		return;
	}
	
	if (Timeline.GetTimelineLength() <= 0.0f)
	{
		UE_LOG(LogTemp, Error, TEXT("Timeline length is zero or negative"));
		return;
	}

	float Alpha = Timeline.GetPlaybackPosition() / Timeline.GetTimelineLength();
	Alpha = FMath::Clamp(Alpha, 0.f, 1.f);

	FVector NewPos = FMath::Lerp(StartLocation, TargetLocation, Alpha);
	NewPos.Z += Value * JumpHeight; 

	Owner->SetActorLocation(NewPos, true);
}
