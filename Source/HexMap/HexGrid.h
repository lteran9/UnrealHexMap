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
	TArray<TArray<AHexTile*>> HexGrid;

	UPROPERTY(EditAnywhere, Category = "Grid")
	int32 Width;
	UPROPERTY(EditAnywhere, Category = "Grid")
	int32 Height;
	/* The tile outer radius in centimeters. */
	UPROPERTY(EditAnywhere, Category = "Grid")
	float TileSize;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Grid")
	TSubclassOf<AHexTile> GrassHexTile;

public:
	// Sets default values for this actor's properties
	AHexGrid();

protected:	
	virtual void BeginPlay() override;

private:
	FVector GetCoordinates(int r, int q);

};
