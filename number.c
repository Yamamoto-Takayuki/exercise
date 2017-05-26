#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int numberGet(FILE* fpt,float* c){
  char buf[256];;
  if(NULL==fgets(buf,256,fpt)){
    fprintf(stdout, "file is empty");
    return 0;
  }

  *c=(float)atof(buf);
  if(isnan(c)){
    fprintf(stdout, "Not a Number\n");
    return 0;
  }
  return 1;
}

void numberPut(FILE* fpt,float* d){
  fprintf(fpt, "%f\n",*d);
}
