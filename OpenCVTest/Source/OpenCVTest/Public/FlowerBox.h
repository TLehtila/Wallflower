// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMeshActor.h"
//#include <opencv2/core.hpp>
//
//#include <opencv2/imgcodecs.hpp>
//#include <opencv2/highgui.hpp>
//#include <opencv2/imgproc.hpp>
//#include <opencv2/videoio.hpp>
//#include <opencv2/video.hpp>

#include "vector"

#include "PreOpenCVHeaders.h"
#include "OpenCVHelper.h"
#include <ThirdParty/OpenCV/include/opencv2/imgproc.hpp>
#include <ThirdParty/OpenCV/include/opencv2/imgcodecs.hpp>
#include <ThirdParty/OpenCV/include/opencv2/videoio.hpp>
#include <ThirdParty/OpenCV/include/opencv2/video.hpp>
#include <ThirdParty/OpenCV/include/opencv2/highgui/highgui.hpp>
#include <ThirdParty/OpenCV/include/opencv2/core.hpp>
#include "PostOpenCVHeaders.h"

#include "NoiseFilter.h"
#include "MyFlower.h"


#include "FlowerBox.generated.h"

UCLASS()
class OPENCVTEST_API AFlowerBox : public AActor
{
	GENERATED_BODY()
public:	
	// Sets default values for this actor's properties
	AFlowerBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Called when the actor stops playing
	void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	UFUNCTION(BlueprintCallable)
	bool SpawnActor();

	void ScheduleActorSpawn();
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION()
	void SpawnActorScheduled();

	cv::Point2f getContours(cv::Mat img);

public:
	//Actor class to spawn
	UPROPERTY(EditAnywhere, BluePrintReadWrite)
	TSubclassOf<AActor> FlowerToBeSpawned;

	UPROPERTY(EditAnywhere, BluePrintReadWrite)
	bool ShouldSpawn = true;

	UPROPERTY(EditAnywhere, BluePrintReadWrite)
	float SpawnTime = 0.5f;

	UPROPERTY(EditAnywhere, BluePrintReadWrite)
	float RandomTime = 0.4f;

private:
	//Box for spawning actors
	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* SpawnBox;

	FTimerHandle SpawnTimerHandle;

	cv::VideoCapture capOne;
	cv::VideoCapture capTwo;
	cv::Mat frameOne;
	cv::Mat frameTwo;

	cv::Ptr<cv::BackgroundSubtractor> pBackSubOne;
	cv::Ptr<cv::BackgroundSubtractor> pBackSubTwo;

	cv::Mat fgMaskOne, fgMaskTwo;
	//cv::Mat frameBlurOne, frameBlurTwo;
	cv::Mat cannyOne, cannyTwo;
	cv::Mat contoursOne;
	cv::Mat contoursTwo;

	cv::Mat pointScreen;
	cv::Point2f touchPointOne, touchPointTwo;
	cv::Point2f correctedPointOne, correctedPointTwo;
	cv::Point2f pointsTogether, correctedPointsTogether;

	float cameraX, cameraY, displayX, displayY;
	float additionalX, additionalY, displayPointX, displayPointY;

	//cv::Rect emptyScreen;

	NoiseFilter* noiseFilterOne;
	NoiseFilter* noiseFilterTwo;
	NoiseFilter* noiseFilterFinal;

};
