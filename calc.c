#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "ex.h"


void calcRepre(float a[],Repre* arg,int N){
  int i;

  for(i=0;i<N;i++){
    arg->mean+=a[i];
  }
    arg->mean/=N;

    for(i=0;i<N;i++){
      arg->sd+=pow((a[i]-arg->mean),2);
      arg->skewness+=pow((a[i]-arg->mean),3);
      arg->kurtosis+=pow((a[i]-arg->mean),4);
    }
    arg->sd/=N;
    arg->sd=sqrt(arg->sd);
    arg->se=arg->sd/sqrt(N);
    arg->skewness/=pow(arg->sd,3);
    arg->kurtosis/=pow(arg->sd,4);
    arg->kurtosis-=3;

}
