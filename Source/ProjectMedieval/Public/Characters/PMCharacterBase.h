// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PMCharacterBase.generated.h"

UCLASS()
class PROJECTMEDIEVAL_API APMCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	APMCharacterBase();

protected:
	virtual void PossessedBy(AController* NewController) override;
};
