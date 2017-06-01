#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "ex.h"
#include "class.h"


int getClassFile(FILE* fpt,Class* class){
  char* buf;
  char str[256];

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
    class->DV_kaiseki=0;
    class->DV_senkei=0;
    class->DV_seibutsu=0;
    class->DV_sum=0;
    class->value=0;

  }

  return 1;
}

void sumToValue(Class* head){
  Class* p;
  for(p=head;p!=NULL;p=p->next){
    p->value=p->sum;
  }
}

void DV_sumToValue(Class* head){
  Class* p;
  for(p=head;p!=NULL;p=p->next){
    p->value=p->DV_sum;
  }
}


int addClassFile(FILE* fpt,Class* head){

  Class* current;
  Class* class;
  current=head;
  while(current->next!=NULL){
    current=current->next;
  }
    class=(Class*)malloc(sizeof(Class));
    if(getClassFile(fpt,class)){
    current->next=class;
    class->prev=current;
    class->next=NULL;
    return 1;
  }
  return 0;
}

void SwapClass(Class* a,Class* b){
  Class* temp;
  if(a->prev!=NULL)a->prev->next=b;
  if(b->prev!=NULL)b->prev->next=a;
  if(a->next!=NULL)a->next->prev=b;
  if(b->next!=NULL)b->next->prev=a;
  temp=a->prev;
  a->prev=b->prev;
  b->prev=temp;
  temp=a->next;
  a->next=b->next;
  b->next=temp;
}

Class* mergeList(Class* list1,Class* list2){

  Class head={0};
  Class* p;
  p=&head;
  while((list1!=NULL)&&(list2!=NULL)){
    if(list1->value>=list2->value){
      p->next=list1;
      list1->prev=p;
      p=list1;
      list1=list1->next;

    }else{
      p->next=list2;
      list2->prev=p;
      p=list2;
      list2=list2->next;
    }
  }

  if(list1==NULL){
    p->next=list2;
  }else{
    p->next=list1;
  }
  return (head.next);
}

Class* mergeSort(Class* p){

  Class* f; //forward
  Class* b; //backward
  Class* part; //partition

  if(p==NULL||p->next==NULL){
    return p;
  }

  f=p;
  b=p->next->next;
  while((b!=NULL)&&(b->next!=NULL)){
    f=f->next;
    b=b->next->next;
  }

  part=f->next; //x x x f part x x b
  f->next=NULL; //x x x f | part x x b


  return (mergeList(mergeSort(p),mergeSort(part)));
}

void putClassFile(FILE* fp,Class* head){
  Class* p;
  for(p=head;p!=NULL;p=p->next){
    fprintf(fp, "%d %d %d %d %d\n",p->ID,p->sum,p->kaiseki,p->senkei,p->seibutsu);
  }
}

void putClassFileDV(FILE* fp,Class* head){
  Class* p;
  for(p=head;p!=NULL;p=p->next){
    fprintf(fp,"%d %f %f %f %f\n",p->ID,p->DV_sum,p->DV_kaiseki,p->DV_senkei,p->DV_seibutsu);
  }
}

void freeClass(Class* head){
  Class* p;
  Class* temp;
  p=head;
  while(p!=NULL){
    temp=p;
    p=p->next;
    free(temp);
  }
}
