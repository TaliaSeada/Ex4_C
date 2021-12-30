#include <stdio.h>
#include "graph.c"
#include "Edge.c"

int main() {
    //   A 4 n 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2 D 2 B 5 0 4 2 1 t
    node* graph = NULL;
    int read=getchar();
    int numOfNodes, i, id, dest, weight;
    int succeed;
    char n;
    while(65<=read && read<=90) {
        switch (read) {
            case 'A':
                getchar();
                scanf("%d", &numOfNodes);
                scanf("%c", &n);
                scanf("%c", &n);
                i = 0;
                for (i = 0; i < numOfNodes; i++) {
                    scanf("%d", &id);
                    if (i == 0) {
                        graph = create_node(id);
                    }
                    pnode current_node = graph;
                    // check if node exists
                    while (current_node) {
                        if (current_node->node_num == id) {
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
                    succeed=scanf("%d",&dest);
                    while (succeed) {
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
                            add(&current_node->edges, node_dst, weight);
                        }
                            // else create it
                        else {
                            pnode node_dst = create_node(dest);
                            insert_node_cmd(&graph, node_dst);
                            add(&current_node->edges, node_dst, weight);
                        }
                        if(getchar()==' '){
                            succeed=scanf("%d",&dest);
                        }
                        else{
                            break;
                        }
                    }
                    read = getc(stdin);
                    if (read != 'n') {
                        break;
                    }
                }
                printGraph_cmd(graph);
                break;
            case 'B':
                // B 5 0 4 2 1
                read = getchar();
                int id;
                scanf("%d", &id);

                pnode current_node = graph;
                // check if node already exists
                while (current_node) {
                    if (current_node->node_num == id) {
                        break;
                    }
                    current_node = current_node->next;
                }
                // if not create it
                if (!current_node) {
                    current_node = create_node(id);
                    insert_node_cmd(&graph, current_node);
                }
                // if it exists, override the out edges with the new given ones
                pedge edge_tmp = current_node -> edges;
                while(edge_tmp){
                    pedge remove_edges = edge_tmp;
                    edge_tmp = edge_tmp -> next;
                    free(remove_edges);
                }
                current_node ->edges = NULL;

                // create new edges:
                int destN;
                int weight;
                scanf("%d", &destN);
                scanf("%d", &weight);

                while(read == 32){
                    pnode dest_node = graph;
                    // check if DestNode exists
                    while (dest_node) {
                        if (dest_node->node_num == destN) {
                            break;
                        }
                        dest_node = dest_node->next;
                    }
                    // if not create it
                    if (!dest_node) {
                        dest_node = create_node(destN);
                        insert_node_cmd(&graph, dest_node);
                    }

                    // add the new edge to the new node
                    add(&current_node->edges, dest_node, weight);

                    scanf("%d", &destN);
                    scanf("%d", &weight);
                    read = getchar();
                }
                printGraph_cmd(graph);
                break;
            case 'D':
                read = getchar();
                int s;
                int node;
                scanf("%d", &node);
                pnode n = create_node(node);
                delete_node_cmd(&graph, n);
                // printGraph_cmd(graph);
                free(n);
                read = getchar();
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
                break;
        }
    }

    deleteGraph_cmd(&graph);
    return 0;
}
