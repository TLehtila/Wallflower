// OpenCVTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/video.hpp>

using namespace std;
using namespace cv;

Point2f getContours(Mat img, Mat imgResult) {
    Point2f coordinates;
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    findContours(img, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    //drawContours(imgResult, contours, -1, Scalar(150, 50, 0), 5);

    //Point corner;
    vector<vector<Point>> contourPoly(contours.size());
    vector<Rect> boundRectangle(contours.size());

    for (int i = 0; i < contours.size(); i++) {
        int area = contourArea(contours[i]);
        if (area > 500) {
            float perimeter = arcLength(contours[i], true);
            approxPolyDP(contours[i], contourPoly[i], 0.02 * perimeter, true);
            //drawContours(imgResult, contourPoly, i, Scalar(150, 50, 0), 5);

            cout << contourPoly[i].size() << endl;
            boundRectangle[i] = boundingRect(contourPoly[i]);
            rectangle(imgResult, boundRectangle[i].tl(), boundRectangle[i].br(), Scalar(255, 255, 255), 5);
            coordinates = boundRectangle[i].br();

        }
    }
    return coordinates;
}

int main()
{
    cout << "OpenCV version is " << CV_VERSION << endl;

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

    // VideoCapture cap(camera id = 0->)
    VideoCapture capOne(1);
    VideoCapture capTwo(1);
    //Mat img, imgBlur, imgCanny;

    Ptr<BackgroundSubtractor> pBackSubOne;
    pBackSubOne = createBackgroundSubtractorMOG2();
    Ptr<BackgroundSubtractor> pBackSubTwo;
    pBackSubTwo = createBackgroundSubtractorMOG2();

    //Point2f sourcePointsOne[4] = { {130, 95}, {640, 0}, {60, 435}, {640, 480} };
    //Point2f sourcePointsTwo[4] = { {30, 90}, {625, 80}, {0, 360}, {640, 360} };
    //Point2f destPointsOne[4] = { {0.0f, 0.0f}, {640, 0.0f}, {0.0f, 480}, {640, 480} };
    //Point2f destPointsTwo[4] = { {0.0f, 0.0f}, {640, 0.0f}, {0.0f, 360}, {640, 360} };
    //Mat matrixOne, matrixTwo, imgWarpOne, imgWarpTwo;

    //matrixOne = getPerspectiveTransform(sourcePointsOne, destPointsOne);
    //matrixTwo = getPerspectiveTransform(sourcePointsTwo, destPointsTwo);
    Mat frame;
    capOne >> frame;
    int capOneWidth = frame.size[0];
    int capOneHeight = frame.size[1];
    Mat frameOne, fgMaskOne, frameBlurOne, frameTwo, fgMaskTwo, frameBlurTwo;
    Mat cannyOne, cannyTwo;
    Mat contoursOne(capOneWidth, capOneHeight, CV_8UC3, Scalar(0, 0, 0));

    /*
    for (int i = 0; i < 4; i++) {
        circle(frameOne, sourcePointsOne[i], 10, Scalar(0, 0, 255), FILLED);
    }
    */
    Point2f touchPoint;

    Rect emptyScreen(0, 0, capOneHeight, capOneWidth);

    while (true) {
        capOne >> frameOne;
        capTwo >> frameTwo;
        
        //warpPerspective(frameOne, imgWarpOne, matrixOne, Point(640, 480));
        //warpPerspective(frameTwo, imgWarpTwo, matrixTwo, Point(640, 360));

        GaussianBlur(frameOne, frameBlurOne, Size(9, 9), 5, 0);
        GaussianBlur(frameTwo, frameBlurTwo, Size(9, 9), 5, 0);

        
        pBackSubOne->apply(frameBlurOne, fgMaskOne, -1.0);
        //pBackSubTwo->apply(frameBlurTwo, fgMaskTwo, -1.0);

        Canny(fgMaskOne, cannyOne, 50, 150);
        //Canny(frameBlurTwo, cannyTwo, 50, 150);

        imshow("canny", cannyOne);


        touchPoint = getContours(fgMaskOne, contoursOne);
        rectangle(contoursOne, emptyScreen, Scalar(0, 0, 0), FILLED);

        circle(contoursOne, touchPoint, 10, Scalar(255, 255, 255), FILLED);

        imshow("contours", contoursOne);
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
