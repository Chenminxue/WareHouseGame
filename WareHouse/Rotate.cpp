#include "Mover.h"
#include "Math/UnrealMathUtility.h"

void Rotate(UStaticMeshComponent *USMComp, FRotator RotateOffset, float MoveTime, bool ShouldMove, FRotator OriginalRotation, float DeltaTime)
{
    if(ShouldMove)
	{
        UE_LOG(LogTemp, Warning, TEXT("Rotating!"));
		FRotator CurrentRotation = USMComp->GetComponentRotation();
		FRotator TargetRotation = OriginalRotation + RotateOffset;

		float CosAngle = FMath::Clamp(FVector::DotProduct(CurrentRotation.Vector(), TargetRotation.Vector()), -1.0f, 1.0f);
		float Angle = FMath::Acos(CosAngle);
		float RotationDistance = FMath::RadiansToDegrees(Angle);

		// Calculate the rotation speed for the door, based on the rotation distance and desired rotation time
		float Speed = RotationDistance / MoveTime;
        // UE_LOG(LogTemp, Warning, TEXT("Speed: %f"), Speed);

        // // Calculate the distance between the start and end rotations
        // float Distance = FMath::RadiansToDegrees(FMath::Abs(CurrentRotation.Yaw - TargetRotation.Yaw));
        // UE_LOG(LogTemp, Warning, TEXT("Distance: %f"), Distance);


        // // Calculate the fraction of the interpolation based on the distance and the interpolation speed
        // float Fraction = FMath::Clamp(Speed * DeltaTime / Distance, 0.0f, 1.0f);
        // UE_LOG(LogTemp, Warning, TEXT("Fraction: %f"), Fraction);



		// Move to the new Rotation 
        FRotator NewRotation = FMath::RInterpTo(CurrentRotation, TargetRotation, DeltaTime, Speed);
		USMComp->SetWorldRotation(NewRotation);
	}
	else{

		// FRotator TargetRotation = OriginalRotation;

		// FRotator CurrentRotation = USMComp->GetComponentRotation();
		// float Speed = RotateOffset.Length() / MoveTime;

        // float Distance = (TargetRotation - CurrentRotation).Size();
        // float Fraction = FMath::Clamp(Speed * DeltaTime / Distance, 0.0f, 1.0f);
		// FRotator NewRotation = FMath::Lerp(CurrentRotation, TargetRotation, Fraction);
		// USMComp->SetWorldRotation(NewRotation);
	}
}
