//Emilio Diaz
//15316

#include <iostream>
#include <opencv2/opencv.hpp>
#include <pthread.h>
#define NUM_THREADS 15
#define W 3
#define H 4



using namespace cv;
using namespace std;
void pixelate(Mat& src, Mat& dst, int pixel_size = 1) {
	
    try {
        dst.create(src.rows, src.cols, src.type());
        Rect rectan;
        
        for (int r = 0; r < src.rows; r += H*W){
            for (int c = 0; c < src.cols; c += H*W){
                rectan.x = c;
                rectan.y = r;
                rectan.width = c + pixel_size < src.cols ? pixel_size : src.cols - c;
                rectan.height = r + pixel_size < src.rows ? pixel_size : src.rows - r;
                Scalar color = mean(Mat(src, rectan));
                rectangle(dst, rect, color, CV_FILLED);
            }
        }
    }

    catch (cv::Exception &ex) {
        cout << ex.what() << endl;

    }

}
void *create_image(void* numero){
    cout<<"thread calledd"<<endl;
        int residuo;

    for (int i = 0; i<H; i++){
        for(int j = 0; j <W; j++){
                        residuo=i*j;
                }

        }
    pthread_exit((void*) residuo);
}

int main(int argc, char** argv){
    Mat image = imread("ramphastosSulphuratus.jpeg", CV_LOAD_IMAGE_COLOR);
    pthread_t threads[NUM_THREADS];
    int t = 0;

    ontrack(H*W, &image);
    return 0;

}





void ontrack(int value, void* data) {
    if (value <= 0) return;
    Mat dst1, dst2;
    pixelate(*((Mat*)data), dst2, W*H);
    imshow("Pixelate Effect", dst2);
	imwrite( "newImage.jpg", dst2 );



}




