#ifndef __GRAPH__
#define __GRAPH__
#include "Edge.h"

//typedef struct edge_ *pedge;

// LinkedList of nodes
typedef struct GRAPH_NODE_ {
    int node_num; //id
    pedge edges; //list of edges
    struct GRAPH_NODE_ *next;
} node, *pnode; //head of the list

node* create_node(int id);
void build_graph_cmd(pnode *head);
void insert_node_cmd(pnode *head, pnode node);
void delete_node_cmd(pnode *head, pnode node);
void printGraph_cmd(pnode head); //for self debug
void deleteGraph_cmd(pnode* head);
void shortsPath_cmd(pnode head);
void TSP_cmd(pnode head);

#endif
