#include "hashtable.h"
#include <stdio.h>

int hash(int value){
    return value;
}

void initHashTable(HashTable* T){

    for(int i=0; i<HASH_SIZE; i++){
        T->table[i] = NULL;
    }

}

node* get(HashTable* T,int value){

    if (!T->table[hash(value)]) return NULL;

    node* tmp = T->table[hash(value)];

    while (tmp){
        if (tmp->value == value) return tmp;
        tmp = tmp->next;
    }

    return NULL;

}

node* insert(HashTable* T,node* newNode){

    int index = hash(newNode->value);
    if (T->table[index]){
        appendNode(T->table[index], newNode);
    } else {
        T->table[index] = newNode;
    }

    return newNode;
}

void detach(HashTable* T,node* n){

    if (!n) return;

    int index = hash(n->value);
    node* tmp = T->table[index];

    while (tmp){
        if (tmp == n){
            if (tmp->prev){
                if (tmp->next) tmp->next->prev = tmp->prev;
                if (tmp->prev) tmp->prev->next = tmp->next;
            } else {
                if (tmp->next) tmp->next->prev = NULL;
                T->table[index] = tmp->next;
            }
            break;
        }
        tmp = tmp->next;
    }

}
