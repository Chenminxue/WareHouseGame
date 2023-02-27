#pragma once

#include "CoreMinimal.h"

/*
 *  This function is resuable for AMoveableObjects class. Check the following variables in AMoveableObjects class:
 *  1. FRotator MoveOffset (UPROPERTY)
 *  2. float MoveTime   (UPROPERTY)
 *  3. bool ShouldMove  (UPROPERTY)
 *  4. FRotator OriginalLocation (Regular)
 */
UFUNCTION(BlueprintCallable)
void Rotate(UStaticMeshComponent* USMComp, FRotator RotateOffset, float MoveTime, bool ShouldMove, FRotator OriginalRotation, float DeltaTime);