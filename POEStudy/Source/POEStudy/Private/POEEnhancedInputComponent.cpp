// Fill out your copyright notice in the Description page of Project Settings.


#include "POEEnhancedInputComponent.h"


// Sets default values for this component's properties
UPOEEnhancedInputComponent::UPOEEnhancedInputComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UPOEEnhancedInputComponent::AddInputMappings(const UPOEInputConfigDA* InputConfig, UEnhancedInputLocalPlayerSubsystem* InputSubsystem) const
{
	check(InputConfig);
	check(InputSubsystem);

	// Here you can handle any custom logic to add something from your input config if required
}

void UPOEEnhancedInputComponent::RemoveInputMappings(const UPOEInputConfigDA* InputConfig, UEnhancedInputLocalPlayerSubsystem* InputSubsystem) const
{
	check(InputConfig);
	check(InputSubsystem);

	// Here you can handle any custom logic to remove input mappings that you may have added above
}

void UPOEEnhancedInputComponent::RemoveBinds(TArray<uint32>& BindHandles)
{
	for(uint32 Handle : BindHandles)
	{
		RemoveBindingByHandle(Handle);
	}
	BindHandles.Reset();
}
