// Lucio  (:  :(


#include "CC_PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/Character.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "Battle/GameplayTags/CCTags.h"

void ACC_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputLocalPlayerSubsystem* InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>
		(GetLocalPlayer()))
	{
		for (UInputMappingContext* Context : InputMappingContexts)
		{
			InputSubsystem->AddMappingContext(Context,0);
		}

		UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

		EnhancedInputComponent->BindAction(JumpAction,ETriggerEvent::Started,this,&ACC_PlayerController::Jump);
		EnhancedInputComponent->BindAction(JumpAction,ETriggerEvent::Completed,this,&ACC_PlayerController::StopJumping);
		EnhancedInputComponent->BindAction(MoveAction,ETriggerEvent::Triggered,this,&ACC_PlayerController::Move);
		EnhancedInputComponent->BindAction(LookAction,ETriggerEvent::Triggered,this,&ACC_PlayerController::Look);

		EnhancedInputComponent->BindAction(PrimaryAction,ETriggerEvent::Started,this,&ACC_PlayerController::Primary);
	}
}

void ACC_PlayerController::Jump()
{
	if (IsValid(GetCharacter()))
	{
		GetCharacter()->Jump();
	}
	
}

void ACC_PlayerController::StopJumping()
{
	if (IsValid(GetCharacter()))
	{
		GetCharacter()->StopJumping();
	}
}

void ACC_PlayerController::Move(const FInputActionValue& Value)
{
	if (IsValid(GetPawn()))
	{
		const FVector2D InputAxisVector = Value.Get<FVector2D>();

		//Find which way is forward
		const FRotator YawRotation(0.f,GetControlRotation().Yaw,0.f);

		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		GetPawn()->AddMovementInput(ForwardDirection,InputAxisVector.Y);
		GetPawn()->AddMovementInput(RightDirection,InputAxisVector.X);
	}
}

void ACC_PlayerController::Look(const FInputActionValue& Value)
{
	if (IsValid(GetPawn()))
	{
		const FVector2D LookAxisVector = Value.Get<FVector2D>();

		AddYawInput(LookAxisVector.X);
		AddPitchInput(LookAxisVector.Y);
	}
}

void ACC_PlayerController::Primary()
{
	ActivateAbility(CCTags::CCAbilities::Primary);
	//FGameplayTag PrimaryTag = FGameplayTag::RequestGameplayTag("CCTags.CCAbilities.Primary");
}

void ACC_PlayerController::ActivateAbility(const FGameplayTag& AbilityTag) const
{
	if (UAbilitySystemComponent* ASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetPawn()))
	{
		ASC->TryActivateAbilitiesByTag(AbilityTag.GetSingleTagContainer());
	}
	
}
