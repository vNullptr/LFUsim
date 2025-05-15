#pragma once
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next, *prev;
} node;

node* createNode(int value, node* next, node* prev);
node* appendNode(node* head, node* n);
node* appendNodeToStart(node* head, node* n);
void deleteNode(node* n);
node* findNode(node* head, int value);
node* getLastNode(node* head);