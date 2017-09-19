// Fill out your copyright notice in the Description page of Project Settings.

#include "SixManMorris.h"
#include "UnrealNetwork.h"
#include "ChessPiece.h"

#include "CheckerPoint.h"

// Sets default values
AChessPiece::AChessPiece()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
    Mesh = CreateDefaultSubobject<UStaticMeshComponent>("ChessPiece");
    Mesh->SetCollisionProfileName("NoCollision");
    RootComponent = Mesh;

    ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovement");
    if (IsValid(ProjectileMovement))
    {
        ProjectileMovement->ProjectileGravityScale = 0;
        ProjectileMovement->MaxSpeed = 3000;
        ProjectileMovement->bAutoActivate = false;
    }
}

void AChessPiece::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
    DOREPLIFETIME(AChessPiece, NextLocation);
}

// Called when the game starts or when spawned
void AChessPiece::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AChessPiece::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
    if (GetActorLocation().Equals(NextLocation, 10))
    {
        ProjectileMovement->Deactivate();
        SetActorLocation(NextLocation);
    }
}

bool AChessPiece::SetLocatilyPoint(ACheckerPoint* const new_point)
{
    if (!IsValid(new_point))
        return false;

    LocatilyPoint = new_point;
    SetNextLocation(new_point->GetActorLocation());
    return true;
}

void AChessPiece::SetNextLocation(const FVector& new_location)
{
    NextLocation = new_location;
    OnRep_NextLocation();
}

void AChessPiece::OnRep_NextLocation()
{
    ProjectileMovement->Velocity = (NextLocation - GetActorLocation()).GetSafeNormal() * 500;
    ProjectileMovement->Activate();
}