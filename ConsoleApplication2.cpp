#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void saveImage(const Mat& img) {
    string outputPath;
    cout << "Do you want to save the changes? (y/n): ";
    char saveChoice;
    cin >> saveChoice;
    if (saveChoice == 'y' || saveChoice == 'Y') {
        cout << "Enter the name for the image: ";
        string imageName;
        cin >> imageName;
        outputPath = "C:\\User-hak\\" + imageName + ".jpg";
        bool success = imwrite(outputPath, img);
        if (success) {
            cout << "Changed image saved at " << outputPath << endl;
        }
        else {
            cout << "Failed to save the Changed image" << endl;
        }
    }
}

int main() {
    Mat img = imread("C:\\User-hak\\wp6700107-cool-anime-3840x2160-wallpapers.jpg");

    if (img.empty()) {
        cout << "Could not open or find the image" << endl;
        return -1;
    }

    while (true) {
        int choice;
        cout << "Choose an option:\n1. View Image\n2. Crop Image\n3. Apply Filter\n4. Adjust Color\n5. Apply Gaussian Blur\n6. Adjust Saturation\n7. Exit\n";
        cin >> choice;

        if (choice == 1) {
            namedWindow("Cool Anime Wallpaper", WINDOW_NORMAL);
            setWindowProperty("Cool Anime Wallpaper", WND_PROP_FULLSCREEN, WINDOW_FULLSCREEN);
            imshow("Cool Anime Wallpaper", img);
            cout << "Press any key to close the window..." << endl;
            waitKey(0);
            destroyWindow("Cool Anime Wallpaper");
        }
        else if (choice == 2) {
            int width = img.cols;
            int height = img.rows;
            int width_new;
            int height_new;
            cout << "Current width: " << width << ", Current height: " << height << endl;
            cout << "Enter new width: ";
            cin >> width_new;
            cout << "Enter new height: ";
            cin >> height_new;
            Rect roi(0, 0, width_new, height_new);
            Mat croppedImage = img(roi);
            namedWindow("Cropped Image", WINDOW_NORMAL);
            imshow("Cropped Image", croppedImage);
            waitKey(0);
            destroyWindow("Cropped Image");
            saveImage(croppedImage);
        }
        else if (choice == 3) {
            Mat edges;
            Canny(img, edges, 50, 150);
            namedWindow("Edges", WINDOW_NORMAL);
            setWindowProperty("Edges", WND_PROP_FULLSCREEN, WINDOW_FULLSCREEN);
            imshow("Edges", edges);
            waitKey(0);
            destroyWindow("Edges");

            saveImage(edges);
        }
        else if (choice == 4) {
            Mat gray;
            cvtColor(img, gray, COLOR_BGR2GRAY);
            namedWindow("Grayscale", WINDOW_NORMAL);
            setWindowProperty("Grayscale", WND_PROP_FULLSCREEN, WINDOW_FULLSCREEN);
            imshow("Grayscale", gray);
            waitKey(0);
            destroyWindow("Grayscale");

            saveImage(gray);
        }
        else if (choice == 5) {
            Mat blurred;
            GaussianBlur(img, blurred, Size(25, 25), 0);
            namedWindow("Blurred", WINDOW_NORMAL);
            setWindowProperty("Blurred", WND_PROP_FULLSCREEN, WINDOW_FULLSCREEN);
            imshow("Blurred", blurred);
            waitKey(0);
            destroyWindow("Blurred");

            saveImage(blurred);
        }
        else if (choice == 6) {

            Mat hsv;
            cvtColor(img, hsv, COLOR_BGR2HSV);
            vector<Mat> channels;
            split(hsv, channels);
            int sat;
            cout << "Enter the saturation value(default:1): " << endl;
            cin >> sat;
            channels[1] *= sat;
            merge(channels, hsv);
            Mat saturated;
            cvtColor(hsv, saturated, COLOR_HSV2BGR);
            namedWindow("Saturated", WINDOW_NORMAL);
            setWindowProperty("Saturated", WND_PROP_FULLSCREEN, WINDOW_FULLSCREEN);
            imshow("Saturated", saturated);
            waitKey(0);
            destroyWindow("Saturated");

            saveImage(saturated);
        }
        else if (choice == 7) {
            break;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
