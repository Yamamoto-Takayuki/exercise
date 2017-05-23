#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>
#include "ex.h"

int main(int argc,char* argv[]){
  float arg1[256];

  FILE* fpi;
  FILE* fpo;
  Repre arg2={0};
  int i;

  if(argc!=3){
    printf("------option error ------\n");
    exit(1);
  }

  if(NULL==(fpi=fopen(argv[1],"r"))){
    fprintf(stdout, "file open error\n");
    exit(1);
  }

  if(NULL==(fpo=fopen(argv[2],"w"))){
    fprintf(stdout, "file open error\n");
    exit(1);
  }

  i=0;
  while(1){

    if(!numberGet(fpi,arg[i]) break;
    i++;
  }
  calcRepre(arg1,&arg2,i);
  numberPut(fpo,arg2.mean);
  numberPut(fpo,arg2.sd);
  numberPut(fpo,arg2.se);
  numberPut(fpo,arg2.skewness);
  numberPut(fpo,arg2.kurtosis);

return 0;
}
