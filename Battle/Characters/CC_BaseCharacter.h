﻿// Lucio  (:  :(

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "CC_BaseCharacter.generated.h"

class UAttributeSet;
class UGameplayEffect;
class UGameplayAbility;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FASCInitialized,UAbilitySystemComponent*,ASC,UAttributeSet*,AS);

UCLASS(Abstract)
class BATTLE_API ACC_BaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	
	ACC_BaseCharacter();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	FORCEINLINE virtual UAttributeSet* GetAttributeSet() const {return nullptr;}

	UPROPERTY(BlueprintAssignable)
	FASCInitialized OnASCInitialized;

protected:

	void GiveStartupAbilities();

	void InitializeAttributes() const;

private:

	UPROPERTY(EditDefaultsOnly,Category="Crash|Abilities")
	TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;

	UPROPERTY(EditDefaultsOnly,Category="Crash|Abilities")
	TSubclassOf<UGameplayEffect> InitilizeAttributesEffect;
	
	
};
