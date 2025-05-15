add_library(LFUlib STATIC
        hashtable.c
        node.c
        cache.c
)

target_include_directories(LFUlib
        PUBLIC
        ${PROJECT_SOURCE_DIR}/includes
)