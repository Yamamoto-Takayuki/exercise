#include "ex.h"
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(int argc,char* argv[]){

  float ave;
  float arg1;
  float arg2;
  FILE* fpi1;
  FILE* fpi2;
  FILE* fpo;

  if(argc!=4){
    printf("------option error ------\n");
    exit(1);
  }

  if(NULL==(fpi1=fopen(argv[1],"r"))){
    fprintf(stdout, "------%s open error------",argv[1]);
    exit(1);
  }
  if(NULL==(fpi2=fopen(argv[2],"r"))){
    fprintf(stdout, "------%s open error------",argv[2]);
    exit(1);
  }
  if(NULL==(fpo=fopen(argv[3],"a"))){
    fprintf(stdout, "------%s open error------",argv[3]);
    exit(1);
  }


  numberGet(fpi1,&arg1);
  numberGet(fpi2,&arg2);
  if(isnan(arg1)||isnan(arg2)){
    fprintf(stdout, "number error\n");
    exit(1);
  }
  ave=average(arg1,arg2);
  numberPut(fpo,&ave);

  return 0;
}
