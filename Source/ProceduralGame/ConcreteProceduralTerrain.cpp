// Fill out your copyright notice in the Description page of Project Settings.

#include "ProceduralGame.h"
#include "ConcreteProceduralTerrain.h"

void AConcreteProceduralTerrain::UpdateMesh()
{
	TArray<FVector> Vertices;
	TArray<int32> Triangles;
	TArray<FVector> Normals;
	TArray<FVector2D> UVs;
	TArray<FProcMeshTangent> Tangents;
	TArray<FColor> VertexColors;

	int32 index = 0;
	int32 elementID = 0;
	for (int32 x = 0; x < chunkLineElements; x++)
	{
		for (int32 y = 0; y < chunkLineElements; y++)
		{
			index = x + (y * chunkLineElements);
			int32 z = chunkFields[index];

			//add faces, vertices, UVs and normals
			int triangle_num = 0;
			if (isFaceVisible()) {
				//vertices
				Vertices.Add(FVector(voxelSize * x, voxelSize * y, voxelSize * z));
				Vertices.Add(FVector(voxelSize * (x + 1), voxelSize * y, voxelSize * z));
				Vertices.Add(FVector(voxelSize * (x + 1), voxelSize * (y + 1), voxelSize * z));
				Vertices.Add(FVector(voxelSize * x, voxelSize * (y + 1), voxelSize * z));

				Triangles.Add(2 + triangle_num + index);
				Triangles.Add(1 + triangle_num + index);
				Triangles.Add(0 + triangle_num + index);
				Triangles.Add(0 + triangle_num + index);
				Triangles.Add(3 + triangle_num + index);
				Triangles.Add(2 + triangle_num + index);
				triangle_num += 4;
							
				

				//UVs.Append(bUvs, ARRAY_COUNT(bUvs));
				//FColor color = FColor(RandomStream.FRand() * 256, RandomStream.FRand() * 256, RandomStream.FRand() * 256, rand() % 5);
				FColor color = FColor(255, 255, 255, 1);
				VertexColors.Add(color);
				VertexColors.Add(color);
				VertexColors.Add(color);
				VertexColors.Add(color);
				}
			elementID += 4;
			}
	}
	proceduralComponent->ClearAllMeshSections();
	proceduralComponent->CreateMeshSection(0, Vertices, Triangles, Normals, UVs, VertexColors, Tangents, true);
}

bool AConcreteProceduralTerrain::isFaceVisible()
{
	return true;
}


/*int32 AConcreteProceduralTerrain::GenerateNoise(int32 index) {
	float fNoise = index;
	int32 noise = (int32)fNoise;
	return noise;
}*/
