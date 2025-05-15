#include "node.h"

node* createNode(int value, node* next, node* prev){
    node* n = (node *)malloc(sizeof(node));
    n->value = value;
    n->next = next;
    n->prev = prev;

    return n;
}

node* appendNode(node* head,node* n){

    if (head){
        node* tmp = head;
        while (tmp->next != NULL){
            tmp = tmp->next;
        }

        tmp->next = n;

        return head;
    } else {
        return n;
    }

}

node* appendNodeToStart(node* head, node* n){

    if (!n) return head;

    n->prev = NULL;

    if ( head ){
        head->prev = n;
        n->next = head;
    }

    return n;

}

void deleteNode(node* n){

    if (n){
        if (n->next) n->next->prev = n->prev;
        if (n->prev) n->prev->next = n->next;

        free(n);
    }

}

node* findNode(node* head, int value){

    if ( head ){
        node* tmp = head;
        while (tmp){
            if(tmp->value == value){
                break;
            }
            tmp = tmp->next;
        }

        return tmp;
    }

    return NULL;

}

node* getLastNode(node* head){

    if ( head ){
        node* tmp = head;
        while (tmp->next != NULL){
            tmp = tmp->next;
        }

        return tmp;
    }

    return NULL;
}