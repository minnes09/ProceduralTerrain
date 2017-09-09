// Fill out your copyright notice in the Description page of Project Settings.

#include "ProceduralGame.h"
#include "ProceduralTerrain.h"

const int32 bTriangles[] = { 2, 1, 0, 0, 3, 2 };
const FVector2D bUvs[] = { FVector2D(0.000000, 0.000000), FVector2D(1.000000, 1.000000), FVector2D(0.000000, 1.000000), FVector2D(1.000000, 0.000000)};
const FVector bNormals0[] = { FVector(0,0,1), FVector(0,0,1), FVector(0,0,1), FVector(0,0,1) };
const FVector bNormals1[] = { FVector(0,0,-1), FVector(0,0,-1), FVector(0,0,-1), FVector(0,0,-1) };
const FVector bNormals2[] = { FVector(0,1,0), FVector(0,1,0), FVector(0,1,0), FVector(0,1,0) };
const FVector bNormals3[] = { FVector(0,-1,0), FVector(0,-1,0), FVector(0,-1,0), FVector(0,-1,0) };
const FVector bNormals4[] = { FVector(1,0,0), FVector(1,0,0), FVector(1,0,0), FVector(1,0,0) };
const FVector bNormals5[] = { FVector(-1,0,0), FVector(-1,0,0), FVector(-1,0,0), FVector(-1,0,0) };
const FVector bMask[] = { FVector(0.000000,0.000000,1.000000), FVector(0.000000,0.000000,-1.000000), FVector(0.000000,1.000000, 0.000000), FVector(0.000000,-1.000000, 0.000000), FVector(0.000000, 0.000000, 1.000000), FVector(0.000000, 0.000000, -1.000000) };
// Sets default values
AProceduralTerrain::AProceduralTerrain()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	/*
	*	Create/replace a section for this procedural mesh component.
	*	@param	SectionIndex		Index of the section to create or replace.
	*	@param	Vertices			Vertex buffer of all vertex positions to use for this mesh section.
	*	@param	Triangles			Index buffer indicating which vertices make up each triangle. Length must be a multiple of 3.
	*	@param	Normals				Optional array of normal vectors for each vertex. If supplied, must be same length as Vertices array.
	*	@param	UV0					Optional array of texture co-ordinates for each vertex. If supplied, must be same length as Vertices array.
	*	@param	VertexColors		Optional array of colors for each vertex. If supplied, must be same length as Vertices array.
	*	@param	Tangents			Optional array of tangent vector for each vertex. If supplied, must be same length as Vertices array.
	*	@param	bCreateCollision	Indicates whether collision should be created for this section. This adds significant cost.
	*/

}

// Called when the game starts or when spawned
void AProceduralTerrain::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AProceduralTerrain::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AProceduralTerrain::OnConstruction(const FTransform & Transform)
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
	//worldLocation = RootComponent->GetComponentLocation();
	Super::OnConstruction(Transform);

	GenerateChunck();
	UpdateMesh();
}

void AProceduralTerrain::GenerateChunck()
{
	chunkFields.SetNumUninitialized(chunkTotalElements);

	for (int32 x = 0; x < chunkLineElements; x++)
	{
		for (int32 y = 0; y < chunkLineElements; y++)
		{
			for (int32 z = 0; z < chunkZElements; z++)
			{
				int32 index = x + (y * chunkLineElements) + (z * chunkLineElementsP2);
				/*int32 noise = GenerateNoise(x,y,z);
				noise = noise + chunkFields[index - 1];*/
				chunkFields[index] = (z < 30 /*+ noise*/) ?  1 : 0;
			}
		}
	}
}

/*int32 AProceduralTerrain::GenerateNoise(int32 x, int32 y, int32 z)
{
	int32 noise = 0;
	float xNoise = FMath::Cos(x) * worldLocation.X * xMult;
	float yNoise = FMath::Sin(y) * worldLocation.Y * yMult;
	if (chunkXIndex != 0 && chunkYIndex != 0) {
		noise = (xNoise * (chunkXIndex + 1) + yNoise * (chunkYIndex + 1));
	}
	else {
		noise = (xNoise + yNoise);
	}

	return noise;
}*/

void AProceduralTerrain::UpdateMesh()
{
	TArray<FVector> Vertices;
	TArray<int32> Triangles;
	TArray<FVector> Normals;
	TArray<FVector2D> UVs;
	TArray<FProcMeshTangent> Tangents;
	TArray<FColor> VertexColors;

	int32 elementID = 0;

	for (int32 x = 0; x < chunkLineElements; x++)
	{
		for (int32 y = 0; y < chunkLineElements; y++)
		{
			for (int32 z = 0; z < chunkZElements; z++)
			{
				int32 index = x + (y * chunkLineElements) + (z * chunkLineElementsP2);
				int32 meshIndex = chunkFields[index];


				if (meshIndex > 0) {
					meshIndex--;

					//add faces, vertices, UVs and normals
					int triangle_num = 0;
					for (int i = 0; i < 6; i++)
					{
						int newIndex = index + bMask[i].X + (bMask[i].Y * chunkLineElements) + (bMask[i].Z * chunkLineElementsP2);
						if (meshIndex > 0) {
							meshIndex--;
							bool flag = false;
							if (meshIndex >= 20)
								flag = true;
							else if ((x + bMask[i].X < chunkLineElements) && (x + bMask[i].X >= 0) && (y + bMask[i].Y < chunkLineElements) && (y + bMask[i].Y >= 0))
							{
								if (newIndex < chunkFields.Num() && newIndex >= 0 && chunkFields[newIndex] < 1)
									flag = true;
							}
							else flag = true;
							if (flag) {
								Triangles.Add(bTriangles[0] + triangle_num + elementID);
								Triangles.Add(bTriangles[1] + triangle_num + elementID);
								Triangles.Add(bTriangles[2] + triangle_num + elementID);
								Triangles.Add(bTriangles[3] + triangle_num + elementID);
								Triangles.Add(bTriangles[4] + triangle_num + elementID);
								Triangles.Add(bTriangles[5] + triangle_num + elementID);
								triangle_num += 4;
								switch (i) {
								case 0: {//ok
									Vertices.Add(FVector(-voxelSizeHalf + x * voxelSize, voxelSizeHalf + y * voxelSize, voxelSizeHalf + z * voxelSize));//e
									Vertices.Add(FVector(-voxelSizeHalf + x * voxelSize, -voxelSizeHalf + y * voxelSize, voxelSizeHalf + z * voxelSize));//c
									Vertices.Add(FVector(voxelSizeHalf + x * voxelSize, -voxelSizeHalf + y * voxelSize, voxelSizeHalf + z * voxelSize));//d
									Vertices.Add(FVector(voxelSizeHalf + x * voxelSize, voxelSizeHalf + y * voxelSize, voxelSizeHalf + z * voxelSize));//f
								}
								case 1: {
									Vertices.Add(FVector(voxelSizeHalf + x * voxelSize, -voxelSizeHalf + y * voxelSize, -voxelSizeHalf + z * voxelSize));//b
									Vertices.Add(FVector(-voxelSizeHalf + x * voxelSize, -voxelSizeHalf + y * voxelSize, -voxelSizeHalf + z * voxelSize));//a
									Vertices.Add(FVector(-voxelSizeHalf + x * voxelSize, voxelSizeHalf + y * voxelSize, -voxelSizeHalf + z * voxelSize));//g
									Vertices.Add(FVector(voxelSizeHalf + x * voxelSize, voxelSizeHalf + y * voxelSize, -voxelSizeHalf + z * voxelSize));//h
								}
								case 2: {//ok
									Vertices.Add(FVector(voxelSizeHalf + x * voxelSize, voxelSizeHalf + y * voxelSize, voxelSizeHalf + z * voxelSize));//f
									Vertices.Add(FVector(voxelSizeHalf + x * voxelSize, voxelSizeHalf + y * voxelSize, -voxelSizeHalf + z * voxelSize));//h
									Vertices.Add(FVector(-voxelSizeHalf + x * voxelSize, voxelSizeHalf + y * voxelSize, -voxelSizeHalf + z * voxelSize));//g
									Vertices.Add(FVector(-voxelSizeHalf + x * voxelSize, voxelSizeHalf + y * voxelSize, voxelSizeHalf + z * voxelSize));//e
								}
								case 3: {//ok
									Vertices.Add(FVector(voxelSizeHalf + x * voxelSize, -voxelSizeHalf + y * voxelSize, -voxelSizeHalf + z * voxelSize));//b
									Vertices.Add(FVector(-voxelSizeHalf + x * voxelSize, -voxelSizeHalf + y * voxelSize, -voxelSizeHalf + z * voxelSize));//a
									Vertices.Add(FVector(-voxelSizeHalf + x * voxelSize, -voxelSizeHalf + y * voxelSize, voxelSizeHalf + z * voxelSize));//c
									Vertices.Add(FVector(voxelSizeHalf + x * voxelSize, -voxelSizeHalf + y * voxelSize, voxelSizeHalf + z * voxelSize));//d
								}
								case 4: {//OK
									Vertices.Add(FVector(voxelSizeHalf + x * voxelSize, -voxelSizeHalf + y * voxelSize, voxelSizeHalf + z * voxelSize));//d
									Vertices.Add(FVector(voxelSizeHalf + x * voxelSize, -voxelSizeHalf + y * voxelSize, -voxelSizeHalf + z * voxelSize));//b
									Vertices.Add(FVector(voxelSizeHalf + x * voxelSize, voxelSizeHalf + y * voxelSize, -voxelSizeHalf + z * voxelSize));//h
									Vertices.Add(FVector(voxelSizeHalf + x * voxelSize, voxelSizeHalf + y * voxelSize, voxelSizeHalf + z * voxelSize));//f
								}
								case 5: {
									Vertices.Add(FVector(-voxelSizeHalf + x * voxelSize, voxelSizeHalf + y * voxelSize, voxelSizeHalf + z * voxelSize));//e
									Vertices.Add(FVector(-voxelSizeHalf + x * voxelSize, voxelSizeHalf + y * voxelSize, -voxelSizeHalf + z * voxelSize));//g
									Vertices.Add(FVector(-voxelSizeHalf + x * voxelSize, -voxelSizeHalf + y * voxelSize, -voxelSizeHalf + z * voxelSize));//a
									Vertices.Add(FVector(-voxelSizeHalf + x * voxelSize, -voxelSizeHalf + y * voxelSize, voxelSizeHalf + z * voxelSize));//c
								}
								}
								UVs.Append(bUvs, ARRAY_COUNT(bUvs));
								//FColor color = FColor(RandomStream.FRand() * 256, RandomStream.FRand() * 256, RandomStream.FRand() * 256, rand() % 5);
								FColor color = FColor(255, 255, 255, 1);
								VertexColors.Add(color);
								VertexColors.Add(color);
								VertexColors.Add(color);
								VertexColors.Add(color);
							}
							elementID += triangle_num;
						}
					}
				}

			}
		}
	}
	proceduralComponent->ClearAllMeshSections();
	proceduralComponent->CreateMeshSection(0, Vertices, Triangles, Normals, UVs, VertexColors, Tangents, true);



}

void AProceduralTerrain::UpdateMeshSingleCube()
{
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
					for (int32 i = 0; i < 6; i++)
					{
						FColor color = FColor(255,0,0,1); 
						switch (i) {
						case 0: {
							vertices.Add(FVector(voxelSize * x, voxelSize * y, z * voxelSize)); //A
							vertices.Add(FVector(voxelSize * (x + 1), voxelSize * y, z * voxelSize)); //B
							vertices.Add(FVector(voxelSize * x, voxelSize * (y + 1), z * voxelSize)); //G
							vertices.Add(FVector(voxelSize * (x + 1), voxelSize * (y + 1), z * voxelSize)); //H
							color = color.Black; 
						}
						case 1: {
							vertices.Add(FVector(voxelSize * x, voxelSize * y, z * voxelSize)); //A
							vertices.Add(FVector(voxelSize * x, voxelSize * y, (z + 1) * voxelSize));//C
							vertices.Add(FVector(voxelSize * (x + 1), voxelSize * y, z * voxelSize));//B
							vertices.Add(FVector(voxelSize * (x + 1), voxelSize * y, (z + 1) * voxelSize));//D
							color = color.Red; 
						}
						case 2: {
							vertices.Add(FVector(voxelSize * x, voxelSize * y, (z + 1) * voxelSize));//C
							vertices.Add(FVector(voxelSize * x, voxelSize * (y + 1), (z + 1) * voxelSize));//E
							vertices.Add(FVector(voxelSize * (x + 1), voxelSize * y, (z + 1) * voxelSize));//D
							vertices.Add(FVector(voxelSize * (x + 1), voxelSize * (y + 1), (z + 1) * voxelSize));//F
							color = color.Green;
						}
						case 3: {
							vertices.Add(FVector(voxelSize * x, voxelSize * (y + 1), z * voxelSize));//G
							vertices.Add(FVector(voxelSize * (x + 1), voxelSize * (y + 1), z * voxelSize));//H
							vertices.Add(FVector(voxelSize * x, voxelSize * (y + 1), (z + 1) * voxelSize));//E
							vertices.Add(FVector(voxelSize * (x + 1), voxelSize * (y + 1), (z + 1) * voxelSize));//F
							color = color.Blue;
						}
						case 4: {
							vertices.Add(FVector(voxelSize * x, voxelSize * (y + 1), z * voxelSize));//G
							vertices.Add(FVector(voxelSize * x, voxelSize * (y + 1), (z + 1) * voxelSize));//E
							vertices.Add(FVector(voxelSize * x, voxelSize * y, z * voxelSize)); //A
							vertices.Add(FVector(voxelSize * x, voxelSize * y, (z + 1) * voxelSize));//C
							color = color.White;
						}
						case 5: {							
							vertices.Add(FVector(voxelSize * (x + 1), voxelSize * (y + 1), (z + 1) * voxelSize));//F
							vertices.Add(FVector(voxelSize * (x + 1), voxelSize * (y + 1), z * voxelSize));//H
							vertices.Add(FVector(voxelSize * (x + 1), voxelSize * y, (z + 1) * voxelSize));//D
							vertices.Add(FVector(voxelSize * (x + 1), voxelSize * y, z * voxelSize));//B
							color = color.Yellow;
						}

						}

						UVs.Append(bUvs, ARRAY_COUNT(bUvs));

						Triangles.Add(0 + triangle_num);
						Triangles.Add(1 + triangle_num);
						Triangles.Add(2 + triangle_num);
						Triangles.Add(3 + triangle_num);
						Triangles.Add(2 + triangle_num);
						Triangles.Add(1 + triangle_num);
						triangle_num += 4;

						VertexColors.Add(color);
						VertexColors.Add(color);
						VertexColors.Add(color);
						VertexColors.Add(color);
					
				}
			}
		}

	}

	proceduralComponent->ClearAllMeshSections();
	proceduralComponent->CreateMeshSection(0, vertices, Triangles, Normals, UVs, VertexColors, Tangents, true);


}

/*int32 AProceduralTerrain::GenerateNoise(int32 index) {

	int32 noise = 1;

	return noise;
}*/
