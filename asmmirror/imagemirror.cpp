#include <vector>
#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

typedef struct image{
  int rows;
  int cols;
  unsigned char* data;
}image;

struct image* initImage(uchar* data, int rows, int cols){
  image* instance = (image*) malloc(sizeof(image*));
  instance->rows = rows;
  instance->cols = cols;
  instance->data = data;
  return instance;
}

extern "C" void saveImage(image* image, char* path){
  Mat img = Mat(image->rows, image->cols, CV_8UC3, image->data);
  vector<int> compression_params;
  compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
  compression_params.push_back(9);
  imwrite(path, img, compression_params);
}

extern "C" image* loadImage(char* path){
  Mat img = imread(path, 1);
  
  uchar data [img.rows * img.cols * 3]; //(uchar*) malloc(img.rows * img.cols * 3 * sizeof(uchar));
  int i, j, k;
  for(i = 0; i < img.rows; i++){
    for(j = 0; j < img.cols; j++){
      for(k = 0; k < 3; k++){
	data[i * img.cols + j * 3 + k] = img.data[i * img.cols + j * 3 + k];
      }
    }
  }
  
  image* save = initImage(data, img.rows, img.cols);
  saveImage(save, (char*)"/home/user/test.jpeg");
}

int main(int argc, char** argv){

  /*Mat img = imread(argv[1], 1);
    uchar* data = img.data;*/

  image* img = loadImage(argv[1]);

  /*Mat save = Mat(img->rows, img->cols, CV_8UC3, img->data);
  vector<int> compression_params;
  compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
  compression_params.push_back(9);
  imwrite(argv[2], save, compression_params);*/

  saveImage(img, argv[2]);

  //printf("%s %s\n", argv[1], argv[2]);
  return 0;
}
