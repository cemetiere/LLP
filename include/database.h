#ifndef DATABASE_H
#define DATABASE_H

#include <stdint.h>
#include "block.h"
#include "types.h"
#include "table.h"
#include "comparator.h"

#include "./hashmap/table_hashmap.h"
#include "allocator.h"
#include "converter.h"

struct DatabaseHeader;


int32_t openDatabaseFileOrCreate(const char *path);

int32_t closeDatabaseFile(void);

int32_t createTable(const char *name, int32_t columnNum, enum DataType *types, const char **names);

int32_t deleteTable(const char *name);

int32_t deleteTableByHeader(struct TableHeader *tableHeader);

int32_t getTable(struct TableHeader **table, const char *name);

int32_t freeTable(struct TableHeader *tableHeader);

struct __attribute__((__packed__)) DatabaseHeader {
    uint64_t size;
    struct BlockCoordinate tableMapPage;
    struct BlockCoordinate freeList;
};

struct BlockCoordinate getFreeList(void);
void setFreeListHeader(struct BlockCoordinate bc);

struct DatabaseHeader *getDatabaseHeader(void);

#endif

