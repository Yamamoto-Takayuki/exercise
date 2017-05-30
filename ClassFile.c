#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "ex.h"


int getClassFile(FILE* fpt,Class* class){
  char* buf;
  char* str;

  if(NULL==fgets(str,256,fpt)){
    return 0;
  }else{
    buf=strtok(str," ");
    class->ID=atoi(buf);
    buf=strtok(NULL," ");
    class->kaiseki=atoi(buf);
    buf=strtok(NULL," ");
    class->senkei=atoi(buf);
    buf=strtok(NULL," ");
    class->seibutsu=atoi(buf);

  }

  return 1;
}

int addClassFile(FILE* fpt,Class* head){

  Class* prev;
  Class* current;
  Class* class;

  for(current=head;current->next!=NULL;current=currnt->next);
    class=(Class*)malloc(sizeof(Class));
    if(getClassFile(fpt,class)){
    current->next=class;
    class->prev=current;
    class->next=NULL;
    return 1;
  }
  return 0;
}

void sortClass(Class* head){

  Class* current;
  Class* prev;
  Class* next;



}




void putClassFile();
