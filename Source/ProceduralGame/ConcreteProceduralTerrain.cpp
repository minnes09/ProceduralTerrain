// Fill out your copyright notice in the Description page of Project Settings.

#include "ProceduralGame.h"
#include "SimplexNoiseLibrary.h"
#include "Engine.h"
#include "ConcreteProceduralTerrain.h"

AConcreteProceduralTerrain::AConcreteProceduralTerrain() 
{

	proceduralComponent = CreateDefaultSubobject<UProceduralMeshComponent>("ProceduralMeshComponent");
	/*static ConstructorHelpers::FObjectFinder<UMaterial> MaterialOb(TEXT("Material'/Game/Blueprints/ChunkTerrain.ChunkTerrain'"));
	Material = MaterialOb.Object;*/
	colors.Add(FColor(255, 23, 7));
	colors.Add(FColor(141, 182, 7));
	colors.Add(FColor(0, 132, 255));
	colors.Add(FColor(255, 250, 250));
}

void AConcreteProceduralTerrain::OnConstruction(const FTransform & Transform)
{
	/*int x = chunkLineElements - 1;
	int n = FMath::Log2(x);
	while ( n % FMath::FloorToInt(n) != 0) {
		chunkLineElements++;
	}*/
	chunkZElements = 80;
	chunkTotalElements = chunkLineElements * chunkLineElements * chunkZElements;
	chunkLineElementsP2 = chunkLineElements * chunkLineElements;
	voxelSizeHalf = voxelSize / 2;

	noise.Init(0, chunkLineElementsP2);
	FString string = "Voxel: " + FString::FromInt(chunkXIndex) + "_" + FString::FromInt(chunkYIndex);
	FName name = FName(*string);
	
	RootComponent = proceduralComponent;
	RootComponent->SetWorldTransform(Transform); //set position of root component
												 //worldLocation = RootComponent->GetComponentLocation();
	Super::Super::OnConstruction(Transform);

	//GenerateChunck();
	UpdateMesh();
}
void AConcreteProceduralTerrain::UpdateMesh() {
	
	TArray<FVector> Vertices;
	TArray<int32> Triangles;
	TArray<FVector> Normals;
	TArray<FVector2D> UVs;
	TArray<FProcMeshTangent> Tangents;
	TArray<FColor> VertexColors;

	//noise = GenerateSquareNoiseArray();
	noise = GeneratePerlinNoiseArray();
	for (int32 i = 0; i < chunkLineElements; i++) {
		for (int32 j = 0; j < chunkLineElements; j++) {
			//float z = USimplexNoiseLibrary::SimplexNoise2D(i * chunkLineElements, j) * 1000;
			float noiseHeight = noise[i * chunkLineElements + j];
			Vertices.Add(FVector(i * voxelSize, j * voxelSize, noiseHeight));
			VertexColors.Add(ComputeVertexColor(noiseHeight));
		}
	}
	int32 tri_length = Vertices.Num() - chunkLineElements - 1;

	//loop for triangles, I arrive at length -1 so I skip the borders
	for (int32 x = 0; x < chunkLineElements - 1; x++) {
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

	//proceduralComponent->ClearAllMeshSections();
	proceduralComponent->CreateMeshSection(0, Vertices, Triangles, Normals, UVs, VertexColors, Tangents, true);
	//proceduralComponent->CreateMeshSection_LinearColor(0, Vertices, Triangles, Normals, UVs, VertexColors, Tangents, true);
	proceduralComponent->SetMaterial(0, Material);
	//UpdateMeshFirstVertices(0);
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
				VertexColors.Add(FColor::White);
				VertexColors.Add(FColor::Blue);
				VertexColors.Add(FColor::Emerald);
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

	noise = GenerateNoiseArray();
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
	int32 iNoise = (int32)fNoise;
	return iNoise;
}

int32 AConcreteProceduralTerrain::GenerateNoise(int32 x, int32 y, int32 z) {

	float noiseX = (randomSeed % 64 ) * worldLocation.X * chunkXIndex * xMult;
	float noiseY = (randomSeed % 64) * worldLocation.Y * chunkYIndex * yMult;

	float fNoise = FMath::Cos(x) * FMath::Cos(y) + x*y*z*chunkTotalElements;
	fNoise = fNoise + noiseX + noiseY;
	int32 iNoise = (int32)fNoise;
	return iNoise;
}

TArray<float> AConcreteProceduralTerrain::GeneratePerlinNoiseArray() {
	noise.Init(0, chunkLineElementsP2);
	FRandomStream RngStream = FRandomStream::FRandomStream(randomSeed);
	TArray<FVector2D> octaveOffset;
	for (int i = 0; i < iterations; i++) {
		float offsetX = RngStream.FRandRange(-10000, 10000);
		float offsetY = RngStream.FRandRange(-10000, 10000);
		octaveOffset.Add(FVector2D(offsetX, offsetY));
	}
	
	for (int32 x = 0; x < chunkLineElements; x++)
	{
		for (int32 y = 0; y < chunkLineElements; y++)
		{
			int index = x * chunkLineElements + y;

			float frequency = lacunarity;
			float amplitude = 1;
			float noiseHeight = 0;

			for (int itr = 0; itr < iterations; itr++) {
				float sampleX = (chunkXIndex * chunkLineElements + x) / freq * frequency + octaveOffset[itr].X;
				float sampleY = (chunkYIndex * chunkLineElements + y) / freq * frequency + octaveOffset[itr].Y;
				float perlinValue = USimplexNoiseLibrary::SimplexNoise2D(sampleX,sampleY) * 2 - 1; //range (-1,1)
				noiseHeight += perlinValue * amplitude;

				amplitude *= persistence;
				frequency *= lacunarity;
			}
			noise[index] = noiseHeight * maxAltitude;
		}
	}
	return noise;
}
/*
frequency must be very low
*/
TArray<float> AConcreteProceduralTerrain::GenerateNoiseArrayWithSimplex(float f) {
	noise.SetNumZeroed(chunkLineElementsP2);
	for (int32 x = 0; x < chunkLineElements; x++)
	{
		for (int32 y = 0; y < chunkLineElements; y++)
		{
			int index = x + chunkLineElements * y;
			float Xval = x * voxelSize * f;
			float Yval = y * voxelSize * f;
			noise[index] = CalculatePointNoise(Xval, Yval, iterations);
		}
	}
	return noise;
}
TArray<float> AConcreteProceduralTerrain::GenerateNoiseArrayRecursive()
{
	noise.SetNumZeroed(chunkLineElementsP2);
	GenerateNoiseArrayRecursive(iterations);
	return noise;
}

void AConcreteProceduralTerrain::GenerateNoiseArrayRecursive(float f)
{
	if(f > 2)
		GenerateNoiseArrayRecursive(f / 2);
	for (int x = 0; x < chunkLineElements; x++) {
		for (int y = 0; y < chunkLineElements; x++) {
			int index = x * chunkLineElements + y;
			noise[index] += USimplexNoiseLibrary::SimplexNoise2D(x, y) / f;
		}
	}
}


float AConcreteProceduralTerrain::CalculatePointNoise(float x, float y, int32 itr)
{
	float pointNoise = 0;
	for (int32 i = 0; i < itr; i++) {
		int32 power = FMath::Pow(2, i);
		pointNoise += ( FMath::Pow(2, -i) * USimplexNoiseLibrary::SimplexNoise2D(power * x, power * y) * maxAltitude );
	}
	return pointNoise;
}
int AConcreteProceduralTerrain::GetGridPosition(int x, int y)
{
	return x + chunkLineElements * y;
}
TArray<float> AConcreteProceduralTerrain::GenerateSquareNoiseArray()
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

void AConcreteProceduralTerrain::InitDiamondSquare(int startX, int startY, int endX,int endY)
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
	noise[endX + chunkLineElements * endY] = ((x2 + y2) * (randomSeed % maxAltitude)) + maxAltitude + PseudoRandomOffset(x2, y2);*/
}


TArray<float> AConcreteProceduralTerrain::DiamondSquare(int x, int y, int half, int range)
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
}

TArray<float> AConcreteProceduralTerrain::Square(int step)
{

	return TArray<float>();
}

TArray<float> AConcreteProceduralTerrain::Diamond(int step)
{
	return TArray<float>();
}

float AConcreteProceduralTerrain::PseudoRandomOffset(float x, float y)
{
	float cosX = FMath::Cos(x + y);
	float sinX = FMath::Sin(x + y);
	float cosY = FMath::Cos(randomSeed);
	return (cosX + sinX + cosY);
}

FColor AConcreteProceduralTerrain::ComputeVertexColor(float h)
{
	//int32 c = FMath::Lerp(0, maxAltitude, h);
	int32 biomeDivisor = maxAltitude / colors.Num();
	for (int32 i = 1; i < colors.Num(); ++i) {
		if (h <= i * biomeDivisor) return colors[i - 1];
	}
	return FColor::Magenta;
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

	//noise = GenerateSquareNoiseArray();
	noise = GeneratePerlinNoiseArray();
	FColor color = FColor::Blue;
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

	for (int32 x = 0; x < chunkLineElements; x ++) {
		for (int32 y = 0; y < chunkLineElements; y++) {
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
	//proceduralComponent->SetMaterial(0, Material);
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

	Triangles->Add(2);
	Triangles->Add(1);
	Triangles->Add(0);
	Triangles->Add(0);
	Triangles->Add(3);
	Triangles->Add(2);

	FColor color = FColor(255, 255, 255, 1);
	VertexColors->Add(color);
	VertexColors->Add(color);
	VertexColors->Add(color);
	VertexColors->Add(color);

}