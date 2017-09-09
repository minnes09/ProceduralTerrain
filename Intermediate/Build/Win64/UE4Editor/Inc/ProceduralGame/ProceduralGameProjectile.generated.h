// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FVector;
struct FHitResult;
#ifdef PROCEDURALGAME_ProceduralGameProjectile_generated_h
#error "ProceduralGameProjectile.generated.h already included, missing '#pragma once' in ProceduralGameProjectile.h"
#endif
#define PROCEDURALGAME_ProceduralGameProjectile_generated_h

#define ProceduralGame_4_17_Source_ProceduralGame_ProceduralGameProjectile_h_9_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OnHit(Z_Param_HitComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalImpulse,Z_Param_Out_Hit); \
		P_NATIVE_END; \
	}


#define ProceduralGame_4_17_Source_ProceduralGame_ProceduralGameProjectile_h_9_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OnHit(Z_Param_HitComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalImpulse,Z_Param_Out_Hit); \
		P_NATIVE_END; \
	}


#define ProceduralGame_4_17_Source_ProceduralGame_ProceduralGameProjectile_h_9_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAProceduralGameProjectile(); \
	friend PROCEDURALGAME_API class UClass* Z_Construct_UClass_AProceduralGameProjectile(); \
public: \
	DECLARE_CLASS(AProceduralGameProjectile, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/ProceduralGame"), NO_API) \
	DECLARE_SERIALIZER(AProceduralGameProjectile) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define ProceduralGame_4_17_Source_ProceduralGame_ProceduralGameProjectile_h_9_INCLASS \
private: \
	static void StaticRegisterNativesAProceduralGameProjectile(); \
	friend PROCEDURALGAME_API class UClass* Z_Construct_UClass_AProceduralGameProjectile(); \
public: \
	DECLARE_CLASS(AProceduralGameProjectile, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/ProceduralGame"), NO_API) \
	DECLARE_SERIALIZER(AProceduralGameProjectile) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define ProceduralGame_4_17_Source_ProceduralGame_ProceduralGameProjectile_h_9_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AProceduralGameProjectile(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AProceduralGameProjectile) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProceduralGameProjectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProceduralGameProjectile); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AProceduralGameProjectile(AProceduralGameProjectile&&); \
	NO_API AProceduralGameProjectile(const AProceduralGameProjectile&); \
public:


#define ProceduralGame_4_17_Source_ProceduralGame_ProceduralGameProjectile_h_9_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AProceduralGameProjectile(AProceduralGameProjectile&&); \
	NO_API AProceduralGameProjectile(const AProceduralGameProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProceduralGameProjectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProceduralGameProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AProceduralGameProjectile)


#define ProceduralGame_4_17_Source_ProceduralGame_ProceduralGameProjectile_h_9_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CollisionComp() { return STRUCT_OFFSET(AProceduralGameProjectile, CollisionComp); } \
	FORCEINLINE static uint32 __PPO__ProjectileMovement() { return STRUCT_OFFSET(AProceduralGameProjectile, ProjectileMovement); }


#define ProceduralGame_4_17_Source_ProceduralGame_ProceduralGameProjectile_h_6_PROLOG
#define ProceduralGame_4_17_Source_ProceduralGame_ProceduralGameProjectile_h_9_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ProceduralGame_4_17_Source_ProceduralGame_ProceduralGameProjectile_h_9_PRIVATE_PROPERTY_OFFSET \
	ProceduralGame_4_17_Source_ProceduralGame_ProceduralGameProjectile_h_9_RPC_WRAPPERS \
	ProceduralGame_4_17_Source_ProceduralGame_ProceduralGameProjectile_h_9_INCLASS \
	ProceduralGame_4_17_Source_ProceduralGame_ProceduralGameProjectile_h_9_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ProceduralGame_4_17_Source_ProceduralGame_ProceduralGameProjectile_h_9_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ProceduralGame_4_17_Source_ProceduralGame_ProceduralGameProjectile_h_9_PRIVATE_PROPERTY_OFFSET \
	ProceduralGame_4_17_Source_ProceduralGame_ProceduralGameProjectile_h_9_RPC_WRAPPERS_NO_PURE_DECLS \
	ProceduralGame_4_17_Source_ProceduralGame_ProceduralGameProjectile_h_9_INCLASS_NO_PURE_DECLS \
	ProceduralGame_4_17_Source_ProceduralGame_ProceduralGameProjectile_h_9_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ProceduralGame_4_17_Source_ProceduralGame_ProceduralGameProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
