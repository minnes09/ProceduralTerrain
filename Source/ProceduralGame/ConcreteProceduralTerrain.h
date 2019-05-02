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

	AConcreteProceduralTerrain();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Perlin", Meta = (ExposeOnSpawn = true))
		float lacunarity = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Perlin", meta = (ClampMin = "1", UIMin = "1", ExposeOnSpawn = true))
		int iterations = 4;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Perlin")
		float heightRange = 50;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Perlin", meta = (ClampMin = "0.00000001", ClampMax = "1.0", UIMin = "0.0001", UIMax = "1.0", ExposeOnSpawn = true))
		float persistence = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Procedural")
		UMaterial* Material;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Procedural")
		TArray<FColor> colors;
	//array for the altitude
	TArray<float> noise;

	void OnConstruction(const FTransform & Transform) override;

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
	TArray<float> GeneratePerlinNoiseArray();
	TArray<float> GenerateNoiseArrayWithSimplex(float f);
	TArray<float> GenerateNoiseArrayRecursive();
	void GenerateNoiseArrayRecursive(float f);
	float CalculatePointNoise(float x, float y, int32 iterations);

	int GetGridPosition( int x, int y);

	TArray<float> GenerateSquareNoiseArray();
	void InitDiamondSquare(int startX, int startY, int endX, int endY);
	TArray<float> DiamondSquare(int x, int y, int half, int range);
	TArray<float> Square(int step);
	TArray<float> Diamond( int step);

	float PseudoRandomOffset(float x, float y);
	/*UFUNCTION(BlueprintNativeEvent, category="Procedural")
	TArray<float> SmoothNoise(TArray<float> noise);
	virtual TArray<float> SmoothNoise_Implementation(TArray<float> noise);*/

	FColor ComputeVertexColor(float height);
};
