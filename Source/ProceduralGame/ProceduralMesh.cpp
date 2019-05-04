// Fill out your copyright notice in the Description page of Project Settings.

#include "ProceduralGame.h"
#include "ProceduralMesh.h"
#include "ProceduralMesh.h"


AProceduralMesh::AProceduralMesh()
{
	PrimaryActorTick.bCanEverTick = true;

	pm = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("ProceduralMesh"));
	pm->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);

	width = 4;
	height = 4;
	spacing = 50.0f;
	maxAltitude = 100;

	generateMesh = false;
}

void AProceduralMesh::OnConstruction(const FTransform& Transform)
{
	if (generateMesh)
	{
		generateMesh = false;

		ClearMeshData();

		GenerateVertices();
		GenerateTriangles();

		//Function that creates mesh section
		pm->CreateMeshSection_LinearColor(0, vertices, triangles, normals, uvs, vertexColors, tangents, false);
	}
}

void AProceduralMesh::GenerateVertices()
{
	float uvSpacing = 1.0f / FMath::Max(height, width);

	for (int32 y = 0; y < height; y++)
	{
		for (int32 x = 0; x < width; x++)
		{
			vertices.Add(FVector(x * spacing, y * spacing, FMath::FRandRange(-maxAltitude, maxAltitude)));
			normals.Add(FVector(0.0f, 0.0f, 1.0f));
			uvs.Add(FVector2D(x * uvSpacing, y * uvSpacing));
			vertexColors.Add(FLinearColor(0.0f, 0.0f, 0.0f, 1.0f));
			tangents.Add(FProcMeshTangent(1.0f, 0.0f, 0.0f));
		}
	}
}

void AProceduralMesh::GenerateTriangles()
{
	for (int32 y = 0; y < height - 1; y++)
	{
		for (int32 x = 0; x < width - 1; x++)
		{
			int A = x + (y * width);
			int B = x + (y * width) + width;
			int C = x + (y * width) + width + 1;
			int D = x + (y * width) + 1;
			triangles.Add(x + (y * width));					//current vertex: A
			triangles.Add(x + (y * width) + width);			//current vertex + row: B
			triangles.Add(x + (y * width) + width + 1);		//current vertex + row + one right: C

			triangles.Add(x + (y * width));					//current vertex: A
			triangles.Add(x + (y * width) + width + 1);		//current vertex + row + one right: C
			triangles.Add(x + (y * width) + 1);				//current vertex + one right: D

			FVector* vA = &vertices[x + (y * width)];
			FVector* vB = &vertices[x + (y * width) + width];
			FVector* vC = &vertices[x + (y * width) + width + 1];
			FVector* vD = &vertices[x + (y * width) + 1];

			FVector n = FVector::CrossProduct(*vB - *vA, *vC - *vA);
			n.Normalize();
			normals[x + (y * width)] = n;
			normals[x + (y * width) + width] = n;
			normals[x + (y * width) + width + 1] = n;
			normals[x + (y * width) + 1] = n;
		}
	}
}
void AProceduralMesh::ClearMeshData()
{
	vertices.Empty();
	triangles.Empty();
	uvs.Empty();
	normals.Empty();
	vertexColors.Empty();
	tangents.Empty();
}

/*
//diamond square noise
TArray<float> AProceduralMesh::GenerateSquareNoiseArray()
{
	noise.SetNumZeroed(chunkLineElementsP2);
	int start = 0;
	int size = chunkLineElements - 1;
	int step = size;
	if (step % 2 != 0) {
		UE_LOG(LogClass, Error, TEXT("step is not multiple of 2"));
	}
	//Diamond Square Algorithm
	InitDiamondSquare(start, start, size, size);
	while (step > 1) {
		int half = step / 2;

		for (int x = half; x < size; x += step) {
			for (int y = half; y < size; y += step) {
				int offset = USimplexNoiseLibrary::SimplexNoise2D(x, y) * heightRange;
				DiamondSquare(x, y, half, offset);
			}
		}
		step = half;
		heightRange /= 2;
	}

	return noise;
}

void AProceduralMesh::InitDiamondSquare(int startX, int startY, int endX, int endY)
{
	//4 corners
	noise[GetGridPosition(startX, startY)] = FMath::FRandRange(-maxAltitude, maxAltitude);
	noise[GetGridPosition(startX, endY)] = FMath::FRandRange(-maxAltitude, maxAltitude);
	noise[GetGridPosition(endX, startY)] = FMath::FRandRange(-maxAltitude, maxAltitude);
	noise[GetGridPosition(endX, endY)] = FMath::FRandRange(-maxAltitude, maxAltitude);
	/*float x1 = chunkXIndex - 0.5f;
	float y1 = chunkYIndex - 0.5f;
	float x2 = chunkXIndex + 0.5f;
	float y2 = chunkYIndex - 0.5f;
	noise[startX + chunkLineElements * startY] = ((x1 + y1) * (randomSeed % maxAltitude)) + maxAltitude + PseudoRandomOffset(x1, y1);
	noise[startX + chunkLineElements * endY] = ((x1 + y2) * (randomSeed % maxAltitude)) + maxAltitude + PseudoRandomOffset(x1, y2);
	noise[endX + chunkLineElements * startY] = ((x2 + y1) * (randomSeed % maxAltitude)) + maxAltitude + PseudoRandomOffset(x2, y1);
	noise[endX + chunkLineElements * endY] = ((x2 + y2) * (randomSeed % maxAltitude)) + maxAltitude + PseudoRandomOffset(x2, y2);*//*
}


TArray<float> AProceduralMesh::DiamondSquare(int x, int y, int half, int range)
{
	float a = noise[GetGridPosition(x - half, y - half)];
	float b = noise[GetGridPosition(x + half, y - half)];
	float c = noise[GetGridPosition(x + half, y + half)];
	float d = noise[GetGridPosition(x - half, y + half)];

	//diamond
	float e = (a + b + c + d) * 0.25f;
	noise[GetGridPosition(x, y)] = e + FMath::FRandRange(-range, range);

	//square
	noise[GetGridPosition(x - half, y)] = (a + d + e) / 3 + FMath::FRandRange(-range, range);
	noise[GetGridPosition(x, y + half)] = (c + d + e) / 3 + FMath::FRandRange(-range, range);
	noise[GetGridPosition(x + half, y)] = (b + c + e) / 3 + FMath::FRandRange(-range, range);
	noise[GetGridPosition(x, y - half)] = (a + b + e) / 3 + FMath::FRandRange(-range, range);
	return noise;
}*/
