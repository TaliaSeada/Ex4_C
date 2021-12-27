#ifndef __LIST_H__

#define __LIST_H__

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create_node(int);
void add_first(Node**, int);
void add_last(Node**, int);
void delete(Node**);
void print_list(Node*);
void remove_node(Node**, int);

#endif