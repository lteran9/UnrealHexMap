// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Public/GenericStructs.h"
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

UCLASS()
class HEXMAP_API AHexTile : public AActor {
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tile")
	bool bIsOccupied;

	UPROPERTY(EditAnywhere, Category = "Tile")
	FHexCoordinates Coordinates;

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
