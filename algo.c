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
        dist[i] = (INT_MAX);
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
    if(dist[dest]==INT_MAX || dist[dest]==INT_MIN){
        return -1;
    }
    return dist[dest];
}
int TSP(pnode *head){
    int size = 0;
    scanf("%d", &size);
    int nodes[size];
    int j;
    for (j = 0; j < size; j++) {
        scanf("%d", &nodes[j]);
    }
    int min_dist=INT_MAX;
    pnode tmp = *head;
    // pnode point_to_list = *head;
    int i;
    for(i=0; i<size;i++){
        int current=0;
        int src_id = nodes[i];
        int nodes_temp[size];
        int j;
        for(j=0;j<size;j++){
            nodes_temp[j]=nodes[j];
        }
        nodes_temp[i]=-1;
        while(1){
            int ans;
            int current_dest;
            int min_current=INT_MAX;
            for(j=0;j<size;j++) {
                if (nodes_temp[j] != -1) {
                    tmp = *head;
                    ans = shortest_path(&tmp, src_id,nodes_temp[j]);
                    if(ans<min_current && ans!=-1 && ans>0){
                        min_current=ans;
                        current_dest=j;
                    }
                    if(ans<0 || ans == -1){
                        min_current=INT_MAX;
                        current=INT_MAX;
                        break;
                    }
                }
            }
            if(min_current==INT_MAX){
                break;
            }
            current+=min_current;
            nodes_temp[current_dest]=-1;
            src_id=nodes[current_dest];
        }
        if(current<min_dist){
            min_dist=current;
        }
    }
    if(min_dist==INT_MAX){
        return -1;
    }
    return min_dist;
}
