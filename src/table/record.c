#include "../../include/record.h"

struct RecordData *prepareRecordDataStructure(struct TableHeader *tableHeader) {
    struct RecordData *recordData = malloc(sizeof(struct RecordData));
    void **data = calloc(tableHeader->columnCount, sizeof(void *));
    recordData->data = data;
    recordData->unreadData = NULL;
    recordData->rowPageBlock = NULL;
    recordData->columns = NULL;
    return recordData;
}

void freeRecordData(struct RecordData *recordData) {
    free(recordData->data);
    free(recordData->columns);
    unmapPage(recordData->rowPageBlock);
    free(recordData);
}

void clearRecordDataToReadFromBegin(struct RecordData *recordData) {
    recordData->unreadData = NULL;
    recordData->rowPageBlock = NULL;
}


