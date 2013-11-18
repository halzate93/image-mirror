#include <cv.h>
#include <stdio.h>

int main (int argc, char** argv)
{
  IplImage* img = cvLoadImage(argv[1], 1);
  char* input = img->imageData;
  int width = img->width;
  int height = img->height;
  int depth = img->depth;
  int channels = img->nChannels;
  CvSize size = cvSize(width * 2, height);
  IplImage* nwimg = cvCreateImage(size, depth, channels);
  char* dst = nwimg->imageData;

  if(argc != 2){
    printf("no image data\n");
    return -1;
  }

  for(int i = 0; i < height; i++){
    for(int j = 0; j < width; j++){
      for(int k = 0; k < channels; k++){
	dst[nwimg->width * i * channels + j * channels + k] = input[width * i * channels + j * channels + k];
	//dst[nwimg->width * i * channels + (width - j) * channels + k] = dst[width * i * channels + j * channels + k];
      }
    }
  }

  cvShowImage("image", nwimg);

  cvWaitKey(0);
  cvDestroyWindow("image");
  cvReleaseImage(&nwimg);

  return 0;
}
