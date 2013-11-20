#include <vector>
#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

typedef struct image{
  int rows;
  int columns;
  uchar * data;
}image;

int cols, rows;
uchar* data;

image* initImage(uchar* data, int rows, int columns){
  image* instance = (image*)malloc(sizeof(image*));
  instance->rows = rows;
  instance->columns = columns;
  instance->data = data;
  return instance;
}

extern "C" struct image* loadImage(char* path){
  Mat img = imread(path, 1);
  cols = img.cols;
  rows = img.rows;
  data = img.data;
  return initImage(img.data, img.rows, img.cols);
}

extern "C" int getCols(){
  return cols;
}

extern "C" int getRows(){
  return rows;
}

extern "C" uchar* getData(){
  return data;
}
//extern "C" void getImage(char* path

extern "C" void saveImage(uchar* image, int rows, int cols, char* path){
  Mat img = Mat(rows, cols, CV_8UC3, image);
  vector<int> compression_params;
  compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
  compression_params.push_back(9);
  imwrite(path, img, compression_params);
}

image* mirror(image* img, int width, int height){
  for(int i = 0; i < height; i++){
    for(int j = 0; i < width; j++){
      for(int k = 0; k < 3; k++){
	img->data[i * width * 3 + (width - j) * 3 + k] = img->data[i * width * 3 + j * 3 + k];
      }
    }
  }
  return img;
}

extern "C" void print(string s){
  //printf("%s", s);
  cout << s << endl;
}

/*int main(int argc, char** argv){
  //image* img = loadImage(argv[1]);
  //saveImage(img->data, img->rows, img->columns, (char*)"gen.jpg\0");
  Mat img = imread(argv[1], 1);
  uchar* data = img.data;
  Mat save = Mat(img.rows, img.cols, CV_8UC3, data);
  vector<int> compression_params;
  compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
  compression_params.push_back(9);
  imwrite("/home/user/Downloads/lol.jpg", save, compression_params);
  
  return 0;
  }*/
