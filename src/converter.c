#include <string.h>
#include "../include/converter.h"

struct TableHeader *convertFileNodeToTableHeader( struct FileNode *fileNode) {
    return (struct TableHeader *) ((char *) fileNode->name) + strlen(fileNode->name) + 1;
}


void *getBlockData( struct BlockHeader *blockHeader) {
    return ((char *) blockHeader) + sizeof(struct BlockHeader);
}

struct BlockHeader *convertTableHeaderToBlockHeader( struct TableHeader *tableHeader) {
    return (struct BlockHeader *) ((char *) tableHeader - tableHeader->offsetFromBlockBegin);
}
struct FileNode* convertBlockHeaderToFileNode(struct BlockHeader* blockHeader) {
    return (struct FileNode*) getBlockData(blockHeader);

}
