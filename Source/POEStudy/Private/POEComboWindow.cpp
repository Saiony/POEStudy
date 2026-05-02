// Fill out your copyright notice in the Description page of Project Settings.


#include "POEComboWindow.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"

void UPOEComboWindow::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	if (!MeshComp || !MeshComp->GetWorld() || !MeshComp->GetWorld()->IsGameWorld()) 
		return;

	AActor* Owner = MeshComp->GetOwner();
	if (!Owner)
	{
		UE_LOG(LogTemp, Error, TEXT("Owner is null"));
		return;
	}

	ASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Owner);
	if (!ASC)
	{
		UE_LOG(LogTemp, Error, TEXT("ASC is null"));
		return;
	}

	ASC->AddLooseGameplayTag(FGameplayTag::RequestGameplayTag(FName("AN.ComboWindowActive")));
}

void UPOEComboWindow::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	if (!MeshComp || !MeshComp->GetWorld() || !MeshComp->GetWorld()->IsGameWorld()) 
		return;
	
	ASC->RemoveLooseGameplayTag(FGameplayTag::RequestGameplayTag(FName("AN.ComboWindowActive")));
}
