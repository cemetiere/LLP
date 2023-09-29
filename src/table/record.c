#include <stdlib.h>
#include "field.h"
#include "record.h"
typedef struct {
    struct field_t* field;
    int index;
} record_t;

record_t* record_new(){
    return (field_t*)malloc(sizeof(field_t));
}
void record_ctor(record_t* record){

}
void record_dtor(record_t* record){

}