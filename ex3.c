#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main (int argc,char* argv[]){

int i,j;
int task;
FILE* fpi;
FILE* fpo;
Class head;

  if(argc!=4){
    printf("------option error ------\n");
    exit(1);
  }

  if(NULL==(fpi=fopen(argv[1],"r"))){
    fprintf(stdout, "------%s open error------",argv[1]);
    exit(1);
  }
  if(NULL==(fpo=fopen(argv[2],"r"))){
    fprintf(stdout, "------%s open error------",argv[2];
    exit(1);
  }
  task=atoi(argv[3]);

  if(!getClassFile(fpi,&head)){
    fprintf(stdout, "error read file\n" );
  }
  head->prev=NULL;
  head->next=NULL;
  while (addClassFile(fpi,&head));

  calcSum(&head);
  sumToValue(&head);
  mergeSortClass(&head);
  putClassFile(fpo,&head);
  return 0;
}
