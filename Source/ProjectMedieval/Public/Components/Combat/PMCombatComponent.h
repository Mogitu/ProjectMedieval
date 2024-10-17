// Project Medieval notice.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/PMGameplayAbility.h"
#include "Components/ActorComponent.h"
#include "PMCombatComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTMEDIEVAL_API UPMCombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPMCombatComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	//These 2 functions will initiate a primary or secondary attack. Going to be used in line with GAS system
	void InitiatePrimaryAttack();

	void InitiateSecondaryAttack();

private:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UPMGameplayAbility> PrimaryAbility;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UPMGameplayAbility> SecondaryAbility;

	//Make 2 ability vars here for primary and secondary attacks with uproperty editdefaults.
	

		
};
