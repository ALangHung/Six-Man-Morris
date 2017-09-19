// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "CheckerboardManager.generated.h"

/**
 * 
 */
UCLASS()
class SIXMANMORRIS_API ACheckerboardManager : public AActor
{
    GENERATED_BODY()

public:

    UPROPERTY()
    TArray<class ACheckerPoint*> CheckerboardArea;
	
    UPROPERTY()
    TArray<class ACheckerPoint*> PrepareArea;
    
    static bool CheckCanMoveTo(const class ACheckerPoint* const Goal);
    static bool CheckCanMoveTo(const class ACheckerPoint* const A, const class ACheckerPoint* const B);

    /** just move, don't care to much. **/
    bool MoveChessPiece(class AChessPiece* const A, class ACheckerPoint* const Goal);

};
