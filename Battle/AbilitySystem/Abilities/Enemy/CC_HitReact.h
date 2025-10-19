// Lucio  (:  :(

#pragma once

#include "CoreMinimal.h"
#include "Battle/AbilitySystem/Abilities/CC_GameplayAbility.h"
#include "CC_HitReact.generated.h"

/**
 * 
 */
UCLASS()
class BATTLE_API UCC_HitReact : public UCC_GameplayAbility
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable,Category = "Crash|Abilities")
	void CacheHitDirectionVectors(AActor* Instigator);

	UPROPERTY(BlueprintReadOnly,Category="Crash|Abilities")
	FVector AvatarForward;

	UPROPERTY(BlueprintReadOnly,Category="Crash|Abilities")
	FVector ToInstigator;
};
