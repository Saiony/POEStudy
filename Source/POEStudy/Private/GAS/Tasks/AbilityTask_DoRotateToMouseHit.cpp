// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/Tasks/AbilityTask_DoRotateToMouseHit.h"

#include "GAS/Tasks/UAbilityTask_DoRotate.h"


UAbilityTask_DoRotateToMouseHit* UAbilityTask_DoRotateToMouseHit::DoRotateToMouseHit(UGameplayAbility* OwningAbility, float Duration, bool LockZAxis)
{
	auto Task = NewAbilityTask<UAbilityTask_DoRotateToMouseHit>(OwningAbility);
	Task->Duration = Duration;
	Task->LockZAxis = LockZAxis;
	
	return Task;
}

void UAbilityTask_DoRotateToMouseHit::Activate()
{
	const auto Avatar = GetAvatarActor();
	const auto PC = Avatar->GetWorld()->GetFirstPlayerController(); //NPCs can look at player's mouse pos

	// gets world mouse hit pos
	FHitResult HitResult;
	PC->GetHitResultUnderCursorByChannel(UEngineTypes::ConvertToTraceType(ECC_Visibility),false, HitResult);

	if (!HitResult.bBlockingHit) 
		return;

	// necessary rotation to look to mouse hit pos
	FVector Direction = (HitResult.Location - Avatar->GetActorLocation()).GetSafeNormal();
	
	if (LockZAxis)
	{
		Direction.Z = 0.f;
		Direction = Direction.GetSafeNormal();
	}
	
	const FRotator TargetRotation = FRotationMatrix::MakeFromX(Direction).Rotator();

	const auto RotateTask = UUAbilityTask_DoRotate::DoRotate(Ability, TargetRotation, Duration);
	RotateTask->OnFinished.AddDynamic(this, &ThisClass::OnRotateFinished);
	RotateTask->ReadyForActivation();
}

void UAbilityTask_DoRotateToMouseHit::OnRotateFinished()
{
	OnFinished.Broadcast();
	EndTask();
}