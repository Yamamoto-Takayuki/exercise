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

#endif
