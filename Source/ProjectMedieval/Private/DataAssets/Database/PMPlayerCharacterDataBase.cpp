// Project Medieval notice.


#include "DataAssets/Database/PMPlayerCharacterDataBase.h"
#include "AbilitySystem/PMAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/PMGameplayAbility.h"

bool FPlayerCharacterAbilitySet::IsValid() const
{
	return InputTag.IsValid() && AbilityToGrant;
}

void UPMPlayerCharacterDataBase::GiveToAbilitySystemComponent(UPMAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InASCToGive, ApplyLevel);
	for (const auto& AbilitySet : PlayerStartUpAbilitySets)
	{
		if (!AbilitySet.IsValid())
		{
			continue;
		}
		FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.DynamicAbilityTags.AddTag(AbilitySet.InputTag);
		InASCToGive->GiveAbility(AbilitySpec);
	}
}
