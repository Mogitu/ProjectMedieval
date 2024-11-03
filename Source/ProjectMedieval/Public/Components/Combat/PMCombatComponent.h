// Project Medieval notice.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/PMGameplayAbility.h"
#include "AbilitySystem/PMAbilitySystemComponent.h"
#include "Components/ActorComponent.h"
#include "PMCombatComponent.generated.h"


class APMWeaponBase;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PROJECTMEDIEVAL_API UPMCombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Combat")
	void RegisterWeapon(FGameplayTag InWeaponTagToRegister, APMWeaponBase* InWeaponToRegister, bool bRegisterAsEquipedWeapon = false);

	UFUNCTION(BlueprintCallable, Category="Combat")
	APMWeaponBase* GetCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const;

	UPROPERTY(BlueprintReadWrite, Category="Combat")
	FGameplayTag CurrentEquippedWeaponTag;

	UFUNCTION(BlueprintCallable, Category="Combat")
	APMWeaponBase* GetCurrentEquipedWeapon() const;

private:
	TMap<FGameplayTag, TObjectPtr<APMWeaponBase>> CarriedWeaponsMap;
};
