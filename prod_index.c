#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "rdjpeg.h"

#define  DEBUG 0


void read(double hist[4][4][4]){
  for (int r = 0; r < 4; ++r){
    for (int g = 0; g < 4; ++g){
      for (int b = 0; b < 4; ++b){
        printf("hist[%d][%d][%d] : %lf\t", r, g, b, hist[r][g][b]);
      }
      printf("\n");
    }
  }
}

int main(int argc, char *argv[]){

  int i,j;
  CIMAGE cim;
  
  size_t readed; 
  size_t len;
  char *image = malloc(15*sizeof(char));
  FILE *list = fopen("list.txt", "r");
  FILE *index = fopen("index.txt", "w");
  double hist[4][4][4];
  if (list != NULL){
  if (DEBUG) printf("Breakpoint1\n");
  
  while ((readed = getline(&image, &len, list)) != 0){
    
    for (int r = 0; r < 4; ++r){
      for (int g = 0; g < 4; ++g){
        for (int b = 0; b < 4; ++b){
          hist[r][g][b] = 0.00;
        }
      }
    }

    char img[50] = "images/";
    image[15]=0;
    strcat(img,image);
    if (DEBUG) printf("%s\n", img);

    read_cimage(img, &cim);

    if (DEBUG) printf("Breakpoint2\n");
    for (i = 0; i < 8; i++){
      for (j = 0; j < 8; j++){
        hist[cim.r[i][j]/64][cim.g[i][j]/64][cim.b[i][j]/64] += (double) 0.015625;
      }
    }

    for (int r = 0; r < 4; ++r){
      for (int g = 0; g < 4; ++g){
        for (int b = 0; b < 4; ++b){
          fprintf(index, "%lf\t", hist[r][g][b]);
        }
        fprintf(index, "\n");
      }
    }
    fprintf(index, "\n");

    free_cimage(image, &cim);
    }

  }

  

  read(hist);
  fclose(list);
  exit(0);
}
