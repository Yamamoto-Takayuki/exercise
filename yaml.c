#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ex.h"

void yamlPut(FILE* fpt,char* term,void* value,int type,int mode){

	int* i_value;
	float* f_value;
	double* d_value;

	if(term==0) {
		i_value=(int*)value
		         fprintf(fpt,"%s:%d\n",term,*i_value);
	}else if(term==1) {
		f_value=(float*)value;
		fprintf(fpt,"%s:%15.6g\f",term,*f_value);
	}else{
		d_value=(double*)value;
		fprintf(fpt,"%s:%15.6g\f",term,*d_value);
	}
}
