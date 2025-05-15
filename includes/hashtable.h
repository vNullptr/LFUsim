#pragma once
#include "node.h"

#define HASH_SIZE 10

typedef struct{
    node* table[HASH_SIZE];
} HashTable;


int hash(int value);
void initHashTable(HashTable* T);
node* get(HashTable* T,int value);
node* insert(HashTable* T,node* newNode);
void detach(HashTable* T,node* n);
