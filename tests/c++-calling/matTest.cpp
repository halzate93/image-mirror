#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

extern "C" void testFunction(int a, int b){
  cout << a + b << endl;
  Mat mat = imread("~/Downloads/img.jpg", 1);
  uchar* datos = mat.data;
}
