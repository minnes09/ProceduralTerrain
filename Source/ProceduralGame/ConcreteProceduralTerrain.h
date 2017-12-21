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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Procedural", Meta = (ExposeOnSpawn = true))
		float frequency = 0.005;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Procedural")
		int iterations = 3;

	void UpdateMesh();

	bool isFaceVisible();
	
	int32 GenerateNoise(int32 index);

	int32 GenerateNoise(int32 x, int32 y, int32 z);

	void UpdateMeshPlain();

	void UpdateMeshFirstVertices(int section);

	void CreateSingleSquareSection(int section);
	void CreateSingleSquare(int32 x, int32 y, int32 z, TArray<FVector>* Vertices, TArray<int32>* Triangles, TArray<FVector>* Normals, TArray<FVector2D>* UVs, TArray<FProcMeshTangent>* Tangents, TArray<FColor>* VertexColors);
	//loop with +4
	void UpdateMesh4();

	TArray<float> GenerateNoiseArray();
	TArray<float> GenerateNoiseArrayWithSimplex();
	TArray<float> GenerateNoiseArrayWithSimplex(float frequency);
	float CalculatePointNoise(float x, float y, int32 iterations);
	/*UFUNCTION(BlueprintNativeEvent, category="Procedural")
	TArray<float> SmoothNoise(TArray<float> noise);
	virtual TArray<float> SmoothNoise_Implementation(TArray<float> noise);*/
};
