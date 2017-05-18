#ifndef EX_H
#define EX_H
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct Repre{
  float mean;
  float sd;
  float se;
  float skewness;
  float kurtosis;
}Repre;


extern void numberGet(FILE* fpt,float* c);
extern void numberPut(FILE* fpt,float* d);
extern float average(float a,float b);
extern void calcRepre(float a[],Repre* arg,int N);
#endif
