// Fill out your copyright notice in the Description page of Project Settings.


#include "FrontWallWithFrontDoor.h"
#include "Rotate.h"

// Sets default values
AFrontWallWithFrontDoor::AFrontWallWithFrontDoor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Structure of the wardrobe
	FrontWall = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Front Wall"));
	RootComponent = FrontWall;

	FrontDoor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Front Door"));
	FrontDoor->SetupAttachment(FrontWall);
}

// Called when the game starts or when spawned
void AFrontWallWithFrontDoor::BeginPlay()
{
    Super::BeginPlay();
	
	OriginalRotation = FrontDoor->GetComponentRotation();
}

// Called every frame
void AFrontWallWithFrontDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Rotate(FrontDoor, RotateOffset, MoveTime, ShouldMove, OriginalRotation, DeltaTime);
}


