#include "cache.h"

Cache createCache(int size){

    Cache C;
    initHashTable(&C.T);
    C.head = C.tail = NULL;
    C.curr_size = 0;
    C.size = size;

    return C;

}

void put(Cache *C, int value){

    if (get(&C->T, value)){ // hit
        printf("hit [%i]", value);
        if (C->curr_size == 1) return;

        node* toMove = findNode(C->head,value);
        if (toMove->next) toMove->next->prev = toMove->prev;
        if (toMove->prev) toMove->prev->next = toMove->next;
        C->head = appendNodeToStart(C->head, toMove);

    } else {
        printf("miss [%i]", value);
        if (C->curr_size == C->size) {
            printf("[full]");
            node* toDelete = C->tail;
            detach(&C->T, get(&C->T,toDelete->value));
            C->tail = toDelete->prev;
            deleteNode(toDelete);

            if (C->tail){
                C->tail->next = NULL;
            }

            C->curr_size--;

        }

        node* LRUNode = createNode(value, NULL, NULL);

        insert(&C->T, LRUNode);

        C->head = appendNodeToStart(C->head, LRUNode);
        if (!C->tail) C->tail = LRUNode;

        C->curr_size++;

    }

}

void show(Cache *C){

    if (C->head){
        node* tmp = C->head;
        printf("[DEBUT]:");
        while (tmp->next){
            printf("%i->", tmp->value);
            tmp = tmp->next;
        }
        printf("%i:[FIN]\n", tmp->value);
    } else {
        printf("[!] Cache vide.\n");
    }

}

