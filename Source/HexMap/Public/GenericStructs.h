// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GenericStructs.generated.h"

USTRUCT(BlueprintType)
struct FHexCoordinates {
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

	FHexCoordinates() {
		qAxis = 0;
		rAxis = 0;
		sAxis = 0;
	}

	/* Q is for Column, R is for Row. */
	FHexCoordinates(int32 q, int32 r) {
		qAxis = q;
		rAxis = r;
		// Auto calculate the S position
		sAxis = -q - r;
	}
};
