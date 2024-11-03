// Project Medieval notice.


#include "AbilitySystem/PMAbilitySystemComponent.h"

void UPMAbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag& InInputTag)
{
	if (!InInputTag.IsValid())
	{
		return;
	}
	for (const auto& AbilitySpec : GetActivatableAbilities())
	{
		if (!AbilitySpec.DynamicAbilityTags.HasTagExact(InInputTag))
		{
			continue;
		}
		TryActivateAbility(AbilitySpec.Handle);
	}
}

void UPMAbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag& InInputTag)
{
}

void UPMAbilitySystemComponent::GrantCharacterWeaponAbilities(const TArray<FPMAbilitySet>& InDefaultAbilities, int32 ApplyLevel, TArray<FGameplayAbilitySpecHandle>& OutGrantedSpecHandles)
{
	if (InDefaultAbilities.IsEmpty())
	{
		return;
	}

	for (const auto& AbilitySet : InDefaultAbilities)
	{
		if (!AbilitySet.IsValid())
		{
			continue;
		}
		FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
		AbilitySpec.SourceObject = GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.DynamicAbilityTags.AddTag(AbilitySet.InputTag);
		OutGrantedSpecHandles.AddUnique(GiveAbility(AbilitySpec));
	}
}
