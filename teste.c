#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int vertex;
    struct node* next;
} node;

typedef struct Graph {
    int numVertices;
    node** adjLists;
} Graph;

node* createNode(int v) {
    node* newNode = malloc(sizeof(node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(node*));
   
    int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest, int is_directed) {
    node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src - 1];
    graph->adjLists[src - 1] = newNode;

    if (!is_directed) {
        newNode = createNode(src);
        newNode->next = graph->adjLists[dest - 1];
        graph->adjLists[dest - 1] = newNode;
    }
}

void printGraph(Graph* graph) {
    int v;
    for (v = 0; v < graph->numVertices; v++) {
        node* temp = graph->adjLists[v];
        printf("\n Lista de adjacência do vértice %d\n ", v + 1);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int vertices, edges, i, src, dest, is_directed;
    printf("Digite o número de vértices: ");
    scanf("%d", &vertices);
    printf("Digite o número de arestas: ");
    scanf("%d", &edges);
    printf("O grafo é orientado? Digite 1 para Sim e 0 para Não: ");
    scanf("%d", &is_directed);

    Graph* graph = createGraph(vertices);
    for (i = 0; i < edges; i++) {
        printf("Entre com a aresta %d origem e destino (exemplo: 1 2): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest, is_directed);
    }

    printGraph(graph);
    return 0;
}