﻿// Lucio  (:  :(

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "CC_BaseCharacter.generated.h"

class UGameplayEffect;
class UGameplayAbility;

UCLASS(Abstract)
class BATTLE_API ACC_BaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	
	ACC_BaseCharacter();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:

	void GiveStartupAbilities();

	void InitializeAttributes() const;

private:

	UPROPERTY(EditDefaultsOnly,Category="Crash|Abilities")
	TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;

	UPROPERTY(EditDefaultsOnly,Category="Crash|Abilities")
	TSubclassOf<UGameplayEffect> InitilizeAttributesEffect;
	
	
};
