// Fill out your copyright notice in the Description page of Project Settings.

#include "HexGrid.h"

// Sets default values
AHexGrid::AHexGrid()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AHexGrid::BeginPlay()
{
	Super::BeginPlay();

	//HexGrid.SetNumZeroed(Width);

	// The array index
	int index = 0;
	// Number of tiles extending out from the center
	const int N = 5;
	// Formula to calculate number of tiles based on input
	int size = (3 * FMath::Square(N + 1)) - (3 * N + 1) + 1;

	HexTiles.SetNumZeroed(size);

	for (int q = -N; q <= N; q++) {
		const int r1 = FMath::Max(-N, -q - N);
		const int r2 = FMath::Min(N, -q + N);

		for (int r = r1; r <= r2; r++)
		{
			TSubclassOf<AHexTile> tileToSpawn = GrassHexTile;
			FVector scale = FVector(1, 1, FMath::RandRange(1,3));

			AHexTile* newTile = GetWorld()->SpawnActor<AHexTile>(tileToSpawn, GetCoordinates(r, q), FRotator::ZeroRotator);
			newTile->SetActorScale3D(scale);
			newTile->SetCubeCoordinates(r, q);
			HexTiles[index++] = newTile;
		}
	}

	/*for (int32 y = 0; y < Height; y++)
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
			newTile->SetCubeCoordinates(x, y);
			HexGrid[x][y] = newTile;
		}
	}*/
}

FVector AHexGrid::GetCoordinates(int r, int q)
{
	const float outerRadius = TileSize;
	const float innerRadius = sqrt(3) * TileSize;

	const bool oddRow = abs(r) % 2 == 1;

	const float offset = (innerRadius / 2);

	const float column = (q * innerRadius) + (r * offset);
	const float row = r * (outerRadius * 3 / 2);

	return FVector(column, row, FMath::RandRange(0, 2));
}

