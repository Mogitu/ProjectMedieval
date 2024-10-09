// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/PMAbilitySystemComponent.h"
#include "GameFramework/Character.h"
#include "PMCharacterBase.generated.h"

class UPMAttributeSet;
class UPMAbilitySystemComponent;

UCLASS()
class PROJECTMEDIEVAL_API APMCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	APMCharacterBase();

	FORCEINLINE UPMAbilitySystemComponent* GetAbilitySystemComponent() const { return AbilitySystemComponent; }
	FORCEINLINE UPMAttributeSet* GetAttributeSet() const { return AbilitySystemAttributes; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AbilitySystem")
	TObjectPtr<UPMAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AbilitySystem")
	TObjectPtr<UPMAttributeSet> AbilitySystemAttributes;

	virtual void PossessedBy(AController* NewController) override;
};
