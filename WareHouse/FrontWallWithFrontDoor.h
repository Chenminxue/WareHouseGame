// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MoveableObjects.h"
#include "FrontWallWithFrontDoor.generated.h"

/**
 * 
 */
UCLASS()
class WAREHOUSE_API AFrontWallWithFrontDoor : public AMoveableObjects
{
	GENERATED_BODY()

public:
	AFrontWallWithFrontDoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	// Component of the wardrobe
	UPROPERTY(EditAnywhere, Category="Component")
	UStaticMeshComponent* FrontWall;

	// Component of the wardrobe
	UPROPERTY(EditAnywhere, Category="Component")
	UStaticMeshComponent* FrontDoor;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
