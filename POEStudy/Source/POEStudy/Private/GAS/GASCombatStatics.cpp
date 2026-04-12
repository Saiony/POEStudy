// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/GASCombatStatics.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "GameplayEffect.h"
#include "GameFramework/Character.h"
#include "Kismet/KismetSystemLibrary.h"

class UAbilitySystemComponent;

void UGASCombatStatics::ApplyEffectToActorsInSphere(AActor* Instigator, FVector Origin, float Radius, TSubclassOf<UGameplayEffect> EffectClass, float EffectLevel, float KnockbackForce)
{
	if (!Instigator)
	{
		UE_LOG(LogTemp, Error, TEXT("Instigator is null"));
		return;
	}
	
	if (!EffectClass)
	{
		UE_LOG(LogTemp, Error, TEXT("Instigator is null"));
		return;
	}

	//DrawDebugSphere(Instigator->GetWorld(), Origin, Radius, 16, FColor::Red, false, 2.);		

	UAbilitySystemComponent* InstigatorASC = nullptr;
	const auto ASCInterface = Cast<IAbilitySystemInterface>(Instigator);
	if (ASCInterface)	
		InstigatorASC = ASCInterface->GetAbilitySystemComponent();

	if (!InstigatorASC)
		return;

	TArray<AActor*> IgnoredActors;
	IgnoredActors.Add(Instigator);

	TArray<AActor*> OverlappedActors;
	UKismetSystemLibrary::SphereOverlapActors(Instigator, Origin, Radius, TArray<TEnumAsByte<EObjectTypeQuery>>(), 
											  APawn::StaticClass(),IgnoredActors, OverlappedActors);

	const auto ContextHandle = InstigatorASC->MakeEffectContext();
	const auto SpecHandle = InstigatorASC->MakeOutgoingSpec(EffectClass, EffectLevel, ContextHandle);

	if (!SpecHandle.IsValid())
		return;

	for (const auto TargetActor : OverlappedActors)
	{
		if (!TargetActor)
			continue;

		const auto TargetInterface = Cast<IAbilitySystemInterface>(TargetActor);
		if (!TargetInterface)
			continue;

		const auto TargetASC = TargetInterface->GetAbilitySystemComponent();
		if (!TargetASC)
			continue;

		InstigatorASC->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), TargetASC);
		
		if (KnockbackForce != 0.0f)
			ApplyKnockback(TargetActor, Origin, KnockbackForce);
	}
}

void UGASCombatStatics::ApplyKnockback(AActor* Target, FVector Origin, float KnockbackForce)
{
	ACharacter* Character = Cast<ACharacter>(Target);
	
	if (!Character)
	{
		UE_LOG(LogTemp, Error, TEXT("Target must be a Character in order to apply knockback"));
		return;
	}

	const auto Direction = (Target->GetActorLocation() - Origin).GetSafeNormal();
	const auto Distance = FVector::Dist(Target->GetActorLocation(), Origin);
	const auto LaunchVelocity = Direction * KnockbackForce;

	Character->LaunchCharacter(LaunchVelocity, true, true);
}
