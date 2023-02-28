// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PreOpenCVHeaders.h"
#include "OpenCVHelper.h"
#include <ThirdParty/OpenCV/include/opencv2/imgproc.hpp>
#include <ThirdParty/OpenCV/include/opencv2/highgui/highgui.hpp>
#include <ThirdParty/OpenCV/include/opencv2/core.hpp>
#include "PostOpenCVHeaders.h"
#include "UObject/NoExportTypes.h"

#include "CoreMinimal.h"

/**
 * 
 */
class OPENCVTEST_API NoiseFilter
{
private:
    static const int maxHistory = 10;
    cv::Point2f lastPoint;
    float pointMaxTolerance;
    cv::Point2f history[maxHistory];
    int historyHead, historySize;
public:
	NoiseFilter(float maxTolerance);
	~NoiseFilter();
    cv::Point2f& getResult();
    cv::Point2f& updatePoint(cv::Point2f newPoint);
    float pointDistance(cv::Point2f& point1, cv::Point2f& point2);
};
