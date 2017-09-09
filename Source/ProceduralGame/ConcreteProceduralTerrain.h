// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProceduralMeshComponent.h"
#include "ProceduralTerrain.h"
#include "ConcreteProceduralTerrain.generated.h"

/**
 * 
 */
UCLASS()
class PROCEDURALGAME_API AConcreteProceduralTerrain : public AProceduralTerrain
{
	GENERATED_BODY()

public:
	void UpdateMesh();

	bool isFaceVisible();
	
	//int32 GenerateNoise(int32 index);
};
