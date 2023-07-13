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
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    if (!is_directed) {
        newNode = createNode(src);
        newNode->next = graph->adjLists[dest];
        graph->adjLists[dest] = newNode;
    }
}

void printGraph(Graph* graph) {
    int v;
    printf("\nLista de adjacencia\n");
    for (v = 0; v < graph->numVertices; v++) {
        node* temp = graph->adjLists[v];
        printf("\nVertice %d-> ", v);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

void vizinhacaGrau(Graph* graph) {
    int v, grau[graph->numVertices];
    for(v = 0; v < graph->numVertices; v++){
        grau[v] = 0;
    }
    printf("\nLista de Vizinhaca\n");
    for (v = 0; v < graph->numVertices; v++) {
        node* temp = graph->adjLists[v];
        printf("Vertice %d:", v);
        while (temp) {
            printf(" %d", temp->vertex);
            temp = temp->next;
            grau[v]++;
        }
        printf("\n");
    }
    printf("\nLista de Grau\n");
    for (v = 0; v < graph->numVertices; v++) {
        node* temp = graph->adjLists[v];
        printf("Vertice %d tem grau:", v);
        while (temp) {
            temp = temp->next;
        }
        printf(" %d\n", grau[v]);
    }
}

int main() {
    int op, vertices, edges, i, src, dest, is_directed;
    printf("O grafo e orientado? Digite 1 para Sim e 0 para Nao: ");
    scanf("%d", &is_directed);
    printf("Digite o numero de vertices: ");
    scanf("%d", &vertices);
    printf("Digite o numero de arestas: ");
    scanf("%d", &edges);

    Graph* graph = createGraph(vertices);
    for (i = 0; i < edges; i++) {
        printf("Entre com a aresta %d origem e destino (exemplo: 1 2): ", i);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest, is_directed);
    }

    do{
        printf("------------------------------\n");
        printf("1- Apresentar a lista resultada do grafo\n");
        printf("2- Apresentar a ordem e o tamanho do grafo\n");
        printf("3- Apresentar a vizinhanca e grau de todos os vertices\n");
        printf("0- Sair\n");
        printf("Informe a opcao desejada:\n");
        
        scanf("%d", &op);
        switch(op){
            case 1:
                printGraph(graph);
            break;
            case 2:
                //Exibindo o tamanho e ordem do grafo
                printf("------------------------------\n");
                printf("O seu grafo tem ordem %d e tamanho %d. \n", vertices, edges);
                break;
            break;
            case 3:
                //Exibindo os graus e vizinhaca dos vertices
                vizinhacaGrau(graph);
            break;
            case 0:
                
            break;
        }
    }while(op != 0);
    return 0;
}