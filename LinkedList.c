#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"

Node* create_node(int data){
    Node* n = (Node*)malloc(sizeof(Node));
    if(n)
        n->data=data;
    return n;
}

void add_first(Node** H, int data){
    Node* n = create_node(data);
    if(!n){
        printf("no memory!");
        return;
    }
    n->next = *H;
    *H = n;
}

void add_last(Node** H, int data){
    Node* n = create_node(data);
    if(!n){
        printf("no memory!");
        return;
    }
    if(!*H){
        *H = n;
        return;
    }
    Node * tmp = *H;
    while(tmp->next)
        tmp = tmp->next;
    tmp->next = n;
}

void delete(Node** H){
while(*H){
Node* tmp = *H;
*H = (*H)->next;
free(tmp);
}
}

void print_list(Node* H){
    while(H){
        printf("%d -> ", H->data);
        H = H->next;
    }
    printf("||\n");
}

void remove_node(Node** H, int data){
    if(!*H)
        return;
    if((*H)->data == data){
        Node *tmp = *H;
        *H = (*H)->next;
        free(tmp);
    }
    Node* tmp = *H;
    while(tmp->next && tmp->next->data != data)
        tmp = tmp->next;
    if(!tmp->next)
        return;
    Node *tmp2 = tmp->next;
    tmp->next = tmp->next->next;
    free(tmp2);
}