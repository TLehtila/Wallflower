// OpenCVTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/video.hpp>

#include "NoiseFilter.h"


cv::Point2f getContours(cv::Mat img, cv::Mat imgResult) {
    cv::Point2f coordinates;
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;

    cv::findContours(img, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    std::vector<std::vector<cv::Point>> contourPoly(contours.size());
    std::vector<cv::Rect> boundRectangle(contours.size());

    for (int i = 0; i < contours.size(); i++) {
        int area = cv::contourArea(contours[i]);
        if (area > 1000) {
            float perimeter = cv::arcLength(contours[i], true);
            cv::approxPolyDP(contours[i], contourPoly[i], 0.02 * perimeter, true);

            boundRectangle[i] = cv::boundingRect(contourPoly[i]);
            rectangle(imgResult, boundRectangle[i].tl(), boundRectangle[i].br(), cv::Scalar(255, 255, 255), 5);
            coordinates.x = boundRectangle[i].tl().x + ((boundRectangle[i].br().x  - boundRectangle[i].tl().x) / 2);
            coordinates.y = boundRectangle[i].tl().y + ((boundRectangle[i].br().y - boundRectangle[i].tl().y) / 2);

        }
    }
    return coordinates;
}

int main()
{
    std::cout << "OpenCV version is " << CV_VERSION << std::endl;


    // VideoCapture cap(camera id = 0->)
    cv::VideoCapture capOne(0);
    cv::VideoCapture capTwo(1);

    cv::Ptr<cv::BackgroundSubtractor> pBackSubOne;
    pBackSubOne = cv::createBackgroundSubtractorMOG2();
    cv::Ptr<cv::BackgroundSubtractor> pBackSubTwo;
    pBackSubTwo = cv::createBackgroundSubtractorMOG2();

    cv::Mat frameOne;
    capOne >> frameOne;
    cv::Mat frameTwo;
    capTwo >> frameTwo;
    int capOneWidth = frameOne.size[1];
    int capOneHeight = frameOne.size[0];
    int capTwoWidth = frameTwo.size[1];
    int capTwoHeight = frameTwo.size[0];

    std::cout << capOneWidth << " 1w - 1h " << capOneHeight << std::endl;
    std::cout << capTwoWidth << " 2w - 2h " << capTwoHeight << std::endl;

    cv::Mat fgMaskOne, frameBlurOne, fgMaskTwo, frameBlurTwo;
    cv::Mat cannyOne, cannyTwo;
    cv::Mat contoursOne(capOneHeight, capOneWidth, CV_8UC3, cv::Scalar(0, 0, 0));
    cv::Mat contoursTwo(capTwoHeight, capTwoWidth, CV_8UC3, cv::Scalar(0, 0, 0));

    cv::Mat pointScreen(capOneHeight, capOneWidth, CV_8UC3, cv::Scalar(0, 0, 0));

    cv::Point2f touchPointOne, touchPointTwo;
    cv::Point2f correctedPointOne, correctedPointTwo;
    cv::Point2f pointsTogether, correctedPointsTogether;

    cv::Rect emptyScreen(0, 0, capOneWidth, capOneHeight);
    touchPointOne.x = 0;
    touchPointOne.y = 0;
    touchPointTwo.x = 0;
    touchPointTwo.y = 0;

    noiseFilter *noiseFilterOne = new noiseFilter(10.5f);
    noiseFilter *noiseFilterTwo = new noiseFilter(10.5f);
    noiseFilter *noiseFilterFinal = new noiseFilter(10.5f);


    while (true) {
        capOne >> frameOne;
        capTwo >> frameTwo;


        //GaussianBlur(frameOne, frameBlurOne, Size(9, 9), 5, 0);
        //GaussianBlur(frameTwo, frameBlurTwo, Size(9, 9), 5, 0);


        pBackSubOne->apply(frameOne, fgMaskOne, -1.0);
        pBackSubTwo->apply(frameTwo, fgMaskTwo, -1.0);

        //Canny(fgMaskOne, cannyOne, 50, 150);
        //Canny(fgMaskTwo, cannyTwo, 50, 150);


        touchPointOne = getContours(fgMaskOne, contoursOne);
        touchPointTwo = getContours(fgMaskTwo, contoursTwo);
        correctedPointOne = noiseFilterOne->updatePoint(touchPointOne);
        correctedPointTwo = noiseFilterTwo->updatePoint(touchPointTwo);


        pointsTogether.x = correctedPointTwo.x;
        pointsTogether.y = correctedPointOne.y;

        //pointsTogether.x = touchPointTwo.x;
        //pointsTogether.y = touchPointOne.y;

        correctedPointsTogether = noiseFilterFinal->updatePoint(pointsTogether);

        rectangle(pointScreen, emptyScreen, cv::Scalar(0, 0, 0), cv::FILLED);

        circle(pointScreen, correctedPointsTogether, 10, cv::Scalar(255, 255, 255), cv::FILLED);

        //cout << correctedPointTwo.x << " " << correctedPointTwo.y << endl;

        imshow("point", pointScreen);
        imshow("camera1", fgMaskOne);
        imshow("camera2", fgMaskTwo);
        
        int keyboard = cv::waitKey(30);
        if (keyboard == 'q' || keyboard == 27) {
            break;
        }
    }
    return 0;
}