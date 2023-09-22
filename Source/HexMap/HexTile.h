// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HexTile.generated.h"

UENUM()
enum class HexTileType {
	INVALID,
	DIRT,
	GRASS,
	MARSH,
	MOUNTAIN,
	SWAMP,
	WATER,
	MAX UMETA(Hidden)
};

USTRUCT(BlueprintType)
struct FHexCoords {
	GENERATED_BODY()

	/*  */
	UPROPERTY(EditAnywhere)
	int32 qAxis;
	/*  */
	UPROPERTY(EditAnywhere)
	int32 rAxis;
	/*  */
	UPROPERTY(EditAnywhere)
	int32 sAxis;

	FHexCoords() {
		qAxis = 0;
		rAxis = 0;
		sAxis = 0;
	}

	/* Q is for Column, R is for Row. */
	FHexCoords(int32 q, int32 r) {
		qAxis = q;
		rAxis = r;
		// Auto calculate the S position
		sAxis = -q - r;
	}
};

UCLASS()
class HEXMAP_API AHexTile : public AActor {
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tile")
	bool bIsOccupied;

	UPROPERTY(EditAnywhere, Category = "Tile")
	FHexCoords Coordinates;

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

protected:
	virtual void BeginPlay() override;

private:
	void OnTileSelected(AActor* TouchedActor, FKey ButtonPressed);
};
