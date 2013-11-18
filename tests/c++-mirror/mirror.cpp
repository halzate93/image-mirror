#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int main( int argc, char** argv )
{
  Mat img;
  img = imread( argv[1], 1 );
  unsigned char *input = (unsigned char*)(img.data);

  if( argc != 2 || !img.data )
  {
    printf( "No image data \n" );
    return -1;
  }
  /*
  for(int i = 0; i < img.rows; i++){
    for(int j = 0; j < img.cols / 2; j++){
      img.at<Vec3b>(i, img.cols - 1 - j) = img.at<Vec3b>(i,j);
    }
  }*/

  //Some other way, with the image pointer
  int ch = img.channels();
  for(int i = 0; i < img.rows; i++){
    for(int j = 0; j < (img.cols / 2); j++){
      for(int k = 0; k < ch; k++){
	input[img.cols * i * ch + (img.cols - j) * ch + k] = input[img.cols * i * ch + j * ch + k];
      }
    }
  }
  vector<int> compression_params;
  compression_params.push_back(CV_IMWRITE_JPEG_QUALITY);
  compression_params.push_back(95);
  imwrite("genimg.jpg", img, compression_params);
  namedWindow( "Display Image", CV_WINDOW_AUTOSIZE );
  imshow( "Display Image", img );

  waitKey(0);

  return 0;
}
