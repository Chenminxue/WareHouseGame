// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MoveableObjects.h"
#include "Wardrobe_1.generated.h"

/**
 * 
 */
UCLASS()
class WAREHOUSE_API AWardrobe_1 : public AMoveableObjects
{
	GENERATED_BODY()

public:
	AWardrobe_1();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	// Component of the wardrobe
	UPROPERTY(EditAnywhere, Category="Component")
	UStaticMeshComponent* WardrobeBase;

	// Component of the wardrobe
	UPROPERTY(EditAnywhere, Category="Component")
	UStaticMeshComponent* Drawer_1;

	// Component of the wardrobe
	UPROPERTY(EditAnywhere, Category="Component")
	UStaticMeshComponent* Drawer_2;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
