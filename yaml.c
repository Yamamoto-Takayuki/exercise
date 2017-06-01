#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ex.h"

void yamlPut(FILE* fpt,char* term,void* value,int type,int mode){

  char* c_value;
	int* i_value;
	float* f_value;
	double* d_value;
  if(type==0){
    c_value=(char*)value;
    fprintf(fpt,"%s:%s\n",term,value);
  }else if(type==1){
		i_value=(int*)value;
    fprintf(fpt,"%s:%d\n",term,*i_value);
	}else if(type==2) {
		f_value=(float*)value;
		fprintf(fpt,"%s:%15.6g\n",term,*f_value);
	}else{
		d_value=(double*)value;
		fprintf(fpt,"%s:%15.6g\n",term,*d_value);
	}
}
