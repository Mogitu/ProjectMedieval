// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/PMCharacterBase.h"
#include "AbilitySystem/PMAbilitySystemComponent.h"
#include "AbilitySystem/PMAttributeSet.h"
#include "Components/Combat/PMCombatComponent.h"

// Sets default values
APMCharacterBase::APMCharacterBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	AbilitySystemComponent = CreateDefaultSubobject<UPMAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemAttributes = CreateDefaultSubobject<UPMAttributeSet>(TEXT("AbilitySystemAttributes"));
	CombatComponent = CreateDefaultSubobject<UPMCombatComponent>(TEXT("CombatComponent"));
}

void APMCharacterBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
	}
}
