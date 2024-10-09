// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "DataAssets/Input/PMDataAsset_InputConfig.h"
#include "PMInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTMEDIEVAL_API UPMInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	template <class UserObject, typename CallbackFunction>
	void BindNativeInputAction(const UPMDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag,
	                           ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunction Func);
	template <class UserObject, typename CallbackFunction>
	void BindAbilityInputAction(const UPMDataAsset_InputConfig* InInputConfig, UserObject* ContextObject, CallbackFunction InputPressedFunc, CallbackFunction InputReleasedFunc);
};

template <class UserObject, typename CallbackFunction>
void UPMInputComponent::BindNativeInputAction(const UPMDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject,
                                              CallbackFunction Func)
{
	checkf(InInputConfig, TEXT("Input config data asset is null, can not proceed with binding"));
	if (UInputAction* FoundAction = InInputConfig->FindNativeInputActionByTag(InInputTag))
	{
		BindAction(FoundAction, TriggerEvent, ContextObject, Func);
	}
}

template <class UserObject, typename CallbackFunction>
void UPMInputComponent::BindAbilityInputAction(const UPMDataAsset_InputConfig* InInputConfig, UserObject* ContextObject, CallbackFunction InputPressedFunc, CallbackFunction InputReleasedFunc)
{
	checkf(InInputConfig, TEXT("Input config data asset is null, can not proceed with binding"));
	for (const FPMInputActionConfig& AbilityInputActionConfig : InInputConfig->AbilityInputActions)
	{
		if (!AbilityInputActionConfig.IsValid())
		{
			continue;
		}
		BindAction(AbilityInputActionConfig.InputAction, ETriggerEvent::Started, ContextObject, InputPressedFunc, AbilityInputActionConfig.InputTag);
		BindAction(AbilityInputActionConfig.InputAction, ETriggerEvent::Completed, ContextObject, InputReleasedFunc, AbilityInputActionConfig.InputTag);
	}
}
