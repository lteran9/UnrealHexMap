// Fill out your copyright notice in the Description page of Project Settings.

#include "HexTile.h"
#include <Components/SceneComponent.h>
#include <Components/StaticMeshComponent.h>

class UStaticMeshComponent;

// Sets default values
AHexTile::AHexTile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TileMesh"));
	Mesh->SetupAttachment(RootComponent);
	Coordinates = FHexCoords(0, 0);
}

// Called every frame
void AHexTile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHexTile::SetCubeCoordinates(int32 row, int32 col)
{
	// Q = Column, R = Row
	Coordinates = FHexCoords(col, row);
}
