// Fill out your copyright notice in the Description page of Project Settings.


#include "MyNotifyClass.h"

// Sets default values
AMyNotifyClass::AMyNotifyClass()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	RootComponent = SkeletalMesh;

}

// Called when the game starts or when spawned
void AMyNotifyClass::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called when the game ends or when despawned
void AMyNotifyClass::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

}

void AMyNotifyClass::StartTheEnd(const EEndPlayReason::Type EndPlayReason) {
	EndPlay(EndPlayReason);
}

// Called every frame
void AMyNotifyClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

