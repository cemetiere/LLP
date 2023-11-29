cmake_minimum_required(VERSION 3.22.1)
project(llp_database C)

set(CMAKE_C_STANDARD 17)

add_library(llp_database
        src/hashmap/abstract_hashmap.c
        src/hashmap/memory_hashmap.c
        src/hashmap/table_hashmap.c
        src/table/record.c
        src/table/table.c
        src/allocator.c
        src/comparator.c
        src/converter.c
        src/database.c
        src/types.c
        include/hashmap/abstract_hashmap.h
        include/hashmap/memory_hashmap.h
        include/hashmap/table_hashmap.h
        include/allocator.h
        include/block.h
        include/comparator.h
        include/converter.h
        include/database.h
        include/record.h
        include/status.h
        include/table.h
        include/types.h
)

add_executable(test src/main.c
    src/hashmap/abstract_hashmap.c
    src/hashmap/memory_hashmap.c
    src/hashmap/table_hashmap.c
    src/table/record.c
    src/table/table.c
    src/allocator.c
    src/comparator.c
    src/converter.c
    src/database.c
    src/types.c
    include/hashmap/abstract_hashmap.h
    include/hashmap/memory_hashmap.h
    include/hashmap/table_hashmap.h
    include/allocator.h
    include/block.h
    include/comparator.h
    include/converter.h
    include/database.h
    include/record.h
    include/status.h
    include/table.h
    include/types.h
)

