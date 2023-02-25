// Fill out your copyright notice in the Description page of Project Settings.


#include "Wardrobe_2.h"
#include "Mover.h"

// Sets default values
AWardrobe_2::AWardrobe_2()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Structure of the wardrobe
	WardrobeBase = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Wardrobe Base"));
	RootComponent = WardrobeBase;

	// Drawer_1 = 	CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Drawer 1"));
	// Drawer_1->SetupAttachment(WardrobeBase);

	// Drawer_2 = 	CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Drawer 2"));
	// Drawer_2->SetupAttachment(WardrobeBase);
}

// Called when the game starts or when spawned
void AWardrobe_2::BeginPlay()
{
    Super::BeginPlay();
	
	OriginalLocation = WardrobeBase->GetComponentLocation();
}

// Called every frame
void AWardrobe_2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Move(WardrobeBase, MoveOffset, MoveTime, ShouldMove, OriginalLocation, DeltaTime);
}
