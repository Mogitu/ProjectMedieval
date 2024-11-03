// Project Medieval notice.


#include "Items/Weapons/PMWeaponBase.h"

#include "Components/BoxComponent.h"

// Sets default values
APMWeaponBase::APMWeaponBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	SetRootComponent(WeaponMesh);

	WeaponCollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("WeaponCollisionBox"));
	WeaponCollisionBox->SetupAttachment(GetRootComponent());
	WeaponCollisionBox->SetBoxExtent(FVector(20.f, 20.f, 20.f));;
	WeaponCollisionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}
