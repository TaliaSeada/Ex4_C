//#include <stdlib.h>
//#include <stdio.h>
//#include "LinkedList.h"
//
//Edge* create_node(int data){
//    Edge* n = (Edge*)malloc(sizeof(Edge));
//    if(n)
//        n->data=data;
//    return n;
//}
//
//void add_first(Edge** H, int data){
//    Edge* n = create_node(data);
//    if(!n){
//        printf("no memory!");
//        return;
//    }
//    n->next = *H;
//    *H = n;
//}
//
//void add_last(Edge** H, int data){
//    Edge* n = create_node(data);
//    if(!n){
//        printf("no memory!");
//        return;
//    }
//    if(!*H){
//        *H = n;
//        return;
//    }
//    Edge* tmp = *H;
//    while(tmp->next)
//        tmp = tmp->next;
//    tmp->next = n;
//}
//
//void delete(Edge** H){
//    while(*H){
//        Edge* tmp = *H;
//        *H = (*H)->next;
//        free(tmp);
//    }
//}
//
//void print_list(Edge* H){
//    while(H){
//        printf("%d -> ", H->data);
//        H = H->next;
//    }
//    printf("||\n");
//}
//
//void remove_node(Edge** H, int data){
//    if(!*H)
//        return;
//    if((*H)->data == data){
//        Edge *tmp = *H;
//        *H = (*H)->next;
//        free(tmp);
//    }
//    Edge* tmp = *H;
//    while(tmp->next && tmp->next->data != data)
//        tmp = tmp->next;
//    if(!tmp->next)
//        return;
//    Edge *tmp2 = tmp->next;
//    tmp->next = tmp->next->next;
//    free(tmp2);
//}