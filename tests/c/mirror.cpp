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
  
  int i,j,r,g,b;
  for(int i = 0; i < img.rows; i++){
    for(int j = 0; j < img.cols / 2; j++){
      input[img.cols * i + (img.rows - 2 - j)] = input[img.cols * i + j];
      input[img.cols * i + (img.rows - 1 - j)] = input[img.cols * i + j + 1];
      input[img.cols * i + (img.rows - j)] = input[img.cols * i + j + 2];
      
      //img.at<Vec3b>(j, img.cols - 1 - i)[0] = img.at<Vec3b>(j,i)[0];  //turn the pixel value @ (k,i) to yellow (0,255,255)
      //img.at<Vec3b>(j, img.cols - 1 - i)[1] = img.at<Vec3b>(j,i)[0];  
      //img.at<Vec3b>(j, img.cols - 1 - i)[2] = img.at<Vec3b>(j,i)[0];

      //b = input[img.step * j + i ] ;
      //g = input[img.step * j + i + 1];
      //r = input[img.step * j + i + 2];
    }
  }
  //for(int i = 0; i < image.rows / 2; i++){
    //for(int j = 0; j < image.cols; j++){
      //image.at(image.rows - 1 - i, j)[0] = image.at(i, j)[0];
      //image.at(image.rows - 1 - i, j)[1] = image.at(i, j)[1];
      //image.at(image.rows - 1 - i, j)[2] = image.at(i, j)[2];
      //}
    //  }
  namedWindow( "Display Image", CV_WINDOW_AUTOSIZE );
  imshow( "Display Image", img );

  waitKey(0);

  return 0;
}
