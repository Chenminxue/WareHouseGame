// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponent.h"
#include "Wardrobe_1.h"
#include "MoveableObjects.h"

UTriggerComponent::UTriggerComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UTriggerComponent::BeginPlay()
{
    Super::BeginPlay();
}

AActor* UTriggerComponent::GetAcceptableActor() const
{
    TArray<AActor*> Actors;
    GetOverlappingActors(Actors);
    for (AActor* Actor : Actors)
    {
        // UE_LOG(LogTemp, Display, TEXT("Actor: %s"), *Actor->GetName());
        
        bool HasAcceptableTag = Actor->ActorHasTag(AcceptableActorTag);
        bool IsGrabbed = Actor->ActorHasTag("Grabbed");
        if (HasAcceptableTag && ! IsGrabbed)
        {
            return Actor;
        }   
    }
    return nullptr;
}


void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);



    AActor* Actor = GetAcceptableActor();
    if (Actor != nullptr)
    {
        // Attach the grabbed object onto the target object
        UPrimitiveComponent* Component = Cast<UPrimitiveComponent>(Actor->GetRootComponent());
        if (Component != nullptr)
        {
            Component->SetSimulatePhysics(false);
        }
        Actor->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);

        // Put the Grabbed object vertically
        FRotator NewRotation = FRotator(0.f, 0.f, 0.f); // Rotate the object 90 degrees around the X-axis
        Actor->SetActorRotation(NewRotation);

        AActor * TempActor = GetOwner();
        UE_LOG(LogTemp, Display, TEXT("Actor: %s"), *TempActor->GetName());
        Cast<AMoveableObjects>(TempActor)->ShouldMove = true;

        if(TempActor->GetActorNameOrLabel() == "BP_Wardrobe_3")
        {
            IsWardrobeTriggered = true;
        }
        // UE_LOG(LogTemp, Display, TEXT("Unlocking"));
    }
    else
    {
        AActor * TempActor = GetOwner();
        // UE_LOG(LogTemp, Display, TEXT("Actor: %s"), *TempActor->GetName());
        Cast<AMoveableObjects>(TempActor)->ShouldMove = false;
        IsWardrobeTriggered = false;
        // UE_LOG(LogTemp, Display, TEXT("Relocking"));
    }

}
