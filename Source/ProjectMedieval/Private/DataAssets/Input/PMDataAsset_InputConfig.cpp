// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/Input/PMDataAsset_InputConfig.h"

UInputAction* UPMDataAsset_InputConfig::FindNativeInputActionByTag(const FGameplayTag& InputTag) const
{
	for (const FPMInputActionConfig& InputActionConfig : NativeInputActions)
	{
		if (InputActionConfig.InputTag == InputTag && InputActionConfig.InputAction)
		{
			return InputActionConfig.InputAction;
		}
	}
	return nullptr;
}
