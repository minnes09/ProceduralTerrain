// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProceduralMeshComponent.h"
#include "ProceduralTerrain.h"
#include "ProceduralPiramid.generated.h"

/**
 * 
 */
UCLASS()
class PROCEDURALGAME_API AProceduralPiramid : public AProceduralTerrain
{
	GENERATED_BODY()
public:
	
	//virtual void OnConstruction(const FTransform & Transform) override;

	void UpdateMesh();

};
