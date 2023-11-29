#ifndef CONVERTER_H
#define CONVERTER_H

#include "block.h"
#include "table.h"

struct TableHeader *convertFileNodeToTableHeader(struct FileNode *fileNode);

void *getBlockData(struct BlockHeader *blockHeader);

struct BlockHeader *convertTableHeaderToBlockHeader(struct TableHeader *tableHeader);

struct FileNode *convertBlockHeaderToFileNode(struct BlockHeader *blockHeader);

#endif
