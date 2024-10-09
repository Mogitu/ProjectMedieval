// Project Medieval notice.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
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
};
