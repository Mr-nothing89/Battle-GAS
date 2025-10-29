﻿// Lucio  (:  :(


#include "CC_PlayerCharacter.h"

#include "AbilitySystemComponent.h"
#include "Battle/Player/CC_PlayerState.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"


// Sets default values
ACC_PlayerCharacter::ACC_PlayerCharacter()
{
	
	PrimaryActorTick.bCanEverTick = false;

	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
	GetCharacterMovement()->JumpZVelocity = 500.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.f;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>("CameraBoom");
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 600.0f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>("FollowCamera");
	FollowCamera->SetupAttachment(CameraBoom,USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;
}

UAbilitySystemComponent* ACC_PlayerCharacter::GetAbilitySystemComponent() const
{
	if (ACC_PlayerState* CCPlayerState = Cast<ACC_PlayerState>(GetPlayerState()))
	{
		return CCPlayerState->GetAbilitySystemComponent();
	}
	return nullptr;
}

UAttributeSet* ACC_PlayerCharacter::GetAttributeSet() const
{
	if (ACC_PlayerState* CCPlayerState = Cast<ACC_PlayerState>(GetPlayerState()))
	{
		return CCPlayerState->GetAttributeSet();
	}
	return nullptr;
}

void ACC_PlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (GetAbilitySystemComponent() && HasAuthority())
	{
		GetAbilitySystemComponent()->InitAbilityActorInfo(GetPlayerState(),this);
		OnASCInitialized.Broadcast(GetAbilitySystemComponent(),GetAttributeSet());
		GiveStartupAbilities();
		InitializeAttributes();
	}
}

void ACC_PlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	if (GetAbilitySystemComponent())
	{
		GetAbilitySystemComponent()->InitAbilityActorInfo(GetPlayerState(),this);
		OnASCInitialized.Broadcast(GetAbilitySystemComponent(),GetAttributeSet());
	}
}

