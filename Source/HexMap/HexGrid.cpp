// Fill out your copyright notice in the Description page of Project Settings.

#include "HexGrid.h"

// Sets default values
AHexGrid::AHexGrid()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHexGrid::BeginPlay()
{
	Super::BeginPlay();

	HexGrid.SetNumZeroed(Width);

	for (int32 col = 0; col < Width; col++)
	{
		HexGrid[col].SetNumZeroed(Height);
	}

	for (int32 y = 0; y < Height; y++)
	{
		for (int32 x = 0; x < Width; x++)
		{
			const float outerRadius = TileSize;
			const float innerRadius = sqrt(3) * TileSize;
			const bool oddRow = y % 2 == 1;

			const float xPos = x * innerRadius + (oddRow ? innerRadius / 2 : 0);
			const float yPos = y * (outerRadius * 2) * 3 / 4;

			TSubclassOf<AHexTile> tileToSpawn = GrassHexTile;
			int32 seed = FMath::RandRange(0, 2);
			FVector scale = FVector(1, 1, seed + 1);

			AHexTile* newTile = GetWorld()->SpawnActor<AHexTile>(tileToSpawn, FVector(xPos, yPos, seed * 10), FRotator::ZeroRotator);
			newTile->SetActorScale3D(scale);
			HexGrid[x][y] = newTile;
		}
	}
}

