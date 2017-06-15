#ifndef CALC_H
#define CALC_H
#include "ex.h"

extern void calcRepre(Class* head,Repre* rep);
extern void calcSeiseki(Class* head,Repre2* rep);
extern void calcAdd(float value,Repre* rep);
extern void calcMean(int N,Repre* rep);
extern void calcSdAdd(float value,Repre* rep);
extern void calcRepValue(int N,Repre* rep);
extern void calcDi(float* DV,float value,Repre* rep);
extern void calcSum(Class* head);
extern void calcSeiseki(Class* head,Repre2* rep)；
extern void calcCov(Class* head,Repre2* rep,Disp* disp);
extern void calcDisp(Class* head,Repre2* rep,Disp* disp);
extern float* getVector(int N);
extern float** getMatrix(int N);
extern void identifyMat(float** I,int N);
extern void freeMatrix(float** X,int N);
extern void calcMatrix(float** X,float** Y,float**Z,int N);
extern void transMatrix(float** X,int N);
extern float getNorm(float* X,int N);
extern float** getHouseholder(float* X,int N);
extern void decomQR(float** det,float** Q,float** R,int N);
extern float* calcEigenvalue(float** det,int N);



#endif
