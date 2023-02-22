// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WardrobeSet_01.generated.h"

UCLASS()
class WAREHOUSE_API AWardrobeSet_01 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWardrobeSet_01();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Move(float DeltaTime);

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

	// How far should drawer move
	UPROPERTY(EditAnywhere)
	FVector MoveOffset;

	// How long should drawer move
	UPROPERTY(EditAnywhere)
	float MoveTime = 2.f;

	// Should drawer move
	UPROPERTY(EditAnywhere)
	bool ShouldMove = false;

	// Starting position of the Wardrobe
	FVector OriginalLocation;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
