// Project Medieval notice.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PMTypes/PMStructTypes.h"
#include "PMWeaponBase.generated.h"

class UBoxComponent;

UCLASS()
class PROJECTMEDIEVAL_API APMWeaponBase : public AActor
{
	GENERATED_BODY()

public:
	APMWeaponBase();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WeaponData")
	FPMWeaponData WeaponData;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Weapons")
	TObjectPtr<UStaticMeshComponent> WeaponMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Weapons")
	TObjectPtr<UBoxComponent> WeaponCollisionBox;

public:
	FORCEINLINE UBoxComponent* GetWeaponCollisionBox() const { return WeaponCollisionBox.Get(); }
};
