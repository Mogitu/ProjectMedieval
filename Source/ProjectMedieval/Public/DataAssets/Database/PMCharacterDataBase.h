// Project Medieval notice.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PMCharacterDataBase.generated.h"

class UPMAbilitySystemComponent;
class UPMGameplayAbility;

/**
 * 
 */
UCLASS()
class PROJECTMEDIEVAL_API UPMCharacterDataBase : public UDataAsset
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(UPMAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);

protected:
	UPROPERTY(EditDefaultsOnly, Category="StartupData")
	TArray<TSubclassOf<UPMGameplayAbility>> ActivateOnGiveAbilities;

	UPROPERTY(EditDefaultsOnly, Category="StartupData")
	TArray<TSubclassOf<UPMGameplayAbility>> ReactiveAbilities;

	void GrantAbilities(const TArray<TSubclassOf<UPMGameplayAbility>>& InAbilitiesToGive, UPMAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);
};
