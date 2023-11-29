#ifndef TABLE_HASHMAP_H
#define TABLE_HASHMAP_H

#include "../block.h"
#include "../table.h"
#include "abstract_hashmap.h"
#include "../allocator.h"
#include "../block.h"
#include "../database.h"

int32_t addTableInMap(struct BlockHeader *mapBlock, struct BlockHeader *tableBlock);

int32_t initFreeFileMapAndReturnBlock(struct BlockHeader **bh, enum KeyType keyType);

int32_t createBiggerMap(struct BlockHeader **bh, struct HashMap *map);

int32_t getTableByNameAndReturnBlock(struct BlockHeader **bh, struct HashMap *map, const void *key);

int32_t removeTableFromMap(struct BlockHeader *mapBlock, struct BlockHeader *tableBlock);

#endif

