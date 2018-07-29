#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;


int main() {
    int cameraNumber(0);
    string directory = "";
    int savingFrames;
    int i(-2);

    std::cout << "What's your choice bitch " << std::endl;
    cin >> cameraNumber;


    cout << "Are you willing to save camera frames ? YES == 1 NO == 0 : "
    cin >> savingFrames;

    if (savingFrames)
    {
        cout << "Where to store images : ";
        cin >> directory;
        cout << "ok " << endl;
    }

    std::cout << "Camera used is : " <<cameraNumber << std::endl;
    cv::VideoCapture cap(cameraNumber);
    cap.set(CV_CAP_PROP_FRAME_WIDTH, 1280);
    cap.set(CV_CAP_PROP_FRAME_HEIGHT, 960);



    while (true) {
        cv::Mat tmpImg;
        cap.read(tmpImg);
        cv::Mat new_image;
        cv::cvtColor(tmpImg, new_image, COLOR_BGR2GRAY);

        ++i;
        cv::imshow("LOL", new_image);

        if (savingFrames)
        {
            string name = directory + std::to_string(i) + ".jpg";
            cv::imwrite(name, new_image);
        }

        char c = (char) cv::waitKey(25);
        if (c == 27)
            break;
    }
    return 0;

}
