#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;


int main() {


    int cameraNumber(0);
    std::cout << "What's your choice bitch " << std::endl;


    cin >> cameraNumber;

    string directory;
    cout << "Where to store images : ";
    cin >> directory;
    cout << "ok " << endl;


    std::cout << "Camera used is : " <<cameraNumber << std::endl;
    cv::VideoCapture cap(cameraNumber);
    cap.set(CV_CAP_PROP_FRAME_WIDTH, 1280);
    cap.set(CV_CAP_PROP_FRAME_HEIGHT, 960);

    int i(-2);

    while (true) {
        cv::Mat tmpImg;
        cap.read(tmpImg);
        cv::Mat new_image;
        cv::cvtColor(tmpImg, new_image, COLOR_BGR2GRAY);

        ++i;
        cv::imshow("LOL", new_image);

        string name = directory + std::to_string(i) + ".jpg";
        cv::imwrite(name, new_image);

        char c = (char) cv::waitKey(25);
        if (c == 27)
            break;
    }
    return 0;

}
