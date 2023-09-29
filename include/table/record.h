#ifndef RECORD
#define RECORD
#include "field.h"

struct record_t;

//record allocation 
struct record_t* record_new();

void record_ctor(struct record_t*, int fieldCount);
void record_dtor(struct record_t*);
    
#endif