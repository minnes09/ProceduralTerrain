// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "ProceduralTerrain.generated.h"

UCLASS()
class PROCEDURALGAME_API AProceduralTerrain : public AActor
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
		TArray<UMaterialInterface *> Materials;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
		int32 randomSeed = 123456789;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Procedural", Meta = (ExposeOnSpawn = true))
		int32 voxelSize = 100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Procedural", Meta = (ExposeOnSpawn = true))
		int32 maxAltitude = 5000;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Procedural")
		int32 height = 5;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Procedural", Meta = (ExposeOnSpawn = true))
		int32 chunkLineElements = 10;//must be multiple of 2
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Procedural", Meta = (ExposeOnSpawn = true))
		int32 chunkXIndex = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Procedural", Meta = (ExposeOnSpawn = true))
		int32 chunkYIndex = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Procedural")
		float xMult = 0.1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Procedural", meta = (ClampMin = "0.00000001", ClampMax = "1.0", UIMin = "0.0001", UIMax = "1.0"))
		float yMult = 0.1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Procedural", meta = (ClampMin = "0.00000001", ClampMax = "1.0", UIMin = "0.0001", UIMax = "1.0"))
		float zMult = 0.1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Procedural", meta = (ClampMin = "0.00000001", ClampMax = "1.0", UIMin = "0.0001", UIMax = "1.0"))
		int32 weight = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Procedural")
		int32 freq = 1;
	UPROPERTY()
		int32 chunkTotalElements;
	UPROPERTY()
		int32 chunkZElements;
	UPROPERTY()
		int32 chunkLineElementsP2;
	UPROPERTY()
		int32 voxelSizeHalf;
	UPROPERTY()
		TArray<float> chunkFields;
	UPROPERTY()
	class UProceduralMeshComponent * proceduralComponent;

	FVector worldLocation = FVector(0, 0, 0);
	// Sets default values for this actor's properties
	AProceduralTerrain();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	virtual void OnConstruction(const FTransform & Transform) override;

	void GenerateChunck();

	UFUNCTION(BlueprintCallable, Category= "Procedural")
	virtual int GenerateNoise(int32 index);

	virtual int32 GenerateNoise(int32 x, int32 y, int32 z);
	virtual void UpdateMesh();

	virtual void UpdateMeshSingleCube();
};
