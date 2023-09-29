#ifndef TABLE_H
#define TABLE_H

#include "../util/dataType.h"

struct table_t;

struct table_t* new_table();

void createTable(struct table_t* table, char* name, size_t columnsNumber, enum DataType* types);

void table_dctor(struct table_t*);
#endif