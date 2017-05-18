#include <stdio.h>
#include<stdlib.h>
#include<string.h>

float average(float a,float b){

  if(a<0||b<0){
    fprintf(stdout, "error number is not positive\n");
    exit(1);
  }
return (a+b)/2.0;
}
