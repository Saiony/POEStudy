// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/POEAttributesWidget.h"

#include "Components/TextBlock.h"
#include "GAS/POECombatAttributeSet.h"

void UPOEAttributesWidget::InitWidget(UPOEAbilitySystemComponent* ASC)
{
    if (!ASC)
    {
        UE_LOG(LogTemp, Error, TEXT("ASC cannot be null"));
        return;
    }

    ASC->GetGameplayAttributeValueChangeDelegate(UPOECombatAttributeSet::GetHealthAttribute()).AddUObject(this, &UPOEAttributesWidget::OnHealthChanged);
    ASC->GetGameplayAttributeValueChangeDelegate(UPOECombatAttributeSet::GetMaxHealthAttribute()).AddUObject(this, &UPOEAttributesWidget::OnMaxHealthChanged);
    ASC->GetGameplayAttributeValueChangeDelegate(UPOECombatAttributeSet::GetManaAttribute()).AddUObject(this, &UPOEAttributesWidget::OnManaChanged);
    ASC->GetGameplayAttributeValueChangeDelegate(UPOECombatAttributeSet::GetMaxManaAttribute()).AddUObject(this, &UPOEAttributesWidget::OnMaxManaChanged);
    ASC->GetGameplayAttributeValueChangeDelegate(UPOECombatAttributeSet::GetAttackSpeedAttribute()).AddUObject(this, &UPOEAttributesWidget::OnAttackSpeedChanged);
    
    HealthText->SetText(FText::AsNumber(ASC->GetNumericAttribute(UPOECombatAttributeSet::GetHealthAttribute())));
    MaxHealthText->SetText(FText::AsNumber(ASC->GetNumericAttribute(UPOECombatAttributeSet::GetMaxHealthAttribute())));
    ManaText->SetText(FText::AsNumber(ASC->GetNumericAttribute(UPOECombatAttributeSet::GetManaAttribute())));
    MaxManaText->SetText(FText::AsNumber(ASC->GetNumericAttribute(UPOECombatAttributeSet::GetMaxManaAttribute())));
    AttackSpeedText->SetText(FText::AsNumber(ASC->GetNumericAttribute(UPOECombatAttributeSet::GetAttackSpeedAttribute())));

}

void UPOEAttributesWidget::OnHealthChanged(const FOnAttributeChangeData& Data)
{
    HealthText->SetText(FText::AsNumber(Data.NewValue));
}

void UPOEAttributesWidget::OnMaxHealthChanged(const FOnAttributeChangeData& Data)
{
    MaxHealthText->SetText(FText::AsNumber(Data.NewValue));
}

void UPOEAttributesWidget::OnManaChanged(const FOnAttributeChangeData& Data)
{
    ManaText->SetText(FText::AsNumber(Data.NewValue));
}

void UPOEAttributesWidget::OnMaxManaChanged(const FOnAttributeChangeData& Data)
{
    MaxManaText->SetText(FText::AsNumber(Data.NewValue));
}

void UPOEAttributesWidget::OnAttackSpeedChanged(const FOnAttributeChangeData& Data)
{
    AttackSpeedText->SetText(FText::AsNumber(Data.NewValue));
}
