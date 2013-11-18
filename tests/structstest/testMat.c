#include <stdio.h>

typedef struct image{
  int rows;
  int columns;
  char * data;
}image;

struct image *initImage(char* data, int rows, int columns){
  struct image *instance = malloc(sizeof(image*));
  instance->rows = rows;
  instance->columns = columns;
  instance->data = data;
  
  return instance;
}

struct image *mockupMatrix(){
  char mat [10];
  int i = 0;
  int j = 0;

  for(i = 0; i < 10; i++){
    mat[i] = i;
  }

  struct image* img = initImage(mat, 2, 5);

  return img;
}

/*int main() {
  
  struct image *img = mockupMatrix();

  for(i = 0; i < img->rows; i++){
    for(j = 0; j < img->columns; j++){
      printf("%d ", img->data[i * img->columns + j]);
    }
    printf("\n");
  }

  printf("char %ld\n", sizeof(char));
  printf("int %ld\n", sizeof(int));
  printf("image %ld\n*", sizeof(image*));
  return 0;
  }*/
