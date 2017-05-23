#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int main (int argc,char* argv[]){

  if(argc!=4){
    printf("------option error ------\n");
    exit(1);
  }

  if(NULL==(fpi1=fopen(argv[1],"r"))){
      fprintf(stdout, "------%s open error------",argv[1]);
      exit(1);
    }
  if(NULL==(fpi2=fopen(argv[2],"r"))){
      fprintf(stdout, "------%s open error------",argv[2];
      exit(1);
    }
  if(NULL==(fpo=fopen(argv[3],"a"))){
      fprintf(stdout, "------%s open error------",argv[3]);
      exit(1
    }



}
