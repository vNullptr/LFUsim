#pragma once

#include "hashtable.h"
#include "node.h"
#include <stdio.h>

typedef struct {

    HashTable T;
    node *head, *tail;
    int curr_size,size;

} Cache;

Cache createCache(int size);
void put(Cache *C, int value);
void show(Cache *C);