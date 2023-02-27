// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoveableObjects.generated.h"

UCLASS()
class WAREHOUSE_API AMoveableObjects : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMoveableObjects();

public:
	// How far should drawer move
	UPROPERTY(EditAnywhere)
	FVector MoveOffset = FVector();

	// How far should drawer rotate
	UPROPERTY(EditAnywhere)
	FRotator RotateOffset = FRotator(0.f, 90.f, 0.f);

	// How long should drawer move
	UPROPERTY(EditAnywhere)
	float MoveTime = 2.f;

	// Should drawer move
	UPROPERTY(EditAnywhere)
	bool ShouldMove = false;

	// Starting position of the Wardrobe
	FVector OriginalLocation;

	// Starting rotation of the Wardrobe
	FRotator OriginalRotation;
};
