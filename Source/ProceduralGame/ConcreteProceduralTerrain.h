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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Procedural")
		float heightRange = 50;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Procedural")
		int offset = 0;
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
	TArray<float> GenerateNoiseArrayWithSimplex();
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
};
