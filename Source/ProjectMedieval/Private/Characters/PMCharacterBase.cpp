// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/PMCharacterBase.h"

// Sets default values
APMCharacterBase::APMCharacterBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;
}

void APMCharacterBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
}
