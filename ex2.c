#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>
#include "calc.h"
#include "class.h"

int main(int argc,char* argv[]){
  Class head;
  Class* current;
  FILE* fpi;
  FILE* fpo;
  Repre arg={0};
  int i;
  float temp;

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

  if(numberGet(fpi,&temp)){
    head.value=temp;
    head.next=NULL;
    current=&head;
}

  while(numberGet(fpi,&temp)){
  current->next=(Class*)malloc(sizeof(Class));
  current=current->next;
  current->value=temp;
  current->next=NULL;
}

  calcRepre(&head,&arg);
  yamlPut(fpo,"mean",&(arg.mean),2,0);
  yamlPut(fpo,"sd",&(arg.sd),2,0);
  yamlPut(fpo,"se",&(arg.se),2,0);
  yamlPut(fpo,"skewness",&(arg.skewness),2,0);
  yamlPut(fpo,"kurtosis",&(arg.kurtosis),2,0);
  freeClass(head.next);
return 0;
}
