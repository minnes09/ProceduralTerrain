// Fill out your copyright notice in the Description page of Project Settings.

#include "ProceduralGame.h"
#include "ProceduralPiramid.h"
/*AProceduralPiramid::AProceduralPiramid() {
	Super();
}*/
/*void AProceduralPiramid::OnConstruction(const FTransform & Transform)
{
	chunkZElements = 80;
	chunkTotalElements = chunkLineElements * chunkLineElements * chunkZElements;
	chunkLineElementsP2 = chunkLineElements * chunkLineElements;
	voxelSizeHalf = voxelSize / 2;

	FString string = "Voxel: " + FString::FromInt(chunkXIndex) + "_" + FString::FromInt(chunkXIndex);
	FName name = FName(*string);
	proceduralComponent = NewObject<UProceduralMeshComponent>(this, name);
	proceduralComponent->RegisterComponent();


	RootComponent = proceduralComponent;
	RootComponent->SetWorldTransform(Transform); //set position of root component

	Super::Super::OnConstruction(Transform);

	GenerateChunck();
	UpdateMeshSingleCube();
}*/
void AProceduralPiramid::UpdateMesh() {
	TArray<FVector> vertices;
	TArray<int32> Triangles;
	TArray<FVector> Normals;
	TArray<FVector2D> UVs;
	TArray<FProcMeshTangent> Tangents;
	TArray<FColor> VertexColors;

	int32 triangle_num = 0;
	for (int32 x = 0; x < 1; x++)
	{
		for (int32 y = 0; y < 1; y++)
		{
			for (int32 z = 0; z < 1; z++)
			{
				vertices.Add(FVector(x * voxelSize, y * voxelSize, z * voxelSize));//A
				vertices.Add(FVector((x + 1) * voxelSize, y * voxelSize, z * voxelSize));//B
				vertices.Add(FVector((x + 1) * voxelSize, (y + 1) * voxelSize, z * voxelSize));//C
				vertices.Add(FVector(x * voxelSize, (y + 1) * voxelSize, z * voxelSize));//D
				vertices.Add(FVector((x + 1) * voxelSize / 2, (y + 1) * voxelSize / 2, (z + 1) * voxelSize));//E

				UVs.Add(FVector2D(0, 0));
				UVs.Add(FVector2D(0, 1));
				UVs.Add(FVector2D(1, 1));
				UVs.Add(FVector2D(1, 0));
				UVs.Add(FVector2D(0,0));
				//base
				Triangles.Add(0);
				Triangles.Add(1);
				Triangles.Add(2);
				Triangles.Add(0);
				Triangles.Add(2);
				Triangles.Add(3);

				//faces
				Triangles.Add(2);
				Triangles.Add(1);
				Triangles.Add(4);

				Triangles.Add(1);
				Triangles.Add(0);
				Triangles.Add(4);

				Triangles.Add(4);
				Triangles.Add(0);
				Triangles.Add(3);

				Triangles.Add(3);
				Triangles.Add(2);
				Triangles.Add(4);

				FColor color = FColor(100,100,100,1);
				VertexColors.Add(color);
				VertexColors.Add(color);
				VertexColors.Add(color);
				VertexColors.Add(color);
				VertexColors.Add(color);


				//normals
				/*Normals.Add(FVector(-1, -1, -1));
				Normals.Add(FVector(1, 0, 0));
				Normals.Add(FVector(0, 1, 0));
				Normals.Add(FVector(-1, 0, 0));
				Normals.Add(FVector(0, -1, 0));*/
				}
			}
		}
	proceduralComponent->ClearAllMeshSections();
	proceduralComponent->CreateMeshSection(0, vertices, Triangles, Normals, UVs, VertexColors, Tangents, true);
}



