#include "../include/database.h"
#include <stdio.h>
#include <assert.h>

#include <time.h>


static char *rand_string(size_t size)
{
    char *str = (char *) malloc(size + 1);
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (size) {
        --size;
        for (size_t n = 0; n < size; n++) {
            int key = rand() % (int) (sizeof charset - 1);
            str[n] = charset[key];
        }
        str[size] = '\0';
    }
    return str;
}

static void insertTest() {
    enum DataType dataType[8] = {INT_TYPE, BOOL_TYPE, DOUBLE_TYPE, STRING_TYPE, INT_TYPE, BOOL_TYPE, DOUBLE_TYPE,
                                 STRING_TYPE};
    const char *names[8] = {"col1", "col2", "col3", "col4", "col5", "col6", "col7", "col8"};
    createTable("test", 8, dataType, names);
    struct TableHeader *tableHeader;
    getTable(&tableHeader, "test");
    struct RecordData *recordData = prepareRecordDataStructure(tableHeader);
    int32_t col1;
    bool col2;
    double col3;
    char *col4;
    int32_t col5;
    bool col6;
    double col7;
    char *col8;

    for (int j = 1; j <= 100000; j++) {
        col1 = rand();
        col2 = rand() % 2 == 0;
        col3 = (double)rand() * 1.0 / rand();
        col4 = rand_string(15);
        col5 = rand();
        col6 = rand() % 2 == 0;
        col7 = (double)rand() * 1.0 / rand();
        col8 = rand_string(15);
        recordData->data[0] = &col1;
        recordData->data[1] = &col2;
        recordData->data[2] = &col3;
        recordData->data[3] = col4;
        recordData->data[4] = &col5;
        recordData->data[5] = &col6;
        recordData->data[6] = &col7;
        recordData->data[7] = col8;

        addRow(tableHeader, recordData);
        free(col4);
        free(col8);

    }


}

static void readTest(void) {
    struct TableHeader *th;
    getTable(&th, "test");
    struct RecordData *rc = prepareRecordDataStructure(th);
    int t = 0;
    while (readRecord(rc, th) == 0) {
        t++;
    }
    printf("read: %d\n", t);

}


static void updateTest(void) {
    struct TableHeader *th;
    getTable(&th, "test");
    int minVal = -999999;
    int maxVal = 0;
    int newVal = 12345;
    struct Operand leftOperand = {true, {.columnName="col1"}};

    struct FreeVariable freeVariableMin = {INT_TYPE, &minVal};
    struct FreeVariable freeVariableMax = {INT_TYPE, &maxVal};
    struct Operand rightOperandMin = {false, {.freeVariable = &freeVariableMin}};
    struct Operand rightOperandMax = {false, {.freeVariable = &freeVariableMax}};
    struct Condition condition1 = {leftOperand, rightOperandMin, MORE};
    struct Condition condition2 = {leftOperand, rightOperandMax, LESS};
    struct Condition conditions[2] = {condition1, condition2};
    struct FreeVariable col1 = {INT_TYPE, &newVal};
    struct Operand ageOperand = {false, {&col1}};

    struct UpdateColumnValue updateColumnValue1 = {"col1", ageOperand};

    updateRow(th, 1, &updateColumnValue1, 2, conditions);

}
static void deleteTest(void) {
    struct TableHeader *th;
    getTable(&th, "test");
    int minVal = -100000;
    int maxVal = 100000;
    struct Operand leftOperand = {true, {.columnName="col1"}};

    struct FreeVariable freeVariableMin = {INT_TYPE, &minVal};
    struct FreeVariable freeVariableMax = {INT_TYPE, &maxVal};
    struct Operand rightOperandMin = {false, {.freeVariable = &freeVariableMin}};
    struct Operand rightOperandMax = {false, {.freeVariable = &freeVariableMax}};
    struct Condition condition1 = {leftOperand, rightOperandMin, MORE};
    struct Condition condition2 = {leftOperand, rightOperandMax, LESS};
    struct Condition conditions[2] = {condition1, condition2};

    int32_t deleted = deleteRow(th, 2, conditions);
    printf("%d\n", deleted);
}

int main(int argc, char **argv) {
    openDatabaseFileOrCreate("./test.file");

    insertTest();
    printf("Finished insertTest\n");

    // readTest();
    // printf("Finished readTest\n");

    // updateTest();
    // printf("Finished updateTest\n");

    // deleteTest();
    // printf("Finished deleteTest\n");

    closeDatabaseFile();
    return 0;
}

