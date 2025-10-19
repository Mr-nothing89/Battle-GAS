﻿// Lucio  (:  :(


#include "CC_Primary.h"

#include "Engine/OverlapResult.h"

void UCC_Primary::HitBoxOverlapTest()
{
	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(GetAvatarActorFromActorInfo());

	//Ensure that the overlap test ignores the avatar actor
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActors(ActorsToIgnore);

	FCollisionResponseParams ResponseParams;
	ResponseParams.CollisionResponse.SetAllChannels(ECR_Ignore);
	ResponseParams.CollisionResponse.SetResponse(ECC_Pawn,ECR_Block);

	TArray<FOverlapResult> OverlapResults;
	FCollisionShape Shere = FCollisionShape::MakeSphere(HitBoxRadius);
	const FVector Forward = GetAvatarActorFromActorInfo()->GetActorForwardVector() * HitBoxForwardOffset;
	const FVector HitBoxLocation = GetAvatarActorFromActorInfo()->GetActorLocation() + Forward + FVector(
		0.f,0.f,HitBoxElevationOffset);
	
	GetWorld()->OverlapMultiByChannel(OverlapResults,HitBoxLocation,FQuat::Identity,ECC_Visibility,
		Shere,QueryParams,ResponseParams);

	if (bDrawDebugs)
	{
		DrawDebugSphere(GetWorld(),HitBoxLocation,HitBoxRadius,16,FColor::Red,false,3.f);

		for (const FOverlapResult& Result : OverlapResults)
		{
			FVector DebugLocation = Result.GetActor()->GetActorLocation();
			DebugLocation.Z += 100.f;;
			DrawDebugSphere(GetWorld(), DebugLocation,30.f,10,FColor::Green,false,3.f);
		}
	}
}
