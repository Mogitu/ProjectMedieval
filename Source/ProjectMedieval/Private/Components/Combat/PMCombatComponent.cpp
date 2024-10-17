// Project Medieval notice.


#include "Components/Combat/PMCombatComponent.h"

// Sets default values for this component's properties
UPMCombatComponent::UPMCombatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPMCombatComponent::BeginPlay()
{
	Super::BeginPlay();

	AbilitySystemComponent = GetOwner()->FindComponentByClass<UPMAbilitySystemComponent>();
	// ...
	
}


// Called every frame
void UPMCombatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPMCombatComponent::InitiatePrimaryAttack()
{
	FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(PrimaryAbility);
	AbilitySystemComponent->GiveAbilityAndActivateOnce(AbilitySpec);
	//TODO: This is going to call the primary attack based on which ability is the primary attack.
}

void UPMCombatComponent::InitiateSecondaryAttack()
{
	FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(SecondaryAbility);
	AbilitySystemComponent->GiveAbilityAndActivateOnce(AbilitySpec);
	//TODO: Same as first but with secondary.
}

