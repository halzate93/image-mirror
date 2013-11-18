#include <stdio.h>
#include <cv.h>

int main( int argc, char** argv )
{
  IplImage* img = cvLoadImage(argv[1], 1);
  char* input = img->imageData;

  if( argc != 2)
  {
    printf( "No image data \n" );
    return -1;
  }

  //Some other way, with the image pointer
  int ch = img->nChannels;
  for(int i = 0; i < img->height; i++){
    for(int j = 0; j < (img->width / 2); j++){
      for(int k = 0; k < ch; k++){
	input[img->width * i * ch + (img->width - j) * ch + k] = input[img->width * i * ch + j * ch + k];
      }
    }
  }
  //cvNamedWindow("Image", 1);
  cvShowImage("image", img);

  //wait for key to close the window
  cvWaitKey(0);
  cvDestroyWindow( "Image" );
  cvReleaseImage( &img );

  return 0;
}

