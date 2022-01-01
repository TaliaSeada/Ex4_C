#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "algo.h"

int shortest_path(pnode* head, int src, int dest){
    int node_max_size = 0;
    pnode tmp = *head;
    while(tmp){
        if(node_max_size < tmp -> node_num){
            node_max_size = tmp -> node_num;
        }
        tmp = tmp -> next;
    }
    int dist[node_max_size+1];
    int visited [node_max_size+1];
    int i;
    for(i = 0; i < node_max_size+1; i++){
        dist[i] = (INT_MAX-1);
        visited[i] = -1;
    }
    tmp = *head;
    while (tmp){
        visited[tmp->node_num] = 1;
        tmp=tmp->next;
    }
    dist[src]=0;
    while(1){
        int min_node_id;
        int min_size = INT_MAX;
        tmp=*head;
        while (tmp){
            if (dist[tmp->node_num]<min_size && visited[tmp->node_num]==1){
                min_size = dist[tmp->node_num];
                min_node_id = tmp->node_num;
            }
            tmp = tmp->next;
        }
        if(min_size == INT_MAX){
            break;
        }
        int current_value;
        int new_value;
        tmp = *head;
        while(tmp->node_num!=min_node_id){
            tmp=tmp->next;
        }
        pedge tmp_edge=tmp->edges;
        while(tmp_edge){
            current_value=dist[tmp_edge->endpoint->node_num];
            new_value=dist[min_node_id]+tmp_edge->weight;
            if(new_value<current_value){
                dist[tmp_edge->endpoint->node_num]=new_value;
            }
            tmp_edge=tmp_edge->next;
        }
        visited[min_node_id]=-1;
    }
    if(dist[dest]==INT_MAX){
        return -1;
    }
    return dist[dest];
}
int TSP(pnode *head, int *nodes){
    return 0;
}
