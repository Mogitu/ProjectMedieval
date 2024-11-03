// Project Medieval notice.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "PMTypes/PMStructTypes.h"
#include "PMAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTMEDIEVAL_API UPMAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	void OnAbilityInputPressed(const FGameplayTag& InInputTag);
	void OnAbilityInputReleased(const FGameplayTag& InInputTag);

	UFUNCTION(BlueprintCallable, Category="Ability", meta=(ApplyLevel = "1"))
	void GrantCharacterWeaponAbilities(const TArray<FPMAbilitySet>& InDefaultAbilities, int32 ApplyLevel, TArray<FGameplayAbilitySpecHandle>& OutGrantedSpecHandles);
};
