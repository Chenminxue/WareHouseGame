// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "MoveableObjects.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"


// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	UPhysicsHandleComponent* PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
}

void UGrabber::ActivateObject()
{
	// Start and end position for sweeping
	FVector Start = GetComponentLocation();
	FVector End = Start + GetForwardVector() * MaxGrabDistance;

	FCollisionShape Sphere = FCollisionShape::MakeSphere(GrabRadius);
	FHitResult HitResult;
	bool HasHit = GetWorld()->SweepSingleByChannel(
		HitResult, 
		Start, 
		End, 
		FQuat::Identity, 
		ECC_GameTraceChannel2,
		Sphere);

		if(HasHit){
			AActor* HitActor = HitResult.GetActor();
			Cast<AMoveableObjects>(HitActor)->ShouldMove = true;
			UE_LOG(LogTemp, Warning, TEXT("Hit actor: %s"), *HitActor->GetActorNameOrLabel());
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("No actor!"));
		}
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}