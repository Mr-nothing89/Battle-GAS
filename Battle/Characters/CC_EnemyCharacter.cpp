﻿// Lucio  (:  :(


#include "CC_EnemyCharacter.h"

#include "Battle/AbilitySystem/CC_AbilitySystemComponent.h"
#include "Battle/AbilitySystem/CC_AttributeSet.h"


// Sets default values
ACC_EnemyCharacter::ACC_EnemyCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	AbilitySystemComponent = CreateDefaultSubobject<UCC_AbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UCC_AttributeSet>("AttributeSet");
}

UAbilitySystemComponent* ACC_EnemyCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* ACC_EnemyCharacter::GetAttributeSet() const
{
	return AttributeSet;
}

void ACC_EnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (!IsValid(GetAbilitySystemComponent()))
	{
		return;
	}
	GetAbilitySystemComponent()->InitAbilityActorInfo(this,this);
	OnASCInitialized.Broadcast(GetAbilitySystemComponent(),GetAttributeSet());

	if (HasAuthority())
	{
		GiveStartupAbilities();
		InitializeAttributes();
	}
}

