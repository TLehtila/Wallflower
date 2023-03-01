// OpenCVTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include <opencv2/opencv.hpp>
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
    //drawContours(imgResult, contours, -1, Scalar(150, 50, 0), 5);

    //Point corner;
    std::vector<std::vector<cv::Point>> contourPoly(contours.size());
    std::vector<cv::Rect> boundRectangle(contours.size());

    for (int i = 0; i < contours.size(); i++) {
        int area = cv::contourArea(contours[i]);
        if (area > 1000) {
            float perimeter = cv::arcLength(contours[i], true);
            cv::approxPolyDP(contours[i], contourPoly[i], 0.02 * perimeter, true);
            //drawContours(imgResult, contourPoly, i, Scalar(150, 50, 0), 5);

            boundRectangle[i] = cv::boundingRect(contourPoly[i]);
            rectangle(imgResult, boundRectangle[i].tl(), boundRectangle[i].br(), cv::Scalar(255, 255, 255), 5);
            coordinates = boundRectangle[i].br();

        }
    }
    return coordinates;
}



//Point pointKalman(Point input) {
//    KalmanFilter KFOne(2, 1, 0);
//    KFOne.transitionMatrix = (Mat_<float>(4, 4) << 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1);
//    Mat_<float> measurement(2, 1);
//    measurement.setTo(Scalar(0));
//
//    KFOne.statePre.at<float>(0) = input.x;
//    KFOne.statePre.at<float>(1) = input.y;
//    KFOne.statePre.at<float>(2) = 0;
//    KFOne.statePre.at<float>(3) = 0;
//
//    setIdentity(KFOne.measurementMatrix);
//    setIdentity(KFOne.processNoiseCov, Scalar::all(1e-4));
//    setIdentity(KFOne.measurementNoiseCov, Scalar::all(1e-1));
//    setIdentity(KFOne.errorCovPost, Scalar::all(.1));
//
//    Mat predictionOne = KFOne.predict();
//    measurement(0) = input.x;
//    measurement(1) = input.y;
//    Mat estimated = KFOne.correct(measurement);
//
//    Point result(estimated.at<float>(0), estimated.at<float>(1));
//
//
//
//    return result;
//}

//KalmanFilter KFOne;
//Mat_<float> measurementOne(2, 1);
//
//void initKalman(Point input, KalmanFilter KF, Mat_<float> measurement) {
//    
//    KF.init(4, 2, 0);
//
//    measurement.at<float>(0, 0) = input.x;
//    measurement.at<float>(0, 0) = input.y;
//
//    KF.statePre.setTo(0);
//    KF.statePre.at<float>(0, 0) = input.x;
//    KF.statePre.at<float>(1, 0) = input.y;
//
//    KF.statePost.setTo(0);
//    KF.statePost.at<float>(0, 0) = input.x;
//    KF.statePost.at<float>(1, 0) = input.y;
//
//    setIdentity(KF.transitionMatrix);
//    setIdentity(KF.measurementMatrix);
//    setIdentity(KF.processNoiseCov, Scalar::all(.005));         //faster -> more noise
//    setIdentity(KF.measurementNoiseCov, Scalar::all(1e-1));
//    setIdentity(KF.errorCovPost, Scalar::all(.1));
//}
//
////https://stackoverflow.com/questions/18403918/opencv-kalman-filter-prediction-without-new-observtion/18407680
////https://www.myzhar.com/blog/tutorials/tutorial-opencv-ball-tracker-using-kalman-filter/ 
//
//Point kalmanCorrect(Point input, KalmanFilter KF, Mat_<float> measurement) {
//    measurement(0) = input.x;
//    measurement(1) = input.y;
//
//    Mat estimated = KF.correct(measurement);
//    Point correctedPoint(estimated.at<float>(0), estimated.at<float>(1));
//    return correctedPoint;
//}

int main()
{
    std::cout << "OpenCV version is " << CV_VERSION << std::endl;


    // VideoCapture cap(camera id = 0->)
    cv::VideoCapture capOne(0);
    cv::VideoCapture capTwo(1);
    //Mat img, imgBlur, imgCanny;

    cv::Ptr<cv::BackgroundSubtractor> pBackSubOne;
    pBackSubOne = cv::createBackgroundSubtractorMOG2();
    cv::Ptr<cv::BackgroundSubtractor> pBackSubTwo;
    pBackSubTwo = cv::createBackgroundSubtractorMOG2();

    //Point2f sourcePointsOne[4] = { {130, 95}, {640, 0}, {60, 435}, {640, 480} };
    //Point2f sourcePointsTwo[4] = { {30, 90}, {625, 80}, {0, 360}, {640, 360} };
    //Point2f destPointsOne[4] = { {0.0f, 0.0f}, {640, 0.0f}, {0.0f, 480}, {640, 480} };
    //Point2f destPointsTwo[4] = { {0.0f, 0.0f}, {640, 0.0f}, {0.0f, 360}, {640, 360} };
    //Mat matrixOne, matrixTwo, imgWarpOne, imgWarpTwo;

    //matrixOne = getPerspectiveTransform(sourcePointsOne, destPointsOne);
    //matrixTwo = getPerspectiveTransform(sourcePointsTwo, destPointsTwo);
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
    cv::Mat contoursOne(capOneWidth, capOneHeight, CV_8UC3, cv::Scalar(0, 0, 0));
    cv::Mat contoursTwo(capTwoWidth, capTwoHeight, CV_8UC3, cv::Scalar(0, 0, 0));

    cv::Mat pointScreen(capOneHeight, capOneWidth, CV_8UC3, cv::Scalar(0, 0, 0));

    /*
    for (int i = 0; i < 4; i++) {
        circle(frameOne, sourcePointsOne[i], 10, Scalar(0, 0, 255), FILLED);
    }
    */
    cv::Point2f touchPointOne, touchPointTwo;
    cv::Point2f correctedPointOne, correctedPointTwo;
    cv::Point2f pointsTogether, correctedPointsTogether;

    cv::Rect emptyScreen(0, 0, capOneWidth, capOneHeight);
    touchPointOne.x = 0;
    touchPointOne.y = 0;
    touchPointTwo.x = 0;
    touchPointTwo.y = 0;
    //initKalman(touchPoint, KFOne, measurementOne);

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

        Canny(fgMaskOne, cannyOne, 50, 150);
        Canny(fgMaskTwo, cannyTwo, 50, 150);


        touchPointOne = getContours(fgMaskOne, contoursOne);
        touchPointTwo = getContours(fgMaskTwo, contoursTwo);
        correctedPointOne = noiseFilterOne->updatePoint(touchPointOne);
        correctedPointTwo = noiseFilterTwo->updatePoint(touchPointTwo);


        pointsTogether.x = correctedPointTwo.x;
        pointsTogether.y = correctedPointOne.y;

        correctedPointsTogether = noiseFilterFinal->updatePoint(pointsTogether);

        rectangle(pointScreen, emptyScreen, cv::Scalar(0, 0, 0), cv::FILLED);

        circle(pointScreen, correctedPointsTogether, 10, cv::Scalar(255, 255, 255), cv::FILLED);

        //cout << correctedPointTwo.x << " " << correctedPointTwo.y << endl;

        imshow("point", pointScreen);
        imshow("camera1", cannyOne);
        imshow("camera2", cannyTwo);
        

        
        //imshow("FG Mask One", fgMaskOne);
        //imshow("FG Mask Two", fgMaskTwo);
        //imshow("TEST IMAGE 1", imgWarpOne);
        //imshow("TEST IMAGE 2", frameOne);

        int keyboard = cv::waitKey(30);
        if (keyboard == 'q' || keyboard == 27) {
            break;
        }
    }



    /*
    string path = "Resources/flower1.jpg";
    
    Mat img = imread(path);
    Mat imgGray, imgBlur, imgCanny, imgDilation, imgErosion, imgResized, imgCrop;
    
    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    GaussianBlur(img, imgBlur, Size(3, 3), 5, 0);
    Canny(imgBlur, imgCanny, 50, 150);

    Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
    dilate(imgCanny, imgDilation, kernel);
    erode(imgDilation, imgErosion, kernel);
    

    //cout << img.size() <<endl;

    resize(img, imgResized, Size(), 0.1, 0.1);


    Rect roi(100, 100, 300, 250);
    imgCrop = img(roi);

    //imshow("Image", img);
    //imshow("ImageGrey", imgGray);
    //imshow("ImageBlur", imgBlur);
    //imshow("ImageCanny", imgCanny);
    //imshow("Dilate", imgDilation);
    //imshow("Erode", imgErosion);
    imshow("Resized", imgResized);
    imshow("Cropped", imgCrop);

    waitKey(0);
    destroyAllWindows();
    
    
     

    string videoPath = "Resources/flowerVideo.avi";
    VideoCapture cap(videoPath);
    Mat img;

    while (true) {
        cap.read(img);
        imshow("Video", img);
        waitKey(1);
    }
    */
    //float screenWidth = 500;
    //float screenHeight = 500;

    //Mat screenImg(screenWidth, screenHeight, CV_8UC3, Scalar(0, 0, 0));

    //Point2f corners[4] = { {10, 10}, {screenWidth - 10, 10}, {10, screenHeight - 10}, {screenWidth - 10, screenHeight - 10} };
    //for (int i = 0; i < 4; i++) {
    //    circle(screenImg, corners[i], 50, Scalar(255, 255, 255), FILLED);
    //}

    //namedWindow("window", WND_PROP_FULLSCREEN);
    //setWindowProperty("window", WND_PROP_FULLSCREEN, WINDOW_FULLSCREEN);
    //imshow("window", screenImg);
    //Mat imgHSV, mask;
    //int hmin, smin, vmin;
    //int hmax, smax, vmax;
   
    //namedWindow("trackbars", (640, 200));
    //createTrackbar("hue min", "trackbars", &hmin, 179);
    //createTrackbar("hue max", "trackbars", &hmax, 179);
    //createTrackbar("sat min", "trackbars", &smin, 255);
    //createTrackbar("sat max", "trackbars", &smax, 255);
    //createTrackbar("val min", "trackbars", &vmin, 255);
    //createTrackbar("val max", "trackbars", &vmax, 255);
    //moveWindow("trackbars", 3000, 500);

    //namedWindow("Image mask");
    //moveWindow("Image mask", 3250, 500);

    //namedWindow("video hsv");
    //moveWindow("video hsv", 3250, 100);


    //cvtColor(screenImg, imgHSV, COLOR_BGR2HSV);

    //Mat frameOne, frameTwo;

    //while (true) {



    //    //imshow("Image", screenImg);
    //    //imshow("Image HSV", imgHSV);

    //    VideoCapture capOne(0);
    //    //VideoCapture capTwo(1);

    //    capOne >> frameOne;
    //    //capTwo >> frameTwo;
    //    //cvtColor(frameOne, imgHSV, COLOR_BGR2HSV);

    //    //Scalar lower(hmin, smin, vmin);
    //    //Scalar upper(hmax, smax, vmax);
    //    //inRange(imgHSV, lower, upper, mask);

    //    //imshow("video hsv", imgHSV);
    //    //imshow("Image mask", mask);

    //    int keyboard = waitKey(30);
    //    if (keyboard == 'q' || keyboard == 27) {
    //        break;
    //    }

    //}


    /*
    while (true) {
        cap.read(img);
        //GaussianBlur(img, imgBlur, Size(3, 3), 5, 0);
        //Canny(imgBlur, imgCanny, 50, 150);

        imshow("Webcam", imgCanny);
        waitKey(1);
    }
    */

    //string path = "Resources/flower1.jpg";
    //Mat img = imread(path);
    //Mat imgGray, imgBlur, imgCanny, imgDilation, imgErosion, imgResized, imgCrop;

    //cvtColor(img, imgGray, COLOR_BGR2GRAY);
    //GaussianBlur(imgGray, imgBlur, Size(3, 3), 5, 0);
    //Canny(imgBlur, imgCanny, 50, 150);
    //Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
    //dilate(imgCanny, imgDilation, kernel);
    //Mat imgContour;

    //getContours(imgDilation, img);

    //imshow("contoured", img);

    //

    ////imshow("effects", imgDilation);


    //waitKey(0);


    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
