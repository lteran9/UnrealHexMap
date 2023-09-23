// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HexTile.h"
#include "HexGrid.generated.h"

class AHexTile;

UCLASS()
class HEXMAP_API AHexGrid : public AActor
{
	GENERATED_BODY()

protected:	
	TArray<AHexTile*> HexTiles;

	/* The number of tiles in the grid: 3N^2-3N+1 */
	UPROPERTY(EditAnywhere, Category = "Grid")
	int32 NSize;
	/* The tile outer radius in centimeters. */
	UPROPERTY(EditAnywhere, Category = "Grid")
	float HexTileDiameter;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Grid|Tiles")
	TSubclassOf<AHexTile> GroundHexTile;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Grid|Tiles")
	TSubclassOf<AHexTile> WaterHexTile;

public:
	// Sets default values for this actor's properties
	AHexGrid();

protected:	
	virtual void BeginPlay() override;

private:
	FVector GetCoordinates(int r, int q, int height);

};
