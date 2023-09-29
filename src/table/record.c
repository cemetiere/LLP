#include <stdlib.h>
#include "../../include/table/record.h"
typedef struct record_t{
    struct field_t* field;
    int index;
} record_t;

record_t* record_new(){
    return (record_t*) malloc(sizeof(record_t));
}
void record_ctor(record_t* record, int fieldCount){

}
void record_dtor(record_t* record){

}