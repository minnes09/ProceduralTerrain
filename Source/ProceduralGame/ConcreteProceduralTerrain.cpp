// Fill out your copyright notice in the Description page of Project Settings.

#include "ProceduralGame.h"
#include "SimplexNoiseLibrary.h"
#include "ConcreteProceduralTerrain.h"

void AConcreteProceduralTerrain::UpdateMesh() {
	
	/*TArray<FVector> Vertices;
	TArray<int32> Triangles;
	TArray<FVector> Normals;
	TArray<FVector2D> UVs;
	TArray<FProcMeshTangent> Tangents;
	TArray<FColor> VertexColors;

	TArray<float> noise = GenerateNoiseArray();
	int32 z = 0;
	for (int32 x = 0; x < chunkLineElements; x++) {
		for (int32 y = 0; y < chunkLineElements; y++) {
			CreateSingleSquare(x, y, noise[z], &Vertices, &Triangles, &Normals, &UVs, &Tangents, &VertexColors);
			if(z < noise.Num() - 1 ) z++;
		}
	}
	proceduralComponent->CreateMeshSection(0, Vertices, Triangles, Normals, UVs, VertexColors, Tangents, true);*/
	UpdateMeshFirstVertices(0);
}

void AConcreteProceduralTerrain::UpdateMeshPlain()
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
			index++;
			float z = chunkFields[index];

			//add faces, vertices, UVs and normals
			int triangle_num = 0;
			if (isFaceVisible()) {
				//vertices
				Vertices.Add(FVector(voxelSize * x, voxelSize * y, voxelSize * z));
				Vertices.Add(FVector(voxelSize * (x + 1), voxelSize * y, voxelSize * z));
				Vertices.Add(FVector(voxelSize * (x + 1), voxelSize * (y + 1), voxelSize * z));
				Vertices.Add(FVector(voxelSize * x, voxelSize * (y + 1), voxelSize * z));

				Triangles.Add(2 + triangle_num + elementID);
				Triangles.Add(1 + triangle_num + elementID);
				Triangles.Add(0 + triangle_num + elementID);
				Triangles.Add(0 + triangle_num + elementID);
				Triangles.Add(3 + triangle_num + elementID);
				Triangles.Add(2 + triangle_num + elementID);
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
	UpdateMesh4();
}

void AConcreteProceduralTerrain::UpdateMesh4() {

	TArray<FVector> Vertices;
	TArray<int32> Triangles;
	TArray<FVector> Normals;
	TArray<FVector2D> UVs;
	TArray<FProcMeshTangent> Tangents;
	TArray<FColor> VertexColors;

	TArray<float> noise = GenerateNoiseArray();
	//noise = SmoothNoise(noise);
	int32 index = 0;
	for (int32 x = 0; x < chunkLineElements; x += 4) {
		for (int32 y = 0; y < chunkLineElements; y += 4)
		{
			index = x * chunkLineElements + y;
			if (isFaceVisible()) {
				//vertices
				Vertices.Add(FVector(voxelSize * x, voxelSize * y, voxelSize * noise[index]));
				Vertices.Add(FVector(voxelSize * (x + 1), voxelSize * y, voxelSize * noise[index + 1]));
				Vertices.Add(FVector(voxelSize * (x + 1), voxelSize * (y + 1), voxelSize * noise[index + 2]));
				Vertices.Add(FVector(voxelSize * x, voxelSize * (y + 1), voxelSize * noise[index + 3]));

				Triangles.Add(2 + index);
				Triangles.Add(1 + index);
				Triangles.Add(0 + index);
				Triangles.Add(0 + index);
				Triangles.Add(3 + index);
				Triangles.Add(2 + index);

				FColor color = FColor(255, 255, 255, 1);
				VertexColors.Add(color);
				VertexColors.Add(color);
				VertexColors.Add(color);
				VertexColors.Add(color);
			}
		}
		proceduralComponent->CreateMeshSection(1, Vertices, Triangles, Normals, UVs, VertexColors, Tangents, true);
	}
}

//size must be multiple of 2
TArray<float> AConcreteProceduralTerrain::GenerateNoiseArray(){
	TArray<float> noise;
	noise.SetNumUninitialized(chunkLineElementsP2);
	/*int32 offNoise = (FMath::Sin(worldLocation.X * xMult) + FMath::Cos(worldLocation.Y * yMult)) * 4 - randomSeed % 64 + FMath::Tan(randomSeed) * FMath::Sin(randomSeed %128);
	noise[0] =  offNoise + randomSeed % 128 * FMath::Tan(offNoise - randomSeed);
	

	for (int32 x = 1; x < chunkLineElements; x++) {
		noise[x] = (noise[x - 1] + offNoise * 2) + randomSeed % 128;
	}
	for (int32 i = 1; i < chunkLineElements / 2; i++) {
		int32 a;
		if (i % 2 == 0) a = 1;
		else a = -1;
		noise[i] = (noise[i - 1] + offNoise - FMath::Sin(i) - FMath::Tan(i-1) - randomSeed % 128) * a;
		for (int32 j = 1; j < chunkLineElements / 2; j++) {
			int32 index = i * chunkLineElements + j;
			noise[index] = (noise[index - 1] 
				+ noise[index - chunkLineElements] 
				+ noise[index - chunkLineElements - 1]) / 3 
				+ (int32)(FMath::Cos((int32)(index / chunkLineElements)) * FMath::Sin(j) + 
					index / chunkTotalElements);
		}
	}*/
	for (int32 index = 0; index < chunkLineElementsP2; index++) {
		int32 a;
		if (index % 2 == 0) a = 1;
		else a = -1;
		float offNoise = a * randomSeed % 256 - FMath::Cos(index / 2) + FMath::Sin(index / 4);
		noise[index] = a * (FMath::Cos(index) - FMath::Sin(index) + offNoise);
		if (index > 0) {
			float absErr = FMath::Abs(noise[index] - noise[index - 1]);
			if (absErr > 50) {
				noise[index] = (noise[index] < noise[index - 1]) ? (noise[index - 1] - 50) : (noise[index - 1] + 50);
			}
		}
	}
	return noise;
}

bool AConcreteProceduralTerrain::isFaceVisible()
{
	return true;
}


int32 AConcreteProceduralTerrain::GenerateNoise(int32 index) {
	float fNoise = index;
	int32 noise = (int32)fNoise;
	return noise;
}

int32 AConcreteProceduralTerrain::GenerateNoise(int32 x, int32 y, int32 z) {

	float noiseX = (randomSeed % 64 ) * worldLocation.X * chunkXIndex * xMult;
	float noiseY = (randomSeed % 64) * worldLocation.Y * chunkYIndex * yMult;

	float fNoise = FMath::Cos(x) * FMath::Cos(y) + x*y*z*chunkTotalElements;
	fNoise = fNoise + noiseX + noiseY;
	int32 noise = (int32)fNoise;
	return noise;
}

TArray<float> AConcreteProceduralTerrain::GenerateNoiseArrayWithSimplex() {
	TArray<float> noise;
	noise.SetNumZeroed(chunkLineElementsP2);
	//float perc = 0.3f;
	noise[0] = USimplexNoiseLibrary::SimplexNoise2D(chunkXIndex, chunkYIndex);
	for (int32 x = 1; x < chunkLineElements; x++)
	{
		for (int32 y = 0; y < chunkLineElements; y++)
		{
			int index = x * chunkLineElements + y;
			float range;
			
			if (index - chunkLineElements - y - 1 >= 0 && y - 1 >= 0) range = (noise[index - chunkLineElements] + noise[y - 1] + noise[index - chunkLineElements - y - 1]) / 3;
			else if (y - 1 >= 0) range = (noise[x * chunkLineElements - 1] + noise[y - 1]) / 2;
			else range = noise[x - 1];
			//float offSet = range * perc;
				noise[index] = USimplexNoiseLibrary::SimplexNoiseInRange2D(chunkXIndex + x * voxelSize, chunkYIndex + y * voxelSize, range - 100, range + 100);
		}
	}
	return noise;
}
/*
frequency must be very low
*/
TArray<float> AConcreteProceduralTerrain::GenerateNoiseArrayWithSimplex(float frequency) {
	TArray<float> noise;
	noise.SetNumZeroed(chunkLineElementsP2);
	for (int32 x = 0; x < chunkLineElements; x++)
	{
		for (int32 y = 0; y < chunkLineElements; y++)
		{
			int index = x * chunkLineElements + y;
			float Xval = x * voxelSize * frequency;
			float Yval = y * voxelSize * frequency;
			noise[index] = CalculatePointNoise(Xval, Yval, iterations);
		}
	}
	return noise;
}
float AConcreteProceduralTerrain::CalculatePointNoise(float x, float y, int32 iterations)
{
	float pointNoise = 0;
	for (int32 i = 0; i < iterations; i++) {
		int32 power = FMath::Pow(2, i);
		pointNoise += ( FMath::Pow(2, -i) * USimplexNoiseLibrary::SimplexNoise2D(power * x, power * y) * maxAltitude );
	}
	return pointNoise;
}
/*
TArray<float> AConcreteProceduralTerrain::SmoothNoise_Implementation(TArray<float> noise)
{
	//remember to call super / parent function in BP!
	FString  PickupDebugString = GetName();
	UE_LOG(LogClass, Log, TEXT("You are smoothing %s"), *PickupDebugString);
	return noise;
}
*/
void AConcreteProceduralTerrain::UpdateMeshFirstVertices(int section) { //WORKS
	TArray<FVector> Vertices;
	TArray<int32> Triangles;
	TArray<FVector> Normals;
	TArray<FVector2D> UVs;
	TArray<FProcMeshTangent> Tangents;
	TArray<FColor> VertexColors;

	TArray<float> noise = GenerateNoiseArrayWithSimplex(frequency);
	FColor color = FColor(148, 62, 15, 1);
	for (int32 i = 0; i < chunkLineElements; i++) {
		for (int32 j = 0; j < chunkLineElements; j++) {
			//float z = USimplexNoiseLibrary::SimplexNoise2D(i * chunkLineElements, j) * 1000;
			Vertices.Add(FVector(i * voxelSize, j * voxelSize, noise[i * chunkLineElements + j]));
			VertexColors.Add(color);
		}
	}
	int32 tri_length = Vertices.Num() - chunkLineElements - 1;

	/*Triangles.Add(chunkLineElements); //(x + 1) + (y + 1)
	Triangles.Add(1); //(x + 1) + y
	Triangles.Add(0);
	Triangles.Add(0);
	Triangles.Add(chunkLineElements + 1); //x + (y + 1)
	Triangles.Add(chunkLineElements);*/

	for (int32 x = 0; x < chunkLineElements - 1; x ++) {
		for (int32 y = 0; y < chunkLineElements - 1; y++) {
			int32 realX = x * chunkLineElements;
			Triangles.Add(realX + chunkLineElements + y + 1); //(x + 1), (y + 1)
			Triangles.Add(realX + chunkLineElements + y); //(x + 1), y
			Triangles.Add(realX + y);//x, y
			Triangles.Add(realX + y);//x, y
			Triangles.Add(realX + y + 1); //x, (y + 1)
			Triangles.Add(realX + chunkLineElements + y + 1);//(x + 1), (y + 1)
		}
	}
	

	proceduralComponent->ClearAllMeshSections();
	proceduralComponent->CreateMeshSection(section, Vertices, Triangles, Normals, UVs, VertexColors, Tangents, true);
}

void AConcreteProceduralTerrain::CreateSingleSquareSection(int section) {
	TArray<FVector> Vertices;
	TArray<int32> Triangles;
	TArray<FVector> Normals;
	TArray<FVector2D> UVs;
	TArray<FProcMeshTangent> Tangents;
	TArray<FColor> VertexColors;

	/*Vertices.Add(FVector(chunkLineElements * voxelSize, chunkLineElements * voxelSize, voxelSize * 10));
	Vertices.Add(FVector((chunkLineElements + 1) * voxelSize, chunkLineElements * voxelSize, voxelSize * 10));
	Vertices.Add(FVector((chunkLineElements + 1) * voxelSize, (chunkLineElements + 1) * voxelSize, voxelSize * 10));
	Vertices.Add(FVector(chunkLineElements * voxelSize, (chunkLineElements + 1)  * voxelSize, voxelSize * 10));

	Triangles.Add(2);
	Triangles.Add(1);
	Triangles.Add(0);
	Triangles.Add(0);
	Triangles.Add(3);
	Triangles.Add(2);

	FColor color = FColor(255, 255, 255, 1);
	VertexColors.Add(color);
	VertexColors.Add(color);
	VertexColors.Add(color);
	VertexColors.Add(color);*/
	int32 z = 0;
	for (int32 x = 0; x < chunkLineElements; x++) {
		for (int32 y = 0; y < chunkLineElements; y++) {
			CreateSingleSquare(x, y, z, &Vertices, &Triangles, &Normals, &UVs, &Tangents, &VertexColors);
			z++;
		}
	}

	proceduralComponent->CreateMeshSection(section, Vertices, Triangles, Normals, UVs, VertexColors, Tangents, true);
}

void AConcreteProceduralTerrain::CreateSingleSquare(int32 x, int32 y, int32 z, TArray<FVector> * Vertices, TArray<int32> * Triangles, TArray<FVector> * Normals, TArray<FVector2D> * UVs, TArray<FProcMeshTangent> * Tangents, TArray<FColor> * VertexColors) {
	Vertices->Add(FVector(1, 1, 1));

	int32 verticesLength = Vertices->Num();
	Vertices->Add(FVector(x * voxelSize, y * voxelSize, voxelSize * z));
	Vertices->Add(FVector((x + 1) * voxelSize, y * voxelSize, voxelSize * z));
	Vertices->Add(FVector((x + 1) * voxelSize, (y + 1) * voxelSize, voxelSize * z));
	Vertices->Add(FVector(x * voxelSize, (y + 1)  * voxelSize, voxelSize * z));

	Triangles->Add(verticesLength + 2);
	Triangles->Add(verticesLength + 1);
	Triangles->Add(verticesLength);
	Triangles->Add(verticesLength);
	Triangles->Add(verticesLength + 3);
	Triangles->Add(verticesLength + 2);

	FColor color = FColor(255, 255, 255, 1);
	VertexColors->Add(color);
	VertexColors->Add(color);
	VertexColors->Add(color);
	VertexColors->Add(color);

}