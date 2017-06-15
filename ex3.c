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
Disp* disp={0};
float det[3][3];
float* E;
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
  }else if(task==3){
    calcCov(head,&rep,disp);
    calcDisp(head,&rep,disp);

    det[0][0]=disp->disp_kaiseki;
    det[1][1]=disp->disp_senkei;
    det[2][2]=disp->disp_seibutsu;
    det[0][1]=disp->cov_XY;
    det[1][0]=disp->cov_XY;
    det[0][2]=disp->cov_XZ;
    det[2][0]=disp->cov_XZ;
    det[1][2]=disp->cov_YZ;
    det[2][2]=disp->cov_YZ;
    E=calcEigenvalue(det,3);
  }

  return 0;
}
