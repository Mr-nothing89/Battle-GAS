// Lucio  (:  :(

#pragma once

#include "CoreMinimal.h"
#include "Battle/AbilitySystem/Abilities/CC_GameplayAbility.h"
#include "CC_Primary.generated.h"

/**
 * 
 */
UCLASS()
class BATTLE_API UCC_Primary : public UCC_GameplayAbility
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable,Category="Crash|Abilities")
	void HitBoxOverlapTest();

private:

	UPROPERTY(EditDefaultsOnly,Category="Crash|Abilities")
	float HitBoxRadius = 100.f;

	UPROPERTY(EditDefaultsOnly,Category="Crash|Abilities")
	float HitBoxForwardOffset = 200.f;

	UPROPERTY(EditDefaultsOnly,Category="Crash|Abilities")
	float HitBoxElevationOffset = 20.f;
	
};
