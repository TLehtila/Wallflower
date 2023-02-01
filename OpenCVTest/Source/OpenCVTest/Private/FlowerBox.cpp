// Fill out your copyright notice in the Description page of Project Settings.


#include "FlowerBox.h"


// Sets default values
AFlowerBox::AFlowerBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SpawnBox = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnBox"));
	RootComponent = SpawnBox;
}

//https://www.youtube.com/watch?v=pNpHU2exYI8

// Called when the game starts or when spawned
void AFlowerBox::BeginPlay()
{
	Super::BeginPlay();

	if (ShouldSpawn) {
		ScheduleActorSpawn();
	}
	
}

void AFlowerBox::EndPlay(const EEndPlayReason::Type EndPlayReason) {
	Super::EndPlay(EndPlayReason);
	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
}

bool AFlowerBox::SpawnActor() {
	bool SpawnedActor = false;
	if (true) {
		FBoxSphereBounds BoxBounds = SpawnBox->CalcBounds(GetActorTransform());

		FVector SpawnLocation = BoxBounds.Origin;
		FRotator SpawnRotation = { 0, -90, 0 };
		SpawnLocation.X += -BoxBounds.BoxExtent.X + 2 * BoxBounds.BoxExtent.X * FMath::FRand();
		SpawnLocation.Y += -BoxBounds.BoxExtent.Y + 2 * BoxBounds.BoxExtent.Y * FMath::FRand();
		SpawnLocation.Z += -BoxBounds.BoxExtent.Z + 2 * BoxBounds.BoxExtent.Z * FMath::FRand();

		SpawnedActor = GetWorld()->SpawnActor<AActor>(FlowerToBeSpawned, SpawnLocation, SpawnRotation) != nullptr;

		if (SpawnedActor) {
		}
	}

	return SpawnedActor;
}

void AFlowerBox::ScheduleActorSpawn() {
	float DeltaToNextSpawn = SpawnTime + (-RandomTime + 2 * RandomTime * FMath::FRand());

	GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &AFlowerBox::SpawnActorScheduled, DeltaToNextSpawn, false);
}


void AFlowerBox::SpawnActorScheduled() {
	if (SpawnActor()) {
		if (ShouldSpawn) {
			ScheduleActorSpawn();
		}
	}
	else {

	}
}

