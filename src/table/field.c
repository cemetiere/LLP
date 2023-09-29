#include <stdlib.h>
#include "field_type.h"
typedef struct {
    field_type type,
    union
} field_t;

field_t* field_new(){
    return (field_t*)malloc(sizeof(field_t));
};

void field_ctor(struct field_t*){

};
void field_dtor(struct field_t*){


};