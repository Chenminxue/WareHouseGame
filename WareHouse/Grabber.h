// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Components/InputComponent.h"
#include "Grabber.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WAREHOUSE_API UGrabber : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

	// Activate the object
	UFUNCTION(BlueprintCallable)
	void ActivateObject();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	// Grab Distance
	UPROPERTY(EditAnywhere)
	float MaxGrabDistance = 400;

	// Grab Radius
	UPROPERTY(EditAnywhere)
	float GrabRadius = 100.f;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
