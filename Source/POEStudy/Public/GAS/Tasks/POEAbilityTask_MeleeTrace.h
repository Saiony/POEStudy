// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "POEAbilityTask_MeleeTrace.generated.h"

class UPOEAttackWindowData;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMeleeTraceHitDetected, const TArray<UAbilitySystemComponent*>&, HitTargets);


/**
 * 
 */
UCLASS()
class POESTUDY_API UPOEAbilityTask_MeleeTrace : public UAbilityTask
{
	GENERATED_BODY()
	
	UPROPERTY()
	const UPOEAttackWindowData* CachedWindowData;

	UPROPERTY()
	TArray<AActor*> HitActors;

	void PerformTrace();
	void TryAddASC(AActor* HitActor, TArray<UAbilitySystemComponent*>& OutHitASCs);
	
protected:
	virtual void Activate() override;
	
public:
	UPROPERTY(BlueprintAssignable)
	FMeleeTraceHitDetected OnHitDetected;

	UFUNCTION(BlueprintCallable, Category = "Ability|Tasks", meta = (HidePin = "OwningAbility", DefaultToSelf = "OwningAbility"))
	static UPOEAbilityTask_MeleeTrace* CreateMeleeTrace(UGameplayAbility* OwningAbility,
	                                                    const UPOEAttackWindowData* WindowData);

	virtual void TickTask(float DeltaTime) override;
	virtual void OnDestroy(bool AbilityEnded) override;
};
