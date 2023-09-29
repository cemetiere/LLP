#ifndef TYPE_H
#define TYPE_H
#include <memory.h>
enum DataType{
    INT,
    STRING,
    FLOAT,
    BOOl
};

size_t dataTypeSize(enum DataType dataType, void* data);


#endif