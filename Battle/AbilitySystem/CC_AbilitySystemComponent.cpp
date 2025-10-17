// Lucio  (:  :(


#include "CC_AbilitySystemComponent.h"


UCC_AbilitySystemComponent::UCC_AbilitySystemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	
}


void UCC_AbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();

	
	
}


void UCC_AbilitySystemComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                               FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	
}

