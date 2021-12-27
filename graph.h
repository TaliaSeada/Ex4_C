#ifndef __GRAPH__
#define __GRAPH__

typedef struct GRAPH_NODE_ *pnode;

// LinkedList of edges
typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge; //head of the list

// LinkedList of nodes
typedef struct GRAPH_NODE_ {
    int node_num; //id
    pedge edges; //list of edges
    struct GRAPH_NODE_ *next;
} node, *pnode; //head of the list

void build_graph_cmd(pnode *head);
void insert_node_cmd(pnode *head);
void delete_node_cmd(pnode *head);
void printGraph_cmd(pnode head); //for self debug
void deleteGraph_cmd(pnode* head);
void shortsPath_cmd(pnode head);
void TSP_cmd(pnode head);

#endif
