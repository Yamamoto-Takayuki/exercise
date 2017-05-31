#ifndef EX_H
#define EX_H
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct numerou{
  float value
  numerou* next;
}

typedef struct Repre{
  float mean;
  float sd;
  float se;
  float skewness;
  float kurtosis;
}Repre;

typedef struct seiseki{
  int ID;
  int kaiseki;
  int senkei;
  int seibutsu;
  int sum;
  float DV_kaiseki;
  float DV_senkei;
  float DV_seibutsu;
  float DV_sum;
  float value;
  seiseki* prev;
  seiseki* next;
}Class;


extern void numberGet(FILE* fpt,float* c);
extern void numberPut(FILE* fpt,float* d);
extern float average(float a,float b);
extern void yamlPut(FILE* fpt,char* term,void* value,int type,int mode);

#endif
