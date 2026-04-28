// Fill out your copyright notice in the Description page of Project Settings.


#include "POEEnemySimple.h"

#include "Components/WidgetComponent.h"
#include "GAS/POECombatAttributeSet.h"
#include "UI/POEAttributesWidget.h"


// Sets default values
APOEEnemySimple::APOEEnemySimple()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	AbilitySystemComp = CreateDefaultSubobject<UPOEAbilitySystemComponent>(TEXT("ASC"));
	
	AttributesWidgetComp = CreateDefaultSubobject<UWidgetComponent>(TEXT("AttributesWidgetComponent"));
	AttributesWidgetComp->SetupAttachment(RootComponent);
	AttributesWidgetComp->SetWidgetSpace(EWidgetSpace::Screen);
	AttributesWidgetComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	AttributesWidgetComp->SetWidgetClass(UPOEAttributesWidget::StaticClass());
	
	CombatAttributeSet = CreateDefaultSubobject<UPOECombatAttributeSet>("CombatAttributeSet");
}

// Called when the game starts or when spawned
void APOEEnemySimple::BeginPlay()
{
	Super::BeginPlay();
	
	auto AttributesWidget = Cast<UPOEAttributesWidget>(AttributesWidgetComp->GetUserWidgetObject());
	AttributesWidget->InitWidget(AbilitySystemComp);
}

// Called every frame
void APOEEnemySimple::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APOEEnemySimple::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

UAbilitySystemComponent* APOEEnemySimple::GetAbilitySystemComponent() const
{
	return AbilitySystemComp;
}
