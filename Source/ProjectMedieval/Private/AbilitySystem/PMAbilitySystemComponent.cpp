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
