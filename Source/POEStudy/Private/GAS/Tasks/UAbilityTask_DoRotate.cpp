// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS\Tasks\UAbilityTask_DoRotate.h"

UUAbilityTask_DoRotate* UUAbilityTask_DoRotate::DoRotate(UGameplayAbility* OwningAbility, FRotator TargetRotation, float Duration)
{
	const auto Task = NewAbilityTask<UUAbilityTask_DoRotate>(OwningAbility);
	Task->TargetRotation = TargetRotation;
	Task->Duration = Duration;
	Task->bTickingTask = true;
	
	return Task;
}

void UUAbilityTask_DoRotate::Activate()
{
	Actor = GetAvatarActor();

	StartRotation = Actor->GetActorRotation();
	ElapsedTime = 0.f;
}

void UUAbilityTask_DoRotate::TickTask(float DeltaTime)
{
	Super::TickTask(DeltaTime);	
	ElapsedTime += DeltaTime;	
	
	const float Alpha = FMath::Clamp(ElapsedTime / Duration, 0.f, 1.f);
	const FRotator NewRotation = FMath::Lerp(StartRotation, TargetRotation, Alpha);
	
	Actor->SetActorRotation(NewRotation);

	if (Alpha >= 1.f)
	{
		OnFinished.Broadcast();
		EndTask();
	}
}