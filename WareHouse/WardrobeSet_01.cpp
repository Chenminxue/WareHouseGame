// Fill out your copyright notice in the Description page of Project Settings.


#include "WardrobeSet_01.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
AWardrobeSet_01::AWardrobeSet_01()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Structure of the wardrobe
	WardrobeBase = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Wardrobe Base"));
	RootComponent = WardrobeBase;

	Drawer_1 = 	CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Drawer 1"));
	Drawer_1->SetupAttachment(WardrobeBase);

	Drawer_2 = 	CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Drawer 2"));
	Drawer_2->SetupAttachment(WardrobeBase);
}

// Called when the game starts or when spawned
void AWardrobeSet_01::BeginPlay()
{
	Super::BeginPlay();
	
	OriginalLocation = Drawer_1->GetComponentLocation();
}

void AWardrobeSet_01::Move(float DeltaTime)
{
	if(ShouldMove)
	{
		FVector CurrentLocation = Drawer_1->GetComponentLocation();
		FVector TargetLocation = OriginalLocation + MoveOffset;
		float Speed = FVector::Distance(OriginalLocation, TargetLocation) / MoveTime;

		FVector NewLocation = FMath::VInterpConstantTo(CurrentLocation, TargetLocation, DeltaTime, Speed);
		Drawer_1->SetWorldLocation(NewLocation);
	}
}

// Called every frame
void AWardrobeSet_01::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Move(DeltaTime);
}

