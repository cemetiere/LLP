#ifndef LAB1_ABSTRACT_HASHMAP_H
#define LAB1_ABSTRACT_HASHMAP_H

#include <stdint.h>
#include <stdbool.h>
#include "../types.h"

static const float defaultLoadFactor = 0.75f;
enum KeyType {
    KEY_STRING,
    KEY_UINT64_T
};
struct __attribute__((__packed__)) HashMap {
    enum KeyType keyType;
    uint32_t capacity;
    uint32_t countElementStored;

};

struct __attribute__((__packed__)) ColumnData {
    enum DataType dataType;
    uint32_t columnNum;
    void *data;
};

struct __attribute__((__packed__)) ColumnNode {
    struct ColumnNode *nextNode;
    struct ColumnNode *prevNode;
    void *key;
    void *data;
};

uint32_t elementIndex(struct HashMap *map, const void *key);

bool keysEquals(struct HashMap *map, const void *key1, const void *key2);

void *getData(struct HashMap *map);

#endif

