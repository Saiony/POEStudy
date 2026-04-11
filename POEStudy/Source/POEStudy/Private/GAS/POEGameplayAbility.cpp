// Fill out your copyright notice in the Description page of Project Settings.


#include "POEStudy/Public/GAS/POEGameplayAbility.h"
#include "POEStudy/POEStudyCharacter.h"
#include "POEStudy/POEStudyPlayerController.h"

APOEStudyCharacter* UPOEGameplayAbility::GetPOECharacterFromActorInfo() const
{
	return Cast<APOEStudyCharacter>(GetAvatarActorFromActorInfo());
}

APOEStudyPlayerController* UPOEGameplayAbility::GetPOEPlayerControllerFromActorInfo() const
{
	if (!CurrentActorInfo)
	{
		UE_LOG(LogTemp, Error, TEXT("GetPOEStudyPlayerController: CurrentActorInfo is null"));
		return nullptr;
	}

	APawn* AvatarPawn = Cast<APawn>(CurrentActorInfo->AvatarActor.Get());
	if (!AvatarPawn)
	{
		UE_LOG(LogTemp, Error, TEXT("GetPOEStudyPlayerController: AvatarActor is null or is not a Pawn"));
		return nullptr;
	}

	AController* Controller = AvatarPawn->GetController();
	if (!Controller)
	{
		UE_LOG(LogTemp, Error, TEXT("GetPOEStudyPlayerController: Controller is null on Pawn %s"), *AvatarPawn->GetName());
		return nullptr;
	}

	APOEStudyPlayerController* PC = Cast<APOEStudyPlayerController>(Controller);
	if (!PC)
	{
		UE_LOG(LogTemp, Error, TEXT("GetPOEStudyPlayerController: Cast failed, Controller is of type %s"), *Controller->GetClass()->GetName());
		return nullptr;
	}

	return PC;
}

FVector UPOEGameplayAbility::ClampDestination(const FVector& Origin, const FVector& Destination, const float MaxDistance) const
{
	const FVector Direction = Destination - Origin;
	float Distance = Direction.Size();

	if (Distance <= MaxDistance)
		return Destination;

	return Origin + Direction.GetSafeNormal() * MaxDistance;
}
