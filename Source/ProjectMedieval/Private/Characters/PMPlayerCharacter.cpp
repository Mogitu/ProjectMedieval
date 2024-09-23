// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/PMPlayerCharacter.h"
#include "EnhancedInputSubsystems.h"
#include "Camera/CameraComponent.h"
#include "Components/Input/PMInputComponent.h"
#include "PMGameplayTags.h"
#include "DataAssets/Input/PMDataAsset_InputConfig.h"

APMPlayerCharacter::APMPlayerCharacter()
{
}

void APMPlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
}

void APMPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	checkf(InputConfigDataAsset, TEXT("Forgot to assign valid data asset as input config"))
	ULocalPlayer* LocalPlayer = GetController<APlayerController>()->GetLocalPlayer();
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<
		UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);

	check(Subsystem)
	Subsystem->AddMappingContext(InputConfigDataAsset->DefaultMappingContext, 0);

	UPMInputComponent* PMInputComponent = CastChecked<UPMInputComponent>(PlayerInputComponent);
	PMInputComponent->BindNativeInputAction(InputConfigDataAsset, PMGameplayTags::InputTag_Move, ETriggerEvent::Triggered, this, &ThisClass::Input_Move);
	PMInputComponent->BindNativeInputAction(InputConfigDataAsset, PMGameplayTags::InputTag_Look, ETriggerEvent::Triggered, this, &ThisClass::Input_Look);
}

void APMPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void APMPlayerCharacter::Input_Move(const FInputActionValue& InputActionValue)
{
	const FVector2d InputVector = InputActionValue.Get<FVector2d>();
	const FRotator Rotation = GetControlRotation();

	FRotator YawRotation(0, Rotation.Yaw, 0);
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(Rotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(ForwardDirection, InputVector.Y);
	AddMovementInput(RightDirection, InputVector.X);
}

void APMPlayerCharacter::Input_Look(const FInputActionValue& InputActionValue)
{
	const FVector2d LookAxisVector = InputActionValue.Get<FVector2d>();
	AddControllerYawInput(LookAxisVector.X);
	AddControllerPitchInput(LookAxisVector.Y);
}
