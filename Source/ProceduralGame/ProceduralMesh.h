// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "ProceduralMesh.generated.h"

UCLASS()
class PROCEDURALGAME_API AProceduralMesh : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProceduralMesh();
	UPROPERTY(VisibleAnywhere, Category = "MyProceduralMesh")
		UProceduralMeshComponent* pm;

public:

	UPROPERTY()
		TArray<FVector> vertices;
	UPROPERTY()
		TArray<FVector> normals;
	UPROPERTY()
		TArray<int32> triangles;
	UPROPERTY()
		TArray<FVector2D> uvs;
	UPROPERTY()
		TArray<FLinearColor> vertexColors;
	UPROPERTY()
		TArray<FProcMeshTangent> tangents;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProceduralMesh")
		int32 height;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProceduralMesh")
		int32 width;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProceduralMesh")
		float spacing;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProceduralMesh")
		int32 maxAltitude;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProceduralMesh")
		bool generateMesh;

	virtual void OnConstruction(const FTransform& Transform) override;

	void GenerateVertices();
	void GenerateTriangles();
	void ClearMeshData();

	//DiamondSquare noise
	/*TArray<float> GenerateSquareNoiseArray();
	void InitDiamondSquare(int startX, int startY, int endX, int endY);
	TArray<float> DiamondSquare(int x, int y, int half, int range);
	TArray<float> Square(int step);
	TArray<float> Diamond(int step);*/
	
};
