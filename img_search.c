#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "rdjpeg.h"
#include "proc.h"

#define  DEBUG 1

float eucliedianDist(float query[4][4][4], float hist[4][4][4]){
  
  float res = 0.00;

  for (int r = 0; r < 4; ++r){
    for (int g = 0; g < 4; ++g){
      for (int b = 0; b < 4; ++b){
        res += query[r][g][b]*hist[r][g][b];
      }
    }
  }

  return res;
}

int main(int argc, char *argv[]){

  CIMAGE cim;
  char *image = malloc(15*sizeof(char));
  int nbOfLines=0;

  int i, j, r, g, b;
  size_t len, readed = 765;
  float query[4][4][4];

  for (r = 0; r < 4; ++r){
    for (g = 0; g < 4; ++g){
      for (b = 0; b < 4; ++b){
        query[r][g][b]=0.0;
      }
    }  
  }

  FILE *list = fopen("list.txt", "r");
  FILE *index = fopen("index.txt", "r");

  if (DEBUG) printf("Initialisation done\n");
    
  char ch;
  while(!feof(list)){
    ch = fgetc(list);
    if(ch == '\n'){
      nbOfLines++;
    }
  }

  if (DEBUG) printf("Nombre de ligne de list.txt : %d\n", nbOfLines);

  read_cimage(argv[1], &cim);


  for (i = 0; i < 8; i++){
    for (j = 0; j < 8; j++){
      query[cim.r[i][j]/64][cim.g[i][j]/64][cim.b[i][j]/64] += (float) 0.015625;
    }
  }

  free_cimage(argv[1], &cim);

  if (DEBUG) printf("Hist of query image done\n");


  KEY euclidDist[nbOfLines];
  float hist[4][4][4];
  char floatInString[8] = "0.000000";
  float floatFromString = 0.0;

  for (i = 0; i < nbOfLines; ++i){

    for ( r=0 ; r<4 ; ++r ) {
      for ( g=0 ; g<4; ++g ) {
        for ( b=0 ; b<4 ; ++b ) {
          hist[r][g][b]=0.0;
        }
      }  
    }

    //recupere l'histogramme de l'image a partir de index.txt
    readed = getline(&image, &len, index);
    // if (DEBUG) printf("%s", image);
    for (r = 0; r < 4; ++r){
      for (g = 0; g < 4; ++g){
        for (b = 0; b < 4; ++b){
          strncpy(floatInString, image+8*(b+4*g+16*r)+(b+4*g+16*r), 8);
          floatFromString = atof(floatInString);
          // printf("%d %d %d : %f\n", r,g,b, floatFromString);
          hist[r][g][b]=floatFromString;
        }
      }
    }
    // if (DEBUG) printf("ok %d\t", i);
    //calcule la distance et la stocke

  }

  exit(0);
}
