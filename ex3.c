#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"calc.h"
#include"class.h"

int main (int argc,char* argv[]){

int task;
FILE* fpi;
FILE* fpo;
Class* head;
Repre2 rep={{0},{0},{0},{0}};
  if(argc!=4){
    printf("------option error ------\n");
    exit(1);
  }

  if(NULL==(fpi=fopen(argv[1],"r"))){
    fprintf(stdout, "------%s open error------",argv[1]);
    exit(1);
  }
  if(NULL==(fpo=fopen(argv[2],"w"))){
    fprintf(stdout, "------%s open error------",argv[2]);
    exit(1);
  }
  task=atoi(argv[3]);
  head=(Class*)malloc(sizeof(Class));
  if(!getClassFile(fpi,head)){
    fprintf(stdout, "error read file\n" );
  }
  head->prev=NULL;
  head->next=NULL;
  while (addClassFile(fpi,head));
  putClassFileDV(stdout,head);

  calcSum(head);
  if(task==1){
    sumToValue(head);
    head=mergeSort(head);
    putClassFile(fpo,head);
  }else if(task==2){
    calcSeiseki(head,&rep);
    putClassFileDV(stdout,head);
    DV_sumToValue(head);
    head=mergeSort(head);
    putClassFileDV(fpo,head);
  }

  return 0;
}
