# include <stdio.h>
# include <stdlib.h>

// recursive DFS graph

struct node {
    int vertex;
    struct node *next;
};

struct graph {
    int numVertices;
    int *visited;
    struct node **adjLists;
};

void DFS(struct graph *graph, int vertex) {
    struct node *adjList = graph->adjLists[vertex];
    struct node *temp = adjList;

    graph->visited[vertex] = 1;
    printf("visited %d \n", vertex);

    while (temp != NULL) {
        int connectedVertex = temp->vertex;

        if (graph->visited[connectedVertex] == 0){
             DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

// Create node
struct node* createNode(int v) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create graph
struct graph* createGraph(int vertices) {
    struct graph *graph = malloc(sizeof(struct graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct  node*));
    graph->visited = malloc(vertices * sizeof(int));


    for (int i=0; i<vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// Add edge
void addEdge(struct graph *graph, int src, int dest) {
    struct node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void printGraph(struct graph *graph) {
    for (int i=0; i<graph->numVertices; i++) {
        struct node *temp = graph->adjLists[i];
        printf("\n Adjacent list of vertex %d\n", i);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct graph *graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    printGraph(graph);

    DFS(graph, 2);
}

