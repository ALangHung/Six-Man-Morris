// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "ConstValueAndStruck.h"
#include "CheckerPoint.generated.h"

UCLASS()
class SIXMANMORRIS_API ACheckerPoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACheckerPoint();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

    UFUNCTION(BlueprintCallable, Category = ChessPiece)
    EWhereAmI GetSideLocation() { return SideLocation; };

    UFUNCTION(BlueprintCallable, Category = ChessPiece)
    EWhosRound GetCamp() const;

    UFUNCTION(BlueprintCallable, Category = ChessPiece)
    void SetChessPiece(class AChessPiece* const NewChessPiece);

private:

    UPROPERTY(EditAnywhere, Category = "BaseInfo")
    EWhereAmI SideLocation;

    UPROPERTY(EditAnywhere, Category = "Neighbor CheckerPoint")
    ACheckerPoint* Top;

    UPROPERTY(EditAnywhere, Category = "Neighbor CheckerPoint")
    ACheckerPoint* Down;
    
    UPROPERTY(EditAnywhere, Category = "Neighbor CheckerPoint")
    ACheckerPoint* Left;
    
    UPROPERTY(EditAnywhere, Category = "Neighbor CheckerPoint")
    ACheckerPoint* Right;

    UFUNCTION()
    void OnClick(ETouchIndex::Type FingerIndex, AActor* TouchedActor);

    class AChessPiece* ChessPiece;
};
