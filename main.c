#include <stdio.h>
#include "graph.c"
#include "Edge.c"

int main() {
    //   A 4 n 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2
    node *graph = NULL;
    int read=getchar();
    //scanf("%c", &read);
    int numOfNodes, i, id, dest, weight;
    char n;
    while(65<=read && read<=90) {
        switch (read) {
            case 'A':
                printf("A");
                getchar();
                scanf("%d", &numOfNodes);
                scanf("%s", &n);
                for (i = 0; i < numOfNodes; i++) {

                    scanf("%d", &id);
                    if (i == 0) {
                        graph = create_node(id);
                    }
                    pnode current_node = graph;
                    // check if node exists
                    while (current_node) {
                        if (current_node->node_num == id) {
                            //                        current_node=current_node->next;
                            break;
                        }
                        current_node = current_node->next;
                    }
                    // if not create it
                    if (!current_node) {
                        current_node = create_node(id);
                        insert_node_cmd(&graph, current_node);
                    }
                    // create the edges
                    while (scanf("%d", &dest)) {
                        scanf("%d", &weight);
                        pnode tmp = graph;
                        // check if dest node exists
                        while (tmp) {
                            if (tmp->node_num == dest) {
                                break;
                            }
                            tmp = tmp->next;
                        }
                        // if so
                        if (tmp) {
                            pnode node_dst = tmp;
                            pedge new_edge = create_edge(node_dst, weight);
                            add(&current_node->edges, node_dst, weight);
                        }
                            // else create it
                        else {
                            pnode node_dst = create_node(dest);
                            insert_node_cmd(&graph, node_dst);
                            add(&current_node->edges, node_dst, weight);
                        }
                    }
                    read = getchar();
                    if (read != 'n') {
                        break;
                    }
                }
                break;
            case 'B':
                printf("B");
                read = getchar();
                break;
            case 'D':
                printf("D");
                read = getchar();
                break;
            case 'S':
                printf("S");
                read = getchar();
                break;
            case 'T':
                printf("T");
                read = getchar();
                break;
            default:
                printf("wrong");
                read=-1;
                break;
        }
        if(read==-1){
            break;
        }
    }


    return 0;
}
