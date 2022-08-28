#include<opencv2/opencv.hpp>
#include<iostream>

std::string path = "D:/COMPUTACION GRAFICA/OPENCV/data/BackgroundSubstraction_Medium.mp4";

int main(){
    // videocapture
    cv::VideoCapture cap(path);
    // init first frame as empty
    cv::Mat background, frame;

    float width = cap.get(cv::CAP_PROP_FRAME_WIDTH);
    float height = cap.get(cv::CAP_PROP_FRAME_HEIGHT);

    float proportion = width / height;

    std::cout << "width: " << width << std::endl;
    std::cout << "height: " << height << std::endl;
    std::cout << "proportion: " << proportion << std::endl;

    // go over all the frames
    while (cap.read(frame))
    {
        // resize to a specific size 
        cv::resize(frame, frame, cv::Size(640, 480));

        // convert to gray scale
        cv::Mat gray;
        cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);

        // blur the image
        cv::GaussianBlur(gray, gray, cv::Size(5, 5), 0);

        // init first frame as empty
        if (background.empty())
        {
            background = gray.clone();
            continue;
        }

        // compute the absolute difference between the background and the current frame
        cv::Mat diff;
        cv::absdiff(background, gray, diff);

        // threshold the diff image
        cv::Mat thresholded;
        cv::threshold(diff, thresholded, 25, 255, cv::THRESH_BINARY);

        // dilate the thresholded image to fill in holes, then find contours on thresholded image
        cv::dilate(thresholded, thresholded, cv::Mat(), cv::Point(-1, -1), 2);

        // copy the thresholded image to detect contours
        cv::Mat contourImage = thresholded.clone();

        // find contours in the image
        std::vector<std::vector<cv::Point>> contours;
        cv::findContours(contourImage, contours, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

        // iterate through each contour.
        for (auto i = 0; i < contours.size(); i++)
        {
            // delete small contours
            if (cv::contourArea(contours[i]) < 360 || cv::contourArea(contours[i]) > 40000)
                continue;

            // compute the bounding box of the contour
            cv::Rect boundingRect = cv::boundingRect(contours[i]);
            // draw the bounding rectangle around the contour
            cv::rectangle(frame, boundingRect, cv::Scalar(0, 255, 0), 2);
        }

        // show the frame with the bounding boxes drawn around the contours (MAIN)
        cv::imshow("Frame", frame);
        // show the thresholded image
        cv::imshow("Thresholded", thresholded);
        // show the dilated thresholded image
        cv::imshow("Rest", diff);
        // show the contour image
        cv::imshow("Contour", contourImage);

        // time sleep to appreciate the difference in frames
        cv::waitKey(36);

    }

    // Wait for a keystroke.   
    cv::waitKey(0);


    // Destroys all the windows created                         
    cv::destroyAllWindows();


    return 0;
}






