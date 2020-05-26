// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Temple_Escape/Temple_EscapeGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTemple_EscapeGameModeBase() {}
// Cross Module References
	TEMPLE_ESCAPE_API UClass* Z_Construct_UClass_ATemple_EscapeGameModeBase_NoRegister();
	TEMPLE_ESCAPE_API UClass* Z_Construct_UClass_ATemple_EscapeGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_Temple_Escape();
// End Cross Module References
	void ATemple_EscapeGameModeBase::StaticRegisterNativesATemple_EscapeGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_ATemple_EscapeGameModeBase_NoRegister()
	{
		return ATemple_EscapeGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_ATemple_EscapeGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATemple_EscapeGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_Temple_Escape,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATemple_EscapeGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "Temple_EscapeGameModeBase.h" },
		{ "ModuleRelativePath", "Temple_EscapeGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATemple_EscapeGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATemple_EscapeGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ATemple_EscapeGameModeBase_Statics::ClassParams = {
		&ATemple_EscapeGameModeBase::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002A8u,
		METADATA_PARAMS(Z_Construct_UClass_ATemple_EscapeGameModeBase_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ATemple_EscapeGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATemple_EscapeGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ATemple_EscapeGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ATemple_EscapeGameModeBase, 2834771363);
	template<> TEMPLE_ESCAPE_API UClass* StaticClass<ATemple_EscapeGameModeBase>()
	{
		return ATemple_EscapeGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ATemple_EscapeGameModeBase(Z_Construct_UClass_ATemple_EscapeGameModeBase, &ATemple_EscapeGameModeBase::StaticClass, TEXT("/Script/Temple_Escape"), TEXT("ATemple_EscapeGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATemple_EscapeGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
