#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "rdjpeg.h"
#include "proc.h"

#define  DEBUG 0

float eucliedianDist(float query[4][4][4] float hist[4][4][4]){
  float res = 0.00;

  for (int r = 0; r < 4; ++r){
    for (int g = 0; g < 4; ++g){
      for (int b = 0; b < 4; ++b){
        res += query[r][g][b]*hist[r][g][b]
      }
    }
  }
}

int main(int argc, char *argv[]){
  CIMAGE cim;
  char *image = malloc(15*sizeof(char));
  int nbOfLines;
  size_t len = 765;
  float query[4][4][4] = {0.0};
  FILE *list = fopen("list.txt", "r");
  FILE *index = fopen("index.txt", "r");
  if ( list != NULL ){
    line = 15000;
    while (fgets(line, line, list) != NULL ){
      nbOfLines++;
    }
    fclose ( file );
  }

  read_cimage(argv[1], &cim);

  for (i = 0; i < 8; i++){
    for (j = 0; j < 8; j++){
      query[cim.r[i][j]/64][cim.g[i][j]/64][cim.b[i][j]/64] += (float) 0.015625;
    }
  }

  KEY euclidDist[nbOfLines];

  while ((readed = getline(&image, &len, index)) != -1){
    
  }


  exit(0);
}
