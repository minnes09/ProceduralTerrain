// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "ProceduralGame.h"
#include "ConcreteProceduralTerrain.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeConcreteProceduralTerrain() {}
// Cross Module References
	PROCEDURALGAME_API UClass* Z_Construct_UClass_AConcreteProceduralTerrain_NoRegister();
	PROCEDURALGAME_API UClass* Z_Construct_UClass_AConcreteProceduralTerrain();
	PROCEDURALGAME_API UClass* Z_Construct_UClass_AProceduralTerrain();
	UPackage* Z_Construct_UPackage__Script_ProceduralGame();
// End Cross Module References
	void AConcreteProceduralTerrain::StaticRegisterNativesAConcreteProceduralTerrain()
	{
	}
	UClass* Z_Construct_UClass_AConcreteProceduralTerrain_NoRegister()
	{
		return AConcreteProceduralTerrain::StaticClass();
	}
	UClass* Z_Construct_UClass_AConcreteProceduralTerrain()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AProceduralTerrain();
			Z_Construct_UPackage__Script_ProceduralGame();
			OuterClass = AConcreteProceduralTerrain::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20900080u;


				static TCppClassTypeInfo<TCppClassTypeTraits<AConcreteProceduralTerrain> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("ConcreteProceduralTerrain.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("ConcreteProceduralTerrain.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(AConcreteProceduralTerrain, 1791928593);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AConcreteProceduralTerrain(Z_Construct_UClass_AConcreteProceduralTerrain, &AConcreteProceduralTerrain::StaticClass, TEXT("/Script/ProceduralGame"), TEXT("AConcreteProceduralTerrain"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AConcreteProceduralTerrain);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
