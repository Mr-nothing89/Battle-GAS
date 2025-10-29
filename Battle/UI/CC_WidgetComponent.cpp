// Lucio  (:  :(


#include "CC_WidgetComponent.h"

#include "Battle/AbilitySystem/CC_AbilitySystemComponent.h"
#include "Battle/AbilitySystem/CC_AttributeSet.h"
#include "Battle/Characters/CC_BaseCharacter.h"


void UCC_WidgetComponent::BeginPlay()
{
	Super::BeginPlay();
	InitAbilitySystemData();
	if (!IsASCInitilized())
	{
		CrashCharacter->OnASCInitialized.AddDynamic(this,&UCC_WidgetComponent::OnASCInitialized);
	}
	
}

void UCC_WidgetComponent::InitAbilitySystemData()
{
	CrashCharacter = Cast<ACC_BaseCharacter>(GetOwner());
	AbilitySystemComponent = Cast<UCC_AbilitySystemComponent>(CrashCharacter->GetAbilitySystemComponent());
	AttributeSet = Cast<UCC_AttributeSet>(CrashCharacter->GetAttributeSet());
}

bool UCC_WidgetComponent::IsASCInitilized() const
{
	return AbilitySystemComponent.IsValid() && AttributeSet.IsValid();
}

void UCC_WidgetComponent::OnASCInitialized(UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	AbilitySystemComponent = Cast<UCC_AbilitySystemComponent>(ASC);
	AttributeSet = Cast<UCC_AttributeSet>(AS);

	// TODO: Check if the Attribute Set Has been initialized with the first GE
	// If not, bind to some delegate that will be broadcast when it is Initialized.
}


