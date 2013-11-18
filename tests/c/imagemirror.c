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
  CvSize size = cvSize(width, height);
  IplImage* dst = cvCreateImage(size, depth, channels);

  if(argc != 2){
    printf("no image data\n");
    return -1;
  }

  return 0;
}
