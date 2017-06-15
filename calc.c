#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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
	for(p=head; p!=NULL; p=p->next) {
		p->sum=p->senkei+p->kaiseki+p->seibutsu;
	}
}

void calcRepre(Class* head,Repre* rep){
	int N=0;
	Class* current;

	for(current=head; current!=NULL; current=current->next) {
		calcAdd(current->value,rep);
		N++;
	}
	calcMean(N,rep);

	for(current=head; current!=NULL; current=current->next) {
		calcSdAdd(current->value,rep);
	}
	calcRepValue(N,rep);

}


void calcSeiseki(Class* head,Repre2* rep){
	Class* current;
	int i=0;
	for(current=head; current!=NULL; current=current->next) {
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

	for(current=head; current!=NULL; current=current->next) {
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

	for(current=head; current!=NULL; current=current->next) {
		calcDi(&current->DV_kaiseki,current->kaiseki,&rep->rep_kai);
		calcDi(&current->DV_senkei,current->senkei,&rep->rep_sen);
		calcDi(&current->DV_seibutsu,current->seibutsu,&rep->rep_sei);
		calcDi(&current->DV_sum,current->sum,&rep->rep_sum);

	}
}

void calcCov(Class* head,Repre2* rep,Disp* disp){

	Class* p;
  int N=0;
	for(p=head; p!=NULL; p=p->next) {
		disp->cov_XY+=pow((p->kaiseki-rep->rep_kai->mean)*(p->senkei-rep->rep_sen->mean),2);
		disp->cov_XZ+=pow((p->kaiseki-rep->rep_kai->mean)*(p->seibutsu-rep->rep_sei->mean),2);
		disp->cov_YZ+=pow((p->senkei-rep->rep_sen->mean)*(p->seibutsu-rep->rep_sei->mean),2);
    N++;
	}

  disp->cov_XY/=N;
  disp->cov_XZ/=N;
  disp->cov_YZ/=N;
}

void calcDisp(Class* head,Repre2* rep,Disp* disp){

  Class* p;

	disp->disp_senkei=pow(rep->rep_kai.sd,2);
	disp->disp_kaiseki=pow(rep->rep_sen.sd,2);
	disp->disp_seibutsu=pow(rep->rep_sei.sd,2);
}

float* getVector(int N){
  float* V;
  V=(float*)malloc(sizeof(float)*N);
  return V;
}

float** getMatrix(int N){
  float** X;
  X=(float**)malloc(sizeof(float*)*N);
  for(i=0;i<N;i++){
    X[i]=(float*)malloc(sizeof(float)*N);
  }
  return X;
}
void identifyMat(float** I,int N){
  int i,j;
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      if(i==j){
        I[i][j]=1;
      }else{
        I[i][j]=0;
      }
    }
  }
}

void freeMatrix(float** X,int N){
  int i,j;

  for(i=0;i<N;i++){
    free(X[i]);
  }
  free(X);
}

void calcMatrix(float** X,float** Y,float**Z,int N){
  int i,j,k;

  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      for(k=0;k<N;k++){
        Z[i][j]+=X[i][k]*Y[j][k];
      }
    }
  }
}

void transMatrix(float** X,int N){
  int i,j,k;
  float temp;
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      for(k=0;k<N;k++){
        temp=X[i][j];
      }
    }
  }
}

float getNorm(float* X,int N){
  int i;
  float norm=0;
  for(i=0;i<N;i++){
  norm+=X[i]*X[i];
}
return sqrt(norm);
}


float** getHouseholder(float* X,int N){
  float norm;
//  float I[N][N];  //C99で対応
  float** H;
  float* Z;
  int i,j;
  float D;

  identifyMat(H,N);
  Z=(float*)malloc(sizeof(float)*N);
  norm=getNorm(X,N);
  X[0]=X[0]-norm;
  D=pow(getNorm(X,N),2);
  for(i=0;i<N;i++){}
    for(j=0;j<N;j++){
      H[i][j]-=2*X[i]*X[j]/D;
    }
  }
// X2=(norm,0,0,0,...)
// H=I-2*(X-X2)(X-X2)^T/pow(getNorm(X-X2,N),2);
// =I-2*X*X/D

return H;
}

void decomQR(float** det,float** Q,float** R,int N){
  int i,j;
  int count=0;
  float* X;

  identifyMat(Q,N);
  identifyMat(R,N);
  calcMatrix(det,R,R);
while((N-count)>0){
  X=getVector(N-count);
  for(i=0;i<(N-count);i++){
    V[i]=X[count][i+count];
  }
  H=getHouseholder(X,N);
  calcMatrix(H,R,R,3);
  transMatrix(H,N);
  calcMatrix(Q,H,Q,3);
  free(X);
  count++;
  }
  freeMatrix(H);
}

float* calcEigenvalue(float** det,int N){
  int i;
  float** Q;
  float** R;
  float** X;
  float* E;
  float diff;
  E=getVector(N);
  Q=getMatrix(N);
  R=getMatrix(N);
  X=getMatrix(N);

  decomQR(det,Q,R,N); //QR=det
  transMatrix(Q,N);
  calcMatrix(Q,det,X);

  while(diff<=0.001&&diff>=-0.001){
    diff=X[0];
    decomQR(X,Q,R,N);
    transMatrix(Q,N);
    calcMatrix(Q,X,X);
    diff-=X[0];
  }
  for(i=0;i<N;i++){
    E[i]=X[i][i];
  }
  return E;
}
