// Project Medieval notice.

#include "Components/Combat/PMCombatComponent.h"
#include "Items/Weapons/PMWeaponBase.h"

void UPMCombatComponent::RegisterWeapon(FGameplayTag InWeaponTagToRegister, APMWeaponBase* InWeaponToRegister, bool bRegisterAsEquipedWeapon)
{
	checkf(!CarriedWeaponsMap.Contains(InWeaponTagToRegister), TEXT("A weapon named %s has already been added as a carried weapon"), *InWeaponTagToRegister.ToString());
	check(InWeaponToRegister);

	CarriedWeaponsMap.Emplace(InWeaponTagToRegister, InWeaponToRegister);
	if (bRegisterAsEquipedWeapon)
	{
		CurrentEquippedWeaponTag = InWeaponTagToRegister;
	}
	//const FString WeaponString = FString::Printf(TEXT("A weapon name: %s has been registered using the tag %s"), *InWeaponToRegister->GetName(), *InWeaponTagToRegister.ToString());
}

APMWeaponBase* UPMCombatComponent::GetCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const
{
	if (CarriedWeaponsMap.Contains(InWeaponTagToGet))
	{
		if (auto FoundWeapon = CarriedWeaponsMap.Find(InWeaponTagToGet))
		{
			return FoundWeapon->Get();
		}
	}
	return nullptr;
}

APMWeaponBase* UPMCombatComponent::GetCurrentEquipedWeapon() const
{
	if (!CurrentEquippedWeaponTag.IsValid())
	{
		return nullptr;
	}
	return GetCarriedWeaponByTag(CurrentEquippedWeaponTag);
}
