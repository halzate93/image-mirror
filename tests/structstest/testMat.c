#include <stdio.h>

unsigned char mat [100];

typedef struct image{
  int rows;
  int columns;
  unsigned char* data;
}image;

struct image* initImage(unsigned char* data, int rows, int columns){
  image* instance = malloc(sizeof(image*));
  instance->rows = rows;
  instance->columns = columns;
  instance->data = data;
  return instance;
}

extern struct image* mockupMatrix(){
  int i;
  for(i = 0; i < 100; i++){
    mat[i] = i;
  }
  struct image* img = initImage(mat, 10, 10);
  return img;
}

extern void printMatrix(image* img){
  int i, j;
  for(i = 0; i < img->rows; i++){
    for(j = 0; j < img->columns; j++){
      printf("%d ", img->data[i * (img->columns) + j]);
    }
    printf("\n");
  }
}

/*int main() {
  
  struct image* img = mockupMatrix();
  printMatrix(img);

  printf("uchar* %ld\n", sizeof(unsigned char*));
  printf("int %ld\n", sizeof(int));
  printf("image* %ld\n", sizeof(image*));
  return 0;
}*/
