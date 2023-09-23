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

	// The array index
	int index = 0;
	// Number of tiles extending out from the center
	const int N = NSize;
	// Formula to calculate number of tiles based on input
	int size = (3 * FMath::Square(N + 1)) - (3 * N + 1) + 1;

	HexTiles.SetNumZeroed(size);

	const float noiseScale = 0.05f;

	for (int q = -N; q <= N; q++) {
		const int r1 = FMath::Max(-N, -q - N);
		const int r2 = FMath::Min(N, -q + N);

		for (int r = r1; r <= r2; r++) {
			const FVector location = FVector(r * noiseScale + 0.01, q * noiseScale + 0.01, r2 * noiseScale + 0.01);
			const float zSample = FMath::Abs(FMath::PerlinNoise3D(location));
			const float height = zSample <= 0 ? 0.f : FGenericPlatformMath::RoundToInt(zSample * 10); // Multiply by 10 to convert to cm

			/*UE_LOG(
				LogTemp,
				Warning,
				TEXT("FVector = %s"),
				*location.ToString()
			);*/

			UE_LOG(
				LogTemp,
				Warning,
				TEXT("zSample = %f, Height = %f"),
				zSample,
				height
			);

			TSubclassOf<AHexTile> tileToSpawn = height > 0 ? GroundHexTile : WaterHexTile;

			FVector coordinates = GetCoordinates(r, q, height + 1);
			AHexTile* newTile = GetWorld()->SpawnActor<AHexTile>(tileToSpawn, coordinates, FRotator::ZeroRotator);
			newTile->SetActorScale3D(FVector(1, 1, height + 1));
			newTile->SetCubeCoordinates(r, q);
			newTile->SetFolderPath(TEXT("HexGrid"));
			HexTiles[index++] = newTile;
		}
	}
}

FVector AHexGrid::GetCoordinates(int r, int q, int height) {
	// Height / 2
	const float outerRadius = HexTileDiameter / 2;
	const float innerRadius = (sqrt(3) * HexTileDiameter) / 2;
	const float offset = (innerRadius / 2);
	const float column = (q * innerRadius) + (r * offset);
	const float row = r * (outerRadius * 3 / 2);

	return FVector(column, row, height * (outerRadius * 0.1));
}

