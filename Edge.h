#ifndef __Edge__
#define __Edge__

typedef struct GRAPH_NODE_ *nodep;

// LinkedList of edges
typedef struct edge_ {
    int weight;
    nodep endpoint;
    struct edge_* next;
} edge, *pedge; //head of the list

edge* create_edge(nodep, int);
void add(edge**, nodep, int);
void delete(edge**);
void print_list(edge*);
void remove_edge(edge**, int);
#endif
