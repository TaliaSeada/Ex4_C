#include <stdlib.h>
#include <stdio.h>
#include "Edge.h"

edge* create_edge(pnode node, int weight){
    edge* n=(edge*)malloc(sizeof(edge));
    if(n){
        n -> weight = weight;
        n -> endpoint = node;
        n -> next = NULL;
    }
    return n;
}
void add(edge** H,pnode node, int data){
    edge* n = create_edge(node, data);
    if(!n){
        printf("no memory!");
        return;
    }
    if(!*H){
        *H = n;
        return;
    }
    edge* tmp = *H;
    while(tmp->next)
        tmp = tmp->next;
    tmp->next = n;
}

void delete(edge** H){
    while(*H){
        edge* tmp = *H;
        *H = (*H)->next;
        free(tmp);
    }
}

void print_list(edge* H){
    while(H){
        printf("%d -> ", H->endpoint->node_num);
        H = H->next;
    }
    printf("|");
}

void remove_edge(edge** H, int dest){
    if(!*H)
        return;
    if((*H)->endpoint->node_num== dest){
        edge* tmp = *H;
        *H = (*H)->next;
        free(tmp);
    }
    edge* tmp = *H;
    while(tmp->next && tmp->next->endpoint->node_num != dest)
        tmp = tmp->next;
    if(!tmp->next)
        return;
    edge* tmp2 = tmp->next;
    tmp->next = tmp->next->next;
    free(tmp2);
}