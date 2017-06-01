#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "ex.h"
#include "calc.h"



void calcAdd(float value,Repre* rep){
  rep->mean+=value;
}

void calcMean(int N,Repre* rep){
  rep->mean/=N;
}

void calcSdAdd(float value,Repre* rep){
  rep->sd+=pow(value-rep->mean,2);
  rep->skewness+=pow(value-rep->mean,3);
  rep->kurtosis+=pow(value-rep->mean,4);

}


void calcRepValue(int N,Repre* rep){
  rep->sd/=N;
  rep->sd=sqrt(rep->sd);
  rep->se=rep->sd/sqrt(N);
  rep->skewness/=pow(rep->sd,3);
  rep->kurtosis/=pow(rep->sd,4);
  rep->kurtosis-=3;
}

void calcDi(float* DV,float value,Repre* rep){
  *DV=((value-rep->mean)*10/rep->sd)+50;
}

void calcSum(Class* head){
  Class* p;
  for(p=head;p!=NULL;p=p->next){
    p->sum=p->senkei+p->kaiseki+p->seibutsu;
  }
}

void calcRepre(Class* head,Repre* rep){
  int N=0;
  Class* current;

  for(current=head;current!=NULL;current=current->next){
    calcAdd(current->value,rep);
    N++;
  }
    calcMean(N,rep);

  for(current=head;current!=NULL;current=current->next){
    calcSdAdd(current->value,rep);
  }
    calcRepValue(N,rep);

}

void calcSeiseki(Class* head,Repre2* rep){
  Class* current;
  int i=0;
  for(current=head;current!=NULL;current=current->next){
    fprintf(stdout,"ID:%d,kaiseki:%d,senkei:%d,seibutsu:%d,sum:%d\n",current->ID,current->kaiseki,current->senkei,current->seibutsu,current->sum);

    calcAdd(current->kaiseki,&rep->rep_kai);
    calcAdd(current->senkei,&rep->rep_sen);
    calcAdd(current->seibutsu,&rep->rep_sei);
    calcAdd(current->sum,&rep->rep_sum);

    ++i;
  }
  calcMean(i,&rep->rep_kai);
  calcMean(i,&rep->rep_sen);
  calcMean(i,&rep->rep_sei);
  calcMean(i,&rep->rep_sum);

  for(current=head;current!=NULL;current=current->next){
    calcSdAdd(current->kaiseki,&rep->rep_kai);
    calcSdAdd(current->senkei,&rep->rep_sen);
    calcSdAdd(current->seibutsu,&rep->rep_sei);
    calcSdAdd(current->sum,&rep->rep_sum);
  }
  calcRepValue(i,&rep->rep_kai);
  calcRepValue(i,&rep->rep_sen);
  calcRepValue(i,&rep->rep_sei);
  calcRepValue(i,&rep->rep_sum);

  yamlPut(stdout,"mean",&(rep->rep_kai.mean),2,0);
  yamlPut(stdout,"sd",&(rep->rep_kai.sd),2,0);
  yamlPut(stdout,"se",&(rep->rep_kai.se),2,0);
  yamlPut(stdout,"skewness",&(rep->rep_kai.skewness),2,0);
  yamlPut(stdout,"kurtosis",&(rep->rep_kai.kurtosis),2,0);

  for(current=head;current!=NULL;current=current->next){
    calcDi(&current->DV_kaiseki,current->kaiseki,&rep->rep_kai);
    calcDi(&current->DV_senkei,current->senkei,&rep->rep_sen);
    calcDi(&current->DV_seibutsu,current->seibutsu,&rep->rep_sei);
    calcDi(&current->DV_sum,current->sum,&rep->rep_sum);

  }
}
