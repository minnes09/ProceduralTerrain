// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "ProceduralGame.h"
#include "ProceduralTerrain.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeProceduralTerrain() {}
// Cross Module References
	PROCEDURALGAME_API UFunction* Z_Construct_UFunction_AProceduralTerrain_GenerateNoise();
	PROCEDURALGAME_API UClass* Z_Construct_UClass_AProceduralTerrain();
	PROCEDURALGAME_API UClass* Z_Construct_UClass_AProceduralTerrain_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_ProceduralGame();
	PROCEDURALMESHCOMPONENT_API UClass* Z_Construct_UClass_UProceduralMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
// End Cross Module References
	void AProceduralTerrain::StaticRegisterNativesAProceduralTerrain()
	{
		UClass* Class = AProceduralTerrain::StaticClass();
		static const TNameNativePtrPair<ANSICHAR> AnsiFuncs[] = {
			{ "GenerateNoise", (Native)&AProceduralTerrain::execGenerateNoise },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, AnsiFuncs, ARRAY_COUNT(AnsiFuncs));
	}
	UFunction* Z_Construct_UFunction_AProceduralTerrain_GenerateNoise()
	{
		struct ProceduralTerrain_eventGenerateNoise_Parms
		{
			int32 index;
			int32 ReturnValue;
		};
		UObject* Outer = Z_Construct_UClass_AProceduralTerrain();
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("GenerateNoise"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), nullptr, (EFunctionFlags)0x04020400, 65535, sizeof(ProceduralTerrain_eventGenerateNoise_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UUnsizedIntProperty(CPP_PROPERTY_BASE(ReturnValue, ProceduralTerrain_eventGenerateNoise_Parms), 0x0010000000000580);
			UProperty* NewProp_index = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("index"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(index, ProceduralTerrain_eventGenerateNoise_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Procedural"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("ProceduralTerrain.h"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AProceduralTerrain_NoRegister()
	{
		return AProceduralTerrain::StaticClass();
	}
	UClass* Z_Construct_UClass_AProceduralTerrain()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_ProceduralGame();
			OuterClass = AProceduralTerrain::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20900080u;

				OuterClass->LinkChild(Z_Construct_UFunction_AProceduralTerrain_GenerateNoise());

				UProperty* NewProp_proceduralComponent = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("proceduralComponent"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(proceduralComponent, AProceduralTerrain), 0x0010000000080008, Z_Construct_UClass_UProceduralMeshComponent_NoRegister());
				UProperty* NewProp_chunkFields = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("chunkFields"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(chunkFields, AProceduralTerrain), 0x0010000000000000);
				UProperty* NewProp_chunkFields_Inner = new(EC_InternalUseOnlyConstructor, NewProp_chunkFields, TEXT("chunkFields"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000);
				UProperty* NewProp_voxelSizeHalf = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("voxelSizeHalf"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(voxelSizeHalf, AProceduralTerrain), 0x0010000000000000);
				UProperty* NewProp_chunkLineElementsP2 = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("chunkLineElementsP2"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(chunkLineElementsP2, AProceduralTerrain), 0x0010000000000000);
				UProperty* NewProp_chunkZElements = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("chunkZElements"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(chunkZElements, AProceduralTerrain), 0x0010000000000000);
				UProperty* NewProp_chunkTotalElements = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("chunkTotalElements"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(chunkTotalElements, AProceduralTerrain), 0x0010000000000000);
				UProperty* NewProp_freq = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("freq"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(freq, AProceduralTerrain), 0x0010000000000005);
				UProperty* NewProp_weight = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("weight"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(weight, AProceduralTerrain), 0x0010000000000005);
				UProperty* NewProp_zMult = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("zMult"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(zMult, AProceduralTerrain), 0x0010000000000005);
				UProperty* NewProp_yMult = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("yMult"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(yMult, AProceduralTerrain), 0x0010000000000005);
				UProperty* NewProp_xMult = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("xMult"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(xMult, AProceduralTerrain), 0x0010000000000005);
				UProperty* NewProp_chunkYIndex = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("chunkYIndex"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(chunkYIndex, AProceduralTerrain), 0x0011000000000005);
				UProperty* NewProp_chunkXIndex = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("chunkXIndex"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(chunkXIndex, AProceduralTerrain), 0x0011000000000005);
				UProperty* NewProp_chunkLineElements = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("chunkLineElements"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(chunkLineElements, AProceduralTerrain), 0x0011000000000005);
				UProperty* NewProp_height = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("height"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(height, AProceduralTerrain), 0x0010000000000005);
				UProperty* NewProp_maxAltitude = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("maxAltitude"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(maxAltitude, AProceduralTerrain), 0x0011000000000005);
				UProperty* NewProp_voxelSize = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("voxelSize"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(voxelSize, AProceduralTerrain), 0x0011000000000005);
				UProperty* NewProp_randomSeed = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("randomSeed"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(randomSeed, AProceduralTerrain), 0x0011000000000005);
				UProperty* NewProp_Materials = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Materials"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(Materials, AProceduralTerrain), 0x0010000000000001);
				UProperty* NewProp_Materials_Inner = new(EC_InternalUseOnlyConstructor, NewProp_Materials, TEXT("Materials"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000, Z_Construct_UClass_UMaterialInterface_NoRegister());
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AProceduralTerrain_GenerateNoise(), "GenerateNoise"); // 849714232
				static TCppClassTypeInfo<TCppClassTypeTraits<AProceduralTerrain> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("ProceduralTerrain.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("ProceduralTerrain.h"));
				MetaData->SetValue(NewProp_proceduralComponent, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_proceduralComponent, TEXT("ModuleRelativePath"), TEXT("ProceduralTerrain.h"));
				MetaData->SetValue(NewProp_chunkFields, TEXT("ModuleRelativePath"), TEXT("ProceduralTerrain.h"));
				MetaData->SetValue(NewProp_voxelSizeHalf, TEXT("ModuleRelativePath"), TEXT("ProceduralTerrain.h"));
				MetaData->SetValue(NewProp_chunkLineElementsP2, TEXT("ModuleRelativePath"), TEXT("ProceduralTerrain.h"));
				MetaData->SetValue(NewProp_chunkZElements, TEXT("ModuleRelativePath"), TEXT("ProceduralTerrain.h"));
				MetaData->SetValue(NewProp_chunkTotalElements, TEXT("ModuleRelativePath"), TEXT("ProceduralTerrain.h"));
				MetaData->SetValue(NewProp_freq, TEXT("Category"), TEXT("Procedural"));
				MetaData->SetValue(NewProp_freq, TEXT("ModuleRelativePath"), TEXT("ProceduralTerrain.h"));
				MetaData->SetValue(NewProp_weight, TEXT("Category"), TEXT("Procedural"));
				MetaData->SetValue(NewProp_weight, TEXT("ClampMax"), TEXT("1.0"));
				MetaData->SetValue(NewProp_weight, TEXT("ClampMin"), TEXT("0.00000001"));
				MetaData->SetValue(NewProp_weight, TEXT("ModuleRelativePath"), TEXT("ProceduralTerrain.h"));
				MetaData->SetValue(NewProp_weight, TEXT("UIMax"), TEXT("1.0"));
				MetaData->SetValue(NewProp_weight, TEXT("UIMin"), TEXT("0.0001"));
				MetaData->SetValue(NewProp_zMult, TEXT("Category"), TEXT("Procedural"));
				MetaData->SetValue(NewProp_zMult, TEXT("ClampMax"), TEXT("1.0"));
				MetaData->SetValue(NewProp_zMult, TEXT("ClampMin"), TEXT("0.00000001"));
				MetaData->SetValue(NewProp_zMult, TEXT("ModuleRelativePath"), TEXT("ProceduralTerrain.h"));
				MetaData->SetValue(NewProp_zMult, TEXT("UIMax"), TEXT("1.0"));
				MetaData->SetValue(NewProp_zMult, TEXT("UIMin"), TEXT("0.0001"));
				MetaData->SetValue(NewProp_yMult, TEXT("Category"), TEXT("Procedural"));
				MetaData->SetValue(NewProp_yMult, TEXT("ClampMax"), TEXT("1.0"));
				MetaData->SetValue(NewProp_yMult, TEXT("ClampMin"), TEXT("0.00000001"));
				MetaData->SetValue(NewProp_yMult, TEXT("ModuleRelativePath"), TEXT("ProceduralTerrain.h"));
				MetaData->SetValue(NewProp_yMult, TEXT("UIMax"), TEXT("1.0"));
				MetaData->SetValue(NewProp_yMult, TEXT("UIMin"), TEXT("0.0001"));
				MetaData->SetValue(NewProp_xMult, TEXT("Category"), TEXT("Procedural"));
				MetaData->SetValue(NewProp_xMult, TEXT("ModuleRelativePath"), TEXT("ProceduralTerrain.h"));
				MetaData->SetValue(NewProp_chunkYIndex, TEXT("Category"), TEXT("Procedural"));
				MetaData->SetValue(NewProp_chunkYIndex, TEXT("ExposeOnSpawn"), TEXT("TRUE"));
				MetaData->SetValue(NewProp_chunkYIndex, TEXT("ModuleRelativePath"), TEXT("ProceduralTerrain.h"));
				MetaData->SetValue(NewProp_chunkXIndex, TEXT("Category"), TEXT("Procedural"));
				MetaData->SetValue(NewProp_chunkXIndex, TEXT("ExposeOnSpawn"), TEXT("TRUE"));
				MetaData->SetValue(NewProp_chunkXIndex, TEXT("ModuleRelativePath"), TEXT("ProceduralTerrain.h"));
				MetaData->SetValue(NewProp_chunkXIndex, TEXT("ToolTip"), TEXT("must be multiple of 2"));
				MetaData->SetValue(NewProp_chunkLineElements, TEXT("Category"), TEXT("Procedural"));
				MetaData->SetValue(NewProp_chunkLineElements, TEXT("ExposeOnSpawn"), TEXT("TRUE"));
				MetaData->SetValue(NewProp_chunkLineElements, TEXT("ModuleRelativePath"), TEXT("ProceduralTerrain.h"));
				MetaData->SetValue(NewProp_height, TEXT("Category"), TEXT("Procedural"));
				MetaData->SetValue(NewProp_height, TEXT("ModuleRelativePath"), TEXT("ProceduralTerrain.h"));
				MetaData->SetValue(NewProp_maxAltitude, TEXT("Category"), TEXT("Procedural"));
				MetaData->SetValue(NewProp_maxAltitude, TEXT("ExposeOnSpawn"), TEXT("TRUE"));
				MetaData->SetValue(NewProp_maxAltitude, TEXT("ModuleRelativePath"), TEXT("ProceduralTerrain.h"));
				MetaData->SetValue(NewProp_voxelSize, TEXT("Category"), TEXT("Procedural"));
				MetaData->SetValue(NewProp_voxelSize, TEXT("ExposeOnSpawn"), TEXT("TRUE"));
				MetaData->SetValue(NewProp_voxelSize, TEXT("ModuleRelativePath"), TEXT("ProceduralTerrain.h"));
				MetaData->SetValue(NewProp_randomSeed, TEXT("Category"), TEXT("ProceduralTerrain"));
				MetaData->SetValue(NewProp_randomSeed, TEXT("ExposeOnSpawn"), TEXT("TRUE"));
				MetaData->SetValue(NewProp_randomSeed, TEXT("ModuleRelativePath"), TEXT("ProceduralTerrain.h"));
				MetaData->SetValue(NewProp_Materials, TEXT("Category"), TEXT("ProceduralTerrain"));
				MetaData->SetValue(NewProp_Materials, TEXT("ModuleRelativePath"), TEXT("ProceduralTerrain.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(AProceduralTerrain, 3620431352);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AProceduralTerrain(Z_Construct_UClass_AProceduralTerrain, &AProceduralTerrain::StaticClass, TEXT("/Script/ProceduralGame"), TEXT("AProceduralTerrain"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AProceduralTerrain);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
