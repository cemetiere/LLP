#include "../../include/table/table.h"
#include <memory.h>
#include <stdlib.h>

typedef struct table_t{
    char* name;
    size_t columnsNumber;
    enum DataType* types;
}table_t;

table_t* new_table(){
    return (table_t*) malloc(sizeof(table_t));
};

void createTable(table_t* table, char* name, size_t columnsNumber, enum DataType* types){
    table->name = name;
    table-> columnsNumber = columnsNumber;
    table->types = types;
};