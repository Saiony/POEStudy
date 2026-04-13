// Copyright Epic Games, Inc. All Rights Reserved.

#include "POEStudyCharacter.h"

#include "EnhancedInputSubsystems.h"
#include "POEEnhancedInputComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "Materials/Material.h"
#include "Engine/World.h"
#include "UI/POEAttributesWidget.h"
#include "Components/POETweenComponent.h"
#include "Data/POEAbilityData.h"

APOEStudyCharacter::APOEStudyCharacter()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
	
	AbilitySystemComp = CreateDefaultSubobject<UPOEAbilitySystemComponent>(TEXT("ASC"));
	
	AttributesWidgetComp = CreateDefaultSubobject<UWidgetComponent>(TEXT("AttributesWidgetComponent"));
	AttributesWidgetComp->SetupAttachment(RootComponent);
	AttributesWidgetComp->SetWidgetSpace(EWidgetSpace::World);
	AttributesWidgetComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	AttributesWidgetComp->SetWidgetClass(UPOEAttributesWidget::StaticClass());
	
	CombatAttributeSet = CreateDefaultSubobject<UPOECombatAttributeSet>("CombatAttributeSet");
	
	TweenComponent = CreateDefaultSubobject<UPOETweenComponent>(TEXT("TweenComponent"));
}

void APOEStudyCharacter::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
}

void APOEStudyCharacter::Landed(const FHitResult& Hit)
{
	Super::Landed(Hit);
	OnCharacterLanded(Hit);
}

void APOEStudyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if(const APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if(UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
	
	auto AttributesWidget = Cast<UPOEAttributesWidget>(AttributesWidgetComp->GetUserWidgetObject());
	AttributesWidget->InitWidget(AbilitySystemComp);
}

UAbilitySystemComponent* APOEStudyCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComp;
}

void APOEStudyCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	const auto InputComp = Cast<UPOEEnhancedInputComponent>(PlayerInputComponent);
	if(!InputComp)
	{
		UE_LOG(LogTemp, Error, TEXT( "'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. "
				   "If you intend to use the legacy system, then you will need to update this C++ file." ), *GetNameSafe(this));
		return;
	}

	// This is where we actually bind and input action to a gameplay tag, which means that Gameplay Ability Blueprints will
	// be triggered directly by these input actions Triggered events.
	InputComp->BindAbilityActions(InputConfigDA, this, &ThisClass::Input_AbilityInputTagPressed, &ThisClass::Input_AbilityInputTagReleased, /*out*/ BindHandles);
}

void APOEStudyCharacter::Input_AbilityInputTagPressed(FGameplayTag InputTag)
{
	AbilitySystemComp->AbilityInputTagPressed(InputTag);
}

void APOEStudyCharacter::Input_AbilityInputTagReleased(FGameplayTag InputTag)
{
	AbilitySystemComp->AbilityInputTagReleased(InputTag);
}

void APOEStudyCharacter::GiveAbilityWithTag(UPOEAbilityData* AbilityData, FGameplayTag InputTag)
{
	AbilityData->GiveToAbilitySystem(AbilitySystemComp, GrantedHandles, InputTag);
}
