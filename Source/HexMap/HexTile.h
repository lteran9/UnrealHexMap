// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HexTile.generated.h"

UENUM()
enum class HexTileType
{
	INVALID,
	DIRT,
	GRASS,
	MARSH,
	MOUNTAIN,
	SWAMP,
	WATER,
	MAX UMETA(Hidden)
};

UCLASS()
class HEXMAP_API AHexTile : public AActor
{
	GENERATED_BODY()

protected:
	/* Cube coordinate Q */
	UPROPERTY(EditAnywhere, Category = "Tile")
	int32 qAxis;
	/* Cube coordinate R */
	UPROPERTY(EditAnywhere, Category = "Tile")
	int32 rAxis;
	/* Cube coordinate S */
	UPROPERTY(EditAnywhere, Category = "Tile")
	int32 sAxis;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tile")
	HexTileType Type;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tile")
	UStaticMeshComponent* Mesh;

public:
	// Sets default values for this actor's properties
	AHexTile();
	//
	void SetCubeCoordinates(int32 row, int32 col);

	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
