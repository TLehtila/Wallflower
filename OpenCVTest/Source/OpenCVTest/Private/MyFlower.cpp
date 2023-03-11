// Fill out your copyright notice in the Description page of Project Settings.


#include "MyFlower.h"

// Sets default values
AMyFlower::AMyFlower()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	//RootComponent = StaticMesh;

	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	RootComponent = SkeletalMesh;
}

// Called when the game starts or when spawned
void AMyFlower::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyFlower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AMyFlower::SpawnActor() {
	bool SpawnedActor = false;
	if (true) {
	}

	return SpawnedActor;
}