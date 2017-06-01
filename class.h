#ifndef CLASS_H
#define CLASS_H
#include"ex.h"


extern int getClassFile(FILE* fpt,Class* class);
extern void sumToValue(Class* head);
extern void DV_sumToValue(Class* head);
extern int addClassFile(FILE* fpt,Class* head);
extern void SwapClass(Class* a,Class* b);
extern Class* mergeList(Class* list1,Class* list2);
extern Class* mergeSort(Class* p);
extern void putClassFile(FILE* fp,Class* head);
extern void putClassFileDV(FILE* fp,Class* head);
extern void freeClass(Class* head);
#endif
