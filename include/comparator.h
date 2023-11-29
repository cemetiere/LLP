#ifndef COMPARATOR_H
#define COMPARATOR_H

#include "block.h"
#include "types.h"
#include "table.h"

#include <string.h>
#include "./hashmap/abstract_hashmap.h"


enum Operator {
    MORE, LESS, EQUALS
};

struct FreeVariable {
    enum DataType dataType;
    void *operand;
};

struct Operand {
    bool isOperandAName;
    union {
        struct FreeVariable *freeVariable;
        char *columnName;
    } operandValue;
};
struct Condition {
    struct Operand left;
    struct Operand right;
    enum Operator op;
};

struct CompareResult {
    int32_t errorCode;
    int32_t compareResult;
};

struct UpdateColumnValue {
    char *name;
    struct Operand assignedValue;
};
struct JoinTablesHeaders {
    struct TableHeader *tableHeader;
    char *tableAlias;
};
struct JoinOperand {
    char *tableAlias;
    char *columnName;
};
struct JoinCondition {
    struct JoinOperand leftOperand;
    struct JoinOperand rightOperand;
    enum Operator operator;
};
struct TableAliasAndColumn {
    char *aliasName;
    char *columnName;
};

struct JoinWhereOperand {
    bool isOperandAName;
    union {
        struct FreeVariable *freeVariable;
        struct TableAliasAndColumn *nameAndColumn;
    } operandValue;
};
struct JoinWhereCondition {
    struct JoinWhereOperand leftOperand;
    struct JoinWhereOperand rightOperand;
    enum Operator operator;
};

struct CompareResult compareColumns(struct ColumnData left, struct ColumnData right);

bool validateCompareResult(enum Operator operator, int32_t compareResult);

bool areTypesComparable(enum DataType dt1, enum DataType dt2);


#endif 
