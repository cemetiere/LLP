
#ifndef TYPES_H
#define TYPES_H

#include <stdlib.h>

#include <string.h>

enum DataType {
    BOOL_TYPE = 0,
    INT_TYPE = 1,
    STRING_TYPE = 2,
    DOUBLE_TYPE = 3,
};

size_t dataTypeLen(enum DataType dataType, void *data);
#endif 

