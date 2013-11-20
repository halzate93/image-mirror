#include <vector>
#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

int cols, rows;
uchar* data;

extern "C" void loadImage(char* path){
  Mat img = imread(path, 1);
  cols = img.cols;
  rows = img.rows;
  data = (uchar*)malloc(cols * rows * 3 * sizeof(uchar));
  int i, j, k;
  for(i = 0; i < rows; i++){
    for(j = 0; j < cols; j++){
      for(k = 0; k < 3; k++){
	//printf("YEAH %d %d %d\n", i, j, k);
	data[i * cols * 3 + j * 3 + k] = img.data[i * cols * 3 + j * 3 + k];
      }
    }
  }
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

extern "C" void saveImage(char* path){
  Mat img = Mat(rows, cols, CV_8UC3, data);
  vector<int> compression_params;
  compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
  compression_params.push_back(9);
  imwrite(path, img, compression_params);
}

extern "C" void mirror(){
  for(int i = 0; i < rows; i++){
    for(int j = 0; i < cols; j++){
      for(int k = 0; k < 3; k++){
  	data[i * cols * 3 + (cols - j) * 3 + k] = data[i * cols * 3 + j * 3 + k];
      }
    }
  }
}

int main(int argc, char** argv){
  loadImage(argv[1]);
  saveImage(argv[2]);
  /*Mat img = imread(argv[1], 1);
  uchar* data = img.data;
  Mat save = Mat(img.rows, img.cols, CV_8UC3, data);
  vector<int> compression_params;
  compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
  compression_params.push_back(9);
  imwrite("/home/user/Downloads/lol.jpg", save, compression_params);*/ 
  return 0;
}
