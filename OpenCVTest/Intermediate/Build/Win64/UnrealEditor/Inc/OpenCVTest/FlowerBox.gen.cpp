// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OpenCVTest/Public/FlowerBox.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFlowerBox() {}
// Cross Module References
	OPENCVTEST_API UClass* Z_Construct_UClass_AFlowerBox_NoRegister();
	OPENCVTEST_API UClass* Z_Construct_UClass_AFlowerBox();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_OpenCVTest();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(AFlowerBox::execSpawnActorScheduled)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SpawnActorScheduled();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AFlowerBox::execSpawnNotify)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->SpawnNotify();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AFlowerBox::execSpawnActor)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->SpawnActor();
		P_NATIVE_END;
	}
	void AFlowerBox::StaticRegisterNativesAFlowerBox()
	{
		UClass* Class = AFlowerBox::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "SpawnActor", &AFlowerBox::execSpawnActor },
			{ "SpawnActorScheduled", &AFlowerBox::execSpawnActorScheduled },
			{ "SpawnNotify", &AFlowerBox::execSpawnNotify },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AFlowerBox_SpawnActor_Statics
	{
		struct FlowerBox_eventSpawnActor_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AFlowerBox_SpawnActor_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((FlowerBox_eventSpawnActor_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AFlowerBox_SpawnActor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FlowerBox_eventSpawnActor_Parms), &Z_Construct_UFunction_AFlowerBox_SpawnActor_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AFlowerBox_SpawnActor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFlowerBox_SpawnActor_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFlowerBox_SpawnActor_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/FlowerBox.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFlowerBox_SpawnActor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFlowerBox, nullptr, "SpawnActor", nullptr, nullptr, sizeof(Z_Construct_UFunction_AFlowerBox_SpawnActor_Statics::FlowerBox_eventSpawnActor_Parms), Z_Construct_UFunction_AFlowerBox_SpawnActor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AFlowerBox_SpawnActor_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AFlowerBox_SpawnActor_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AFlowerBox_SpawnActor_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AFlowerBox_SpawnActor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFlowerBox_SpawnActor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AFlowerBox_SpawnActorScheduled_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFlowerBox_SpawnActorScheduled_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/FlowerBox.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFlowerBox_SpawnActorScheduled_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFlowerBox, nullptr, "SpawnActorScheduled", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AFlowerBox_SpawnActorScheduled_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AFlowerBox_SpawnActorScheduled_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AFlowerBox_SpawnActorScheduled()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFlowerBox_SpawnActorScheduled_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AFlowerBox_SpawnNotify_Statics
	{
		struct FlowerBox_eventSpawnNotify_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AFlowerBox_SpawnNotify_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((FlowerBox_eventSpawnNotify_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AFlowerBox_SpawnNotify_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FlowerBox_eventSpawnNotify_Parms), &Z_Construct_UFunction_AFlowerBox_SpawnNotify_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AFlowerBox_SpawnNotify_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFlowerBox_SpawnNotify_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFlowerBox_SpawnNotify_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/FlowerBox.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFlowerBox_SpawnNotify_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFlowerBox, nullptr, "SpawnNotify", nullptr, nullptr, sizeof(Z_Construct_UFunction_AFlowerBox_SpawnNotify_Statics::FlowerBox_eventSpawnNotify_Parms), Z_Construct_UFunction_AFlowerBox_SpawnNotify_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AFlowerBox_SpawnNotify_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AFlowerBox_SpawnNotify_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AFlowerBox_SpawnNotify_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AFlowerBox_SpawnNotify()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFlowerBox_SpawnNotify_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AFlowerBox);
	UClass* Z_Construct_UClass_AFlowerBox_NoRegister()
	{
		return AFlowerBox::StaticClass();
	}
	struct Z_Construct_UClass_AFlowerBox_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FlowerToBeSpawned_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_FlowerToBeSpawned;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NotifyToBeSpawned_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_NotifyToBeSpawned;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ShouldSpawn_MetaData[];
#endif
		static void NewProp_ShouldSpawn_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ShouldSpawn;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SpawnTime_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_SpawnTime;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RandomTime_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_RandomTime;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SpawnBox_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SpawnBox;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFlowerBox_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_OpenCVTest,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AFlowerBox_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AFlowerBox_SpawnActor, "SpawnActor" }, // 1959964404
		{ &Z_Construct_UFunction_AFlowerBox_SpawnActorScheduled, "SpawnActorScheduled" }, // 2366128560
		{ &Z_Construct_UFunction_AFlowerBox_SpawnNotify, "SpawnNotify" }, // 417122157
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFlowerBox_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "FlowerBox.h" },
		{ "ModuleRelativePath", "Public/FlowerBox.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFlowerBox_Statics::NewProp_FlowerToBeSpawned_MetaData[] = {
		{ "Category", "FlowerBox" },
		{ "Comment", "//Actor class to spawn\n" },
		{ "ModuleRelativePath", "Public/FlowerBox.h" },
		{ "ToolTip", "Actor class to spawn" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AFlowerBox_Statics::NewProp_FlowerToBeSpawned = { "FlowerToBeSpawned", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFlowerBox, FlowerToBeSpawned), Z_Construct_UClass_AActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AFlowerBox_Statics::NewProp_FlowerToBeSpawned_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFlowerBox_Statics::NewProp_FlowerToBeSpawned_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFlowerBox_Statics::NewProp_NotifyToBeSpawned_MetaData[] = {
		{ "Category", "FlowerBox" },
		{ "ModuleRelativePath", "Public/FlowerBox.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AFlowerBox_Statics::NewProp_NotifyToBeSpawned = { "NotifyToBeSpawned", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFlowerBox, NotifyToBeSpawned), Z_Construct_UClass_AActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AFlowerBox_Statics::NewProp_NotifyToBeSpawned_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFlowerBox_Statics::NewProp_NotifyToBeSpawned_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFlowerBox_Statics::NewProp_ShouldSpawn_MetaData[] = {
		{ "Category", "FlowerBox" },
		{ "ModuleRelativePath", "Public/FlowerBox.h" },
	};
#endif
	void Z_Construct_UClass_AFlowerBox_Statics::NewProp_ShouldSpawn_SetBit(void* Obj)
	{
		((AFlowerBox*)Obj)->ShouldSpawn = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AFlowerBox_Statics::NewProp_ShouldSpawn = { "ShouldSpawn", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AFlowerBox), &Z_Construct_UClass_AFlowerBox_Statics::NewProp_ShouldSpawn_SetBit, METADATA_PARAMS(Z_Construct_UClass_AFlowerBox_Statics::NewProp_ShouldSpawn_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFlowerBox_Statics::NewProp_ShouldSpawn_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFlowerBox_Statics::NewProp_SpawnTime_MetaData[] = {
		{ "Category", "FlowerBox" },
		{ "ModuleRelativePath", "Public/FlowerBox.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFlowerBox_Statics::NewProp_SpawnTime = { "SpawnTime", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFlowerBox, SpawnTime), METADATA_PARAMS(Z_Construct_UClass_AFlowerBox_Statics::NewProp_SpawnTime_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFlowerBox_Statics::NewProp_SpawnTime_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFlowerBox_Statics::NewProp_RandomTime_MetaData[] = {
		{ "Category", "FlowerBox" },
		{ "ModuleRelativePath", "Public/FlowerBox.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFlowerBox_Statics::NewProp_RandomTime = { "RandomTime", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFlowerBox, RandomTime), METADATA_PARAMS(Z_Construct_UClass_AFlowerBox_Statics::NewProp_RandomTime_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFlowerBox_Statics::NewProp_RandomTime_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFlowerBox_Statics::NewProp_SpawnBox_MetaData[] = {
		{ "Category", "FlowerBox" },
		{ "Comment", "//Box for spawning actors\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/FlowerBox.h" },
		{ "ToolTip", "Box for spawning actors" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFlowerBox_Statics::NewProp_SpawnBox = { "SpawnBox", nullptr, (EPropertyFlags)0x0040000000090009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFlowerBox, SpawnBox), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFlowerBox_Statics::NewProp_SpawnBox_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFlowerBox_Statics::NewProp_SpawnBox_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFlowerBox_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFlowerBox_Statics::NewProp_FlowerToBeSpawned,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFlowerBox_Statics::NewProp_NotifyToBeSpawned,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFlowerBox_Statics::NewProp_ShouldSpawn,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFlowerBox_Statics::NewProp_SpawnTime,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFlowerBox_Statics::NewProp_RandomTime,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFlowerBox_Statics::NewProp_SpawnBox,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFlowerBox_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFlowerBox>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AFlowerBox_Statics::ClassParams = {
		&AFlowerBox::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AFlowerBox_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AFlowerBox_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AFlowerBox_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AFlowerBox_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AFlowerBox()
	{
		if (!Z_Registration_Info_UClass_AFlowerBox.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AFlowerBox.OuterSingleton, Z_Construct_UClass_AFlowerBox_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AFlowerBox.OuterSingleton;
	}
	template<> OPENCVTEST_API UClass* StaticClass<AFlowerBox>()
	{
		return AFlowerBox::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFlowerBox);
	struct Z_CompiledInDeferFile_FID_OpenCVTest_Source_OpenCVTest_Public_FlowerBox_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OpenCVTest_Source_OpenCVTest_Public_FlowerBox_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AFlowerBox, AFlowerBox::StaticClass, TEXT("AFlowerBox"), &Z_Registration_Info_UClass_AFlowerBox, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFlowerBox), 3677358875U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OpenCVTest_Source_OpenCVTest_Public_FlowerBox_h_2169287202(TEXT("/Script/OpenCVTest"),
		Z_CompiledInDeferFile_FID_OpenCVTest_Source_OpenCVTest_Public_FlowerBox_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OpenCVTest_Source_OpenCVTest_Public_FlowerBox_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
