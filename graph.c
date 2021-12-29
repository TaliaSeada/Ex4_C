#include <stdlib.h>
#include "graph.h"
#include "Edge.h"

//typedef struct GRAPH_NODE_ *pnode ;

node* create_node(int id) {
    node* n = (node *) malloc(sizeof(node));
    if (n) {
        n->node_num = id;
        n->edges = NULL;
        n->next = NULL;
    }
    return n;
}

void insert_node_cmd(node** head, pnode node){
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

void delete_node_cmd(pnode* head, pnode node){
    if(!*head)
        return;
    if((*head)->node_num == node->node_num){
        pnode tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
    pnode tmp = *head;
    // TODO check memory leak on tmp
    while(tmp->next && tmp->next->node_num != node->node_num)
        tmp = tmp->next;
    if(!tmp->next)
        return;
    //free edges
    pedge edge_tmp = tmp ->next->edges;
    while(edge_tmp -> next){
        pedge remove_edges = edge_tmp;
        edge_tmp = edge_tmp -> next;
        free(remove_edges);
    }
    //remove node
    pnode tmp2 = tmp->next;
    tmp->next = tmp->next->next;
    free(tmp2);
    pnode tmp3 = *head;
    while(tmp3 -> next){
        remove_edge(&(tmp3->edges), node->node_num);
        tmp3 = tmp3 -> next;
    }
}

void printGraph_cmd(pnode head){
    while(head){
        printf("%d (", head -> node_num);
        print_list(head -> edges);
        printf(") -> ");
        head = head->next;
    }
    printf("||\n");
}

void deleteGraph_cmd(pnode* head){

}

void shortsPath_cmd(pnode head){

}

void TSP_cmd(pnode head){

}