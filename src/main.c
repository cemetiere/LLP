#include "../include/table/table.h"
#include "../include/util/dataType.h"
#include <stdlib.h>
int main(){
    struct table_t* table1 = new_table();
    enum DataType types[3] = {INT, STRING, BOOl};
    createTable(table1, "hui", 3, types);
    free(table1);
}