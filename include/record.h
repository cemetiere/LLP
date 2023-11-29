#ifndef RECORD_H
#define RECORD_H

#include <stdlib.h>
#include "block.h"
#include "table.h"
#include "allocator.h"


struct __attribute__((__packed__)) RecordData {
    struct BlockHeader *rowPageBlock;
    char *unreadData;
    struct Column **columns;
    void **data;
};


struct RecordData *prepareRecordDataStructure(struct TableHeader *tableHeader);

void freeRecordData(struct RecordData *recordData);

void clearRecordDataToReadFromBegin(struct RecordData *recordData);

#endif