#include <stdlib.h>
#include "graph.h"

typedef struct GRAPH_NODE_ *pnode ;

pnode create_node(int id) {
    node* n = (node *) malloc(sizeof(pnode));
    if (n) {
        n->node_num = id;
        n->edges = NULL;
        n->next = NULL;
    }
    return n;
}

void insert_node_cmd(pnode* head, pnode node){
    if(!node){
        printf("no memory!");
        return;
    }
    if(!*head){
        *head = node;
        return;
    }
    pnode tmp = *head;
    while(tmp->next) {
        tmp = tmp->next;
    }
    tmp->next = node;
}

void delete_node_cmd(pnode* head){

}

void printGraph_cmd(pnode head){

}

void deleteGraph_cmd(pnode* head){

}

void shortsPath_cmd(pnode head){

}

void TSP_cmd(pnode head){

}