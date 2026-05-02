// Fill out your copyright notice in the Description page of Project Settings.


#include "POEStudy/Public/GAS/POEGameplayAbility.h"

#include "Abilities/Tasks/AbilityTask_WaitGameplayEvent.h"
#include "AnimNotify/POEAttackWindowData.h"
#include "GAS/Tasks/POEAbilityTask_MeleeTrace.h"
#include "POEStudy/POEStudyCharacter.h"
#include "POEStudy/POEStudyPlayerController.h"

class UAbilityTask_WaitGameplayTagAdded;

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
		UE_LOG(LogTemp, Error, TEXT("GetPOEStudyPlayerController: Controller is null on Pawn %s"),
		       *AvatarPawn->GetName());
		return nullptr;
	}

	APOEStudyPlayerController* PC = Cast<APOEStudyPlayerController>(Controller);
	if (!PC)
	{
		UE_LOG(LogTemp, Error, TEXT("GetPOEStudyPlayerController: Cast failed, Controller is of type %s"),
		       *Controller->GetClass()->GetName());
		return nullptr;
	}

	return PC;
}

FVector UPOEGameplayAbility::ClampDestination(const FVector& Origin, const FVector& Destination,
                                              const float MaxDistance) const
{
	const FVector Direction = Destination - Origin;
	float Distance = Direction.Size();

	if (Distance <= MaxDistance)
		return Destination;

	return Origin + Direction.GetSafeNormal() * MaxDistance;
}

void UPOEGameplayAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                          const FGameplayAbilityActorInfo* ActorInfo,
                                          const FGameplayAbilityActivationInfo ActivationInfo,
                                          const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	const auto ASC = ActorInfo->AbilitySystemComponent.Get();

	//Subscribe to InputPressed
	DelegateHandle = ASC->AbilityReplicatedEventDelegate(EAbilityGenericReplicatedEvent::InputPressed, Handle, ActivationInfo.GetActivationPredictionKey()).AddUObject(this, &ThisClass::OnPressCallback);

	//Subscribe to AttackWindowStart
	const auto WaitAttackWindowStart = UAbilityTask_WaitGameplayEvent::WaitGameplayEvent(this, FGameplayTag::RequestGameplayTag(FName("AN.AttackWindowStart")));
	WaitAttackWindowStart->EventReceived.AddDynamic(this, &ThisClass::OnHitWindowStart);
	WaitAttackWindowStart->ReadyForActivation();

	//Subscribe to AttackWindowEnd
	const auto WaitAttackWindowEnd = UAbilityTask_WaitGameplayEvent::WaitGameplayEvent(this, FGameplayTag::RequestGameplayTag(FName("AN.AttackWindowEnd")));
	WaitAttackWindowEnd->EventReceived.AddDynamic(this, &ThisClass::OnHitWindowEnd);
	WaitAttackWindowEnd->ReadyForActivation();
}

void UPOEGameplayAbility::OnPressCallback()
{
	OnInputPressed();
}

void UPOEGameplayAbility::OnHitWindowStart(FGameplayEventData Payload)
{
	const auto WindowData = Cast<UPOEAttackWindowData>(Payload.OptionalObject);
	if (!WindowData)
	{
		UE_LOG(LogTemp, Error, TEXT("OnHitWindowStart: Payload OptionalObject is not UPOEAttackWindowData"));
		return;
	}

	if (ActiveMeleeTrace)
	{
		ActiveMeleeTrace->EndTask();
		ActiveMeleeTrace = nullptr;
	}

	ActiveMeleeTrace = UPOEAbilityTask_MeleeTrace::CreateMeleeTrace(this, WindowData);
	if (!ActiveMeleeTrace)
	{
		UE_LOG(LogTemp, Error, TEXT("OnHitWindowStart: Failed to create melee trace task"));
		return;
	}

	ActiveMeleeTrace->OnHitDetected.AddDynamic(this, &ThisClass::OnHitDetected);
	ActiveMeleeTrace->ReadyForActivation();
}

void UPOEGameplayAbility::OnHitWindowEnd(FGameplayEventData Payload)
{
	if (!ActiveMeleeTrace)
	{
		UE_LOG(LogTemp, Warning, TEXT("OnHitWindowEnd: ActiveMeleeTrace is null"));
		return;
	}

	ActiveMeleeTrace->EndTask();
	ActiveMeleeTrace = nullptr;
}
