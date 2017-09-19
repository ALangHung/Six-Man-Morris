// Fill out your copyright notice in the Description page of Project Settings.

#include "SixManMorris.h"
#include "CheckerboardManager.h"

#include "CheckerPoint.h"
#include "ChessPiece.h"


bool ACheckerboardManager::CheckCanMoveTo(const ACheckerPoint* const Goal)
{
    //Goal->

    return true;
}

bool ACheckerboardManager::CheckCanMoveTo(const ACheckerPoint* const A, const ACheckerPoint* const B)
{


    return true;
}

bool ACheckerboardManager::MoveChessPiece(AChessPiece* const A, ACheckerPoint* const Goal)
{
    if (Goal->GetCamp() == EWhosRound::None)
    {
        A->SetLocatilyPoint(Goal);
        Goal->SetChessPiece(A);
        return true;
    }

    return false;
}