#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stddef.h>


typedef struct test{
  int ID;
  int eigo;
  int kokugo;
  struct test* next;
}Class;

void pri(Class* p,char* PROPERTY);

int main(void){
Class P={0,50,80,NULL};
Class Q={1,70,30,NULL};
Class R={2,40,10,NULL};
int i;
int N;
Class* p;
P.next=&Q;
Q.next=&R;
p=&P;

printf("ID:%d 英語:%d 国語:%d \n",p->ID,p->eigo,p->kokugo);
printf("ID:%d 英語:%d 国語:%d \n",p->next->ID,p->next->eigo,p->next->kokugo);
printf("ID:%d 英語:%d 国語:%d \n",p->next->next->ID,p->next->next->eigo,p->next->next->kokugo);
pri(p,"eigo");
}

void pri(Class* p,char* PROPERTY){
  printf("ID:%d 英語:%d \n",p->ID,p->PROPERTY);

}
