#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "ex.h"


void calcRepre(Class* head,Repre* rep){
  int i;
  int N;
  Class* current;

  for(current=head;current!=NULL;current=current->next){
    calcAdd(current->value,rep);
    N++;
  }
    calcMean(i,rep);

  for(current=head;current!=NULL;current=current->next){
    calcSdAdd(current->value,rep);
  }
    calcRepre(i,rep);

}

void calcSeiseki(Class* head,Repre* rep){
  Class* current;
  int i;
  for(current=head;current!=NULL;current=current->next){
    calcAdd(current->kaiseki,rep_kai);
    calcAdd(current->senkei,rep_sen);
    calcAdd(current->seibutsu,rep_sei);
    calcAdd(current->sum,rep_sum)
    ++i;
  }
  calcMean(i,rep_kai);
  calcMean(i,rep_sen);
  calcMean(i,rep_sei);
  calcMean(i,rep_sum);

  for(current=head;current!=NULL;current=current->next){
    calcSdAdd(current->kaiseki,rep_kai);
    calcSdAdd(current->senkei,rep_sen);
    calcSdAdd(current->seibutsu,rep_sei);
    calcSdAdd(current->sum,rep_sum);
  }
  calcRepre(i,rep_kai);
  calcRepre(i,rep_sen);
  calcRepre(i,rep_sei);
  calcRepre(i,rep_sum);

  for(current=head;current!=NULL;current=current->next){
    calcDi(current->DV_kaiseki,current->kaiseki,rep_kai);
    calcDi(current->DV_senkei,current->senkei,rep_sen);
    calcDi(current->DV_seibutsu,current->seibutsu,rep_sei);
    calcDi(current->DV_sum,current->sum,rep_sum);

  }
}


void calcAdd(float value,Repre* rep){
  rep->mean+=value;
}

void calcMean(int N,Repre* rep){
  rep->mean/=N;
}

void calcSdAdd(float value,Repre* rep){
  rep->sd+=pow(value-rep->mean,2);
  rep->skewness+=pow((current->value)-rep->mean),3);
  rep->kurtosis+=pow((current->value)-rep->mean),4);
}

void calcRepre(int N,Repre* rep){
  rep->sd/=N;
  rep->sd=sqrt(rep->sd);
  rep->se=rep->sd/sqrt(N);
  rep->skewness/=pow(rep->sd,3);
  rep->kurtosis/=pow(rep->sd,4);
  rep->kurtosis-=3;

}

void calcDi(float* DV,float value,Repre* rep){
  DV=((value-rep->mean)*10/rep->sd)+50;
}

void calcSum(Class* head){
  Class* p;
  for(p=head;p!=NULL;p=p->next){
    p->sum=p->senkei+p->kaiseki+p->seibutsu;
  }
}
