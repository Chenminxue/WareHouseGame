// Fill out your copyright notice in the Description page of Project Settings.


#include "Wardrobe_1.h"
#include "Mover.h"

// Sets default values
AWardrobe_1::AWardrobe_1()
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
void AWardrobe_1::BeginPlay()
{
    Super::BeginPlay();
	
	OriginalLocation = Drawer_1->GetComponentLocation();
}

// Called every frame
void AWardrobe_1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Move(Drawer_1, MoveOffset, MoveTime, ShouldMove, OriginalLocation, DeltaTime);
}
