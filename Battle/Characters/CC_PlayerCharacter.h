﻿// Lucio  (:  :(

#pragma once

#include "CoreMinimal.h"
#include "CC_BaseCharacter.h"
#include "CC_PlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class BATTLE_API ACC_PlayerCharacter : public ACC_BaseCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACC_PlayerCharacter();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

private:

	UPROPERTY(VisibleAnywhere,Category="Camera")
	TObjectPtr<USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere,Category="Camera")
	TObjectPtr<UCameraComponent> FollowCamera;
};
