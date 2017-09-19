// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "ConstValueAndStruck.h"
#include "ChessPiece.generated.h"

UCLASS()
class SIXMANMORRIS_API AChessPiece : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChessPiece();
    void GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

    UFUNCTION(BlueprintCallable, Category = ChessPiece)
    bool SetLocatilyPoint(class ACheckerPoint* const new_point);
    
    UFUNCTION(BlueprintCallable, Category = ChessPiece)
    void SetNextLocation(const FVector& new_location);

    UFUNCTION(BlueprintCallable, Category = ChessPiece)
    EWhosRound GetCamp() { return Camp; };

private:
    
    UPROPERTY(VisibleAnywhere, Category=Render)
    class UStaticMeshComponent* Mesh;
	
    UPROPERTY(VisibleAnywhere, Category = Render)
    class UProjectileMovementComponent* ProjectileMovement;

    class ACheckerPoint* LocatilyPoint;

    UPROPERTY(ReplicatedUsing = OnRep_NextLocation)
    FVector_NetQuantize NextLocation;

    UPROPERTY(EditAnywhere, Category = "Camp")
    EWhosRound Camp;

    FVector Direction;

    UFUNCTION()
    void OnRep_NextLocation();

};
