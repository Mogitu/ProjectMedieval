// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "NativeGameplayTags.h"

namespace PMGameplayTags
{
	//input tags for player movement/orientation
	PROJECTMEDIEVAL_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Move)
	PROJECTMEDIEVAL_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Look)
	PROJECTMEDIEVAL_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Jump)

	//input tags for primary and secondary firing of weapons
	PROJECTMEDIEVAL_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_PrimaryFire)
	PROJECTMEDIEVAL_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_SecondaryFire)

	//tags for the (player) weapons
	PROJECTMEDIEVAL_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Weapon_Sword)
}
