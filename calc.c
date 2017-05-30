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
    ++i;
  }
  calcMean(i,rep_kai);
  calcMean(i,rep_sen);
  calcMean(i,rep_sei);

  for(current=head;current!=NULL;current=current->next){
    calcSdAdd(current->kaiseki,rep_kai);
    calcSdAdd(current->senkei,rep_sen);
    calcSdAdd(current->seibutsu,rep_sei);
  }
  calcRepre(i,rep_kai);
  calcRepre(i,rep_sen);
  calcRepre(i,rep_sei);

  for(current=head;current!=NULL;current=current->next){
    calcDi(current->Di,current->kaiseki,rep_kai);
    calcDi(current->Di,current->senkei,rep_sen);
    calcDi(current->Di,current->seibutsu,rep_sei);
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

void calcDi(float* Di,float value,Repre* rep,){
  *Di=((value-mean)*10/rep->sd)+50;
}
