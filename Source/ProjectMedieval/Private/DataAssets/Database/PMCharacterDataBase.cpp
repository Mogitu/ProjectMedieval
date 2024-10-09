// Project Medieval notice.

#include "DataAssets/Database/PMCharacterDataBase.h"
#include "AbilitySystem/PMAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/PMGameplayAbility.h"

void UPMCharacterDataBase::GiveToAbilitySystemComponent(UPMAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	check(InASCToGive);
	GrantAbilities(ActivateOnGiveAbilities, InASCToGive, ApplyLevel);
	GrantAbilities(ReactiveAbilities, InASCToGive, ApplyLevel);
}

void UPMCharacterDataBase::GrantAbilities(const TArray<TSubclassOf<UPMGameplayAbility>>& InAbilitiesToGive, UPMAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	if (InAbilitiesToGive.IsEmpty())
	{
		return;
	}

	for (const auto& Ability : InAbilitiesToGive)
	{
		if (!Ability)
		{
			continue;
		}
		FGameplayAbilitySpec AbilitySpec(Ability);
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		InASCToGive->GiveAbility(AbilitySpec);
	}
}
