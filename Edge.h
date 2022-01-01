#ifndef __Edge__
#define __Edge__


typedef struct GRAPH_NODE_ *pnode;

// LinkedList of edges
typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_* next;
} edge, *pedge; //head of the list

edge* create_edge(pnode, int);
void add(edge**, pnode, int);
void delete(edge**);
void print_list(edge*);
void remove_edge(edge**, int);
#endif
