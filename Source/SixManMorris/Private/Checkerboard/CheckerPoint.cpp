// Fill out your copyright notice in the Description page of Project Settings.

#include "SixManMorris.h"
#include "CheckerPoint.h"

#include "ChessPiece.h"

// Sets default values
ACheckerPoint::ACheckerPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
    bReplicates = true;

    if (GIsClient)
    {
        OnInputTouchBegin.AddDynamic(this, &ACheckerPoint::OnClick);
    }

}

// Called when the game starts or when spawned
void ACheckerPoint::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACheckerPoint::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

EWhosRound ACheckerPoint::GetCamp() const
{
    if (!IsValid(ChessPiece))
        return EWhosRound::None;

    return ChessPiece->GetCamp();
}

void ACheckerPoint::SetChessPiece(AChessPiece* const NewChessPiece)
{
    ChessPiece = NewChessPiece;
}


void ACheckerPoint::OnClick(ETouchIndex::Type FingerIndex, AActor* TouchedActor)
{

}