// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Characters/PMCharacterBase.h"
#include "PMPlayerCharacter.generated.h"

struct FInputActionValue;
class UPMDataAsset_InputConfig;
class UCameraComponent;
/**
 * 
 */
UCLASS()
class PROJECTMEDIEVAL_API APMPlayerCharacter : public APMCharacterBase
{
	GENERATED_BODY()

public:
	APMPlayerCharacter();

protected:
	virtual void PossessedBy(AController* NewController) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CharacterData", meta=(AllowPrivateAccess=true))
	TObjectPtr<UPMDataAsset_InputConfig> InputConfigDataAsset;
	void Input_Move(const FInputActionValue& InputActionValue);
	void Input_Look(const FInputActionValue& InputActionValue);

	void Input_AbilityInputPressed(FGameplayTag InInputTag);
	void Input_AbilityInputReleased(FGameplayTag InInputTag);

};
