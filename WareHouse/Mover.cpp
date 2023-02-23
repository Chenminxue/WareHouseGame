#include "Mover.h"
#include "Math/UnrealMathUtility.h"

void Move(UStaticMeshComponent *USMComp, FVector MoveOffset, float MoveTime, bool ShouldMove, FVector OriginalLocation, float DeltaTime)
{
    if(ShouldMove)
	{
		FVector CurrentLocation = USMComp->GetComponentLocation();
		FVector TargetLocation = OriginalLocation + MoveOffset;
		// Moving Speed
		float Speed = FVector::Distance(OriginalLocation, TargetLocation) / MoveTime;

		// Move to the new location 
		FVector NewLocation = FMath::VInterpConstantTo(CurrentLocation, TargetLocation, DeltaTime, Speed);
		USMComp->SetWorldLocation(NewLocation);
	}
}
