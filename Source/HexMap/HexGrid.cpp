// Fill out your copyright notice in the Description page of Project Settings.

#include "HexGrid.h"

// Sets default values
AHexGrid::AHexGrid() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AHexGrid::BeginPlay() {
	Super::BeginPlay();

	//HexGrid.SetNumZeroed(Width);

	// The array index
	int index = 0;
	// Number of tiles extending out from the center
	const int N = NSize;
	// Formula to calculate number of tiles based on input
	int size = (3 * FMath::Square(N + 1)) - (3 * N + 1) + 1;

	HexTiles.SetNumZeroed(size);

	for (int q = -N; q <= N; q++) {
		const int r1 = FMath::Max(-N, -q - N);
		const int r2 = FMath::Min(N, -q + N);

		for (int r = r1; r <= r2; r++) {
			const int height = FMath::RandRange(0, 2);
			TSubclassOf<AHexTile> tileToSpawn = height > 0 ? GrassHexTile : WaterHexTile;

			AHexTile* newTile = GetWorld()->SpawnActor<AHexTile>(tileToSpawn, GetCoordinates(r, q, height), FRotator::ZeroRotator);
			newTile->SetActorScale3D(FVector(1, 1, height + 1));
			newTile->SetCubeCoordinates(r, q);
			HexTiles[index++] = newTile;
		}
	}
}

FVector AHexGrid::GetCoordinates(int r, int q, int height) {
	const float outerRadius = TileSize;
	const float innerRadius = sqrt(3) * TileSize;

	const bool oddRow = FMath::Abs(r) % 2 == 1;

	const float offset = (innerRadius / 2);

	const float column = (q * innerRadius) + (r * offset);
	const float row = r * (outerRadius * 3 / 2);

	return FVector(column, row, height * (TileSize * 0.1));
}

