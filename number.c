#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void numberGet(FILE* fpt,float* c){
  char buf[256];
  if(NULL==fgets(buf,256,fpt)){
    fprintf(stdout, "file is empty");
    *c=nanf("empty");
  }else if(strlen(buf)<=0){
    *c=nanf("empty");
  }else{
  *c=(float)atof(buf);
  }
}

void numberPut(FILE* fpt,float* d){
  fprintf(fpt, "%f\n",*d);
}
