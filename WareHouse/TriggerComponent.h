// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "TriggerComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class WAREHOUSE_API UTriggerComponent : public UBoxComponent
{
	GENERATED_BODY()

public:
	UTriggerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	// Interface for receiving the tag from the object
	UPROPERTY(EditAnywhere)
	FName AcceptableActorTag;

	// Check which object is acceptable for the trigger
	AActor* GetAcceptableActor() const;

	class AWardrobe_1* Wardrobe_1;



public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	
	static bool IsWardrobeTriggered;

};

bool UTriggerComponent::IsWardrobeTriggered = false;