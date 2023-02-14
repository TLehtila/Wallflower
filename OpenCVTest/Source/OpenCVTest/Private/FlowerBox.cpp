// Fill out your copyright notice in the Description page of Project Settings.


#include "FlowerBox.h"
#include <opencv2/core.hpp>
//
//#include <opencv2/imgcodecs.hpp>
//#include <opencv2/highgui.hpp>
//#include <opencv2/imgproc.hpp>
//#include <opencv2/videoio.hpp>
//#include <opencv2/video.hpp>


// Sets default values
AFlowerBox::AFlowerBox()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true; 

	//PrimaryActorTick.bStartWithTickEnabled = true;
	//PrimaryActorTick.bAllowTickOnDedicatedServer = true;
	//bAllowTickBeforeBeginPlay = true;

	//PrimaryActorTick.RegisterTickFunction(GetLevel());

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

	capOne.open(0);

	if (!capOne.isOpened()) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Failed to open videocapture"));
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Videocapture open??"));
	}


	//float screenWidth = 500;
	//float screenHeight = 500;

	//cv::Mat screenImg(screenWidth, screenHeight, CV_8UC3, cv::Scalar(0, 0, 0));

	//cv::Point2f corners[4] = { {10, 10}, {screenWidth - 10, 10}, {10, screenHeight - 10}, {screenWidth - 10, screenHeight - 10} };
	//for (int i = 0; i < 4; i++) {
	//    cv::circle(screenImg, corners[i], 50, cv::Scalar(255, 255, 255), cv::FILLED);
	//}

	////cv::namedWindow("window", 1);
	////setWindowProperty("window", WND_PROP_FULLSCREEN, WINDOW_FULLSCREEN);
	//cv::imshow("window", screenImg);


}

void AFlowerBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Tick tock"));
	//cv::Mat frameOne;
	//capOne.read(frameOne);

	//cv::imshow("camera", frameOne);

	

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

			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Spawned"));
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

