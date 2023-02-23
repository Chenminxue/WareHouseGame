#pragma once

#include "CoreMinimal.h"

/*
 *  This function is resuable for AMoveableObjects class. Check the following variables in AMoveableObjects class:
 *  1. FVector MoveOffset (UPROPERTY)
 *  2. float MoveTime   (UPROPERTY)
 *  3. bool ShouldMove  (UPROPERTY)
 *  4. FVector OriginalLocation (Regular)
 */

void Move(UStaticMeshComponent* USMComp, FVector MoveOffset, float MoveTime, bool ShouldMove, FVector OriginalLocation, float DeltaTime);