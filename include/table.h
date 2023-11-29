#ifndef TABLE_H
#define TABLE_H

#include "types.h"
#include "block.h"
#include "record.h"
#include "comparator.h"
#include "allocator.h"
#include "./hashmap/memory_hashmap.h"
#include "converter.h"

struct __attribute__((__packed__)) RowPage {
    struct BlockCoordinate nextRowPage;
    struct BlockCoordinate prevRowPage;
    int32_t rowCount;
    uint64_t freeSpaceOffsetStart;
    uint64_t freeSpaceOffsetEnd;

};
struct __attribute__((__packed__)) Column {
    enum DataType dataType;
    char name[];
};

struct __attribute__((__packed__)) RowPointer {
    bool isToDelete;
    uint64_t offset;
};

struct __attribute__((__packed__)) TableHeader {
    uint64_t offsetFromBlockBegin;
    struct BlockCoordinate firstRowPage;
    int32_t columnCount;
    int32_t rowCount;

};
struct __attribute__((__packed__)) FileNode {
    struct BlockCoordinate nextTableHeader;
    struct BlockCoordinate prevTableHeader;
    char name[];
};

struct __attribute__((__packed__)) FreeListNode {
    struct BlockCoordinate nextTableHeader;
    struct BlockCoordinate prevTableHeader;
};


struct Column;

struct TableHeader;

int32_t allocTable(struct BlockHeader **bh, const char *name, int32_t columnNum, const enum DataType *types,
                   const char **names);


struct __attribute__((__packed__)) JoinResult {
    struct TableHeader *tableHeader;
    struct RecordData *recordData; 
};

int32_t addRow(struct TableHeader *tableHeader, struct RecordData *recordData);

int32_t readRecord(struct RecordData *recordData, struct TableHeader *tableHeader);

int32_t deleteRow(struct TableHeader *tableHeader, int32_t conditionCount, struct Condition *conditions);

int32_t
updateRow(struct TableHeader *tableHeader, int32_t updateColumnsCount, struct UpdateColumnValue *updateColumnValues,
          int32_t conditionCount, struct Condition *conditions);

int32_t selectWithConditions(struct RecordData *recordData, struct TableHeader *tableHeader, int32_t conditionCount,
                             struct Condition *conditions);

int32_t joinTables(struct JoinResult *joinResult, int32_t selectColumnsNum, struct TableAliasAndColumn *selectColumns,
                   int32_t joinTablesNum, struct JoinTablesHeaders *joinTables,
                   int32_t joinConditionNum, struct JoinCondition *joinCondition,
                   int32_t filtersNum, struct JoinWhereCondition *joinWhereCondition);

#endif
