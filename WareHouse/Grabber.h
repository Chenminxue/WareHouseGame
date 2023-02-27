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

	// Release the object
	UFUNCTION(BlueprintCallable)
	void Release();

	// Get PhysicsHandle
	class UPhysicsHandleComponent* GetPhysicsHandle() const;

	// Check whether a object been grabbed or not 
	bool GetGrabbableInReach(FHitResult & OutHitResult) const;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	// Grab Distance
	UPROPERTY(EditAnywhere)
	float MaxGrabDistance = 200.f;

	// Grab Radius
	UPROPERTY(EditAnywhere)
	float GrabRadius = 40.f;

	// Hold Distance
	UPROPERTY(EditAnywhere)
	float HoldDistance = 200.f;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
