#include "../../include/util/dataType.h"

size_t dataTypeSize(enum DataType dataType, void* data){
    size_t dataSize;
    switch (dataType)
    {
    case STRING:
        dataSize = strlen(data)+1;
        break;
    case INT:
        dataSize = 4;
        break;
    case BOOl:
        dataSize = 1;
        break;
    default:
        dataSize = 4;
        break;
    }
    return dataSize;
}