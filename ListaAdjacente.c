#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{
   
    int numero;
    
    struct Lista *proximo;
}Lista;

typedef struct Grafo{
   
    Lista **vertices;
    
    int qtdV;
    int qtdA;
}*Grafo;

//Grafo inicialzaGrafo(int n);
void insereAresta(Grafo G, int origem, int destino);
void exibirListaAdjacente(Grafo G);

int main(int argc, char *argv[])
{

    int op, direcao, qtdV, origem, destino, maisAresta;
/*
    printf("-----Matriz de Adjacencia-----\n");
    printf("Escolha qual tipo do seu grafo: \n");
    printf("0 - Nao Direcional \n");
    printf("1 - Direcional \n");
    scanf("%d", &direcao);
*/
    printf("------------------------------\n");
    printf("Digite a quantidade de Vertices: ");    
    scanf("%d", &qtdV);

    Grafo G = malloc(sizeof *G);
    //inicializando o grafo com nenhuma aresta
    G->qtdV = qtdV;
    G->qtdA = 0;
    G->vertices = malloc(qtdV * sizeof(Lista *));
    for (int i=0; i < qtdV; i++){
        G->vertices[i] = NULL;
    }

    printf("Digite a origem e destino de cada aresta (exemplo: 1 2): ");
    scanf("%d %d", &origem, &destino);

    Lista *p;
    for(p = G->vertices[origem]; p != NULL; p = p->proximo){
        if(p->numero == destino)
            return;
    p = malloc(sizeof(Lista));
    p->numero = destino;
    p->proximo = G->vertices[origem];
    G->vertices[origem] = p;
    G->qtdA++;

    }
/*
    do{
        printf("Digite a origem e destino de cada aresta (exemplo: 1 2): ");
        scanf("%d %d", &origem, &destino);

        printf("Deseja inserir outra aresta? (1-Sim | 0-Nao)\n");
        scanf("%d", &maisAresta);

    }while(maisAresta == 1);
*/
    while(op != 0){
        printf("Lista Simplesmente Encadeada\n");
        printf("Informe a opcao desejada:\n");
        printf("1-Exibir a lista de adjacencia\n");
        printf("0-Sair\n");
        
        scanf("%d", &op);
        switch(op){
            case 1:
            
            break;
            case 0:
                
            break;
        }
    }
    
    return 0;
}
/*
//iniciando o Grafo com nenhuma aresta
Grafo inicialzaGrafo(int n){
    Grafo G = malloc(sizeof *G);
    G->qtdV = n;
    G->qtdA = 0;
    G->vertices = malloc(n * sizeof(Lista *));
    for (int i=0; i < n; i++){
        G->vertices[i] = NULL;
    }
    return G;
}
*/
void insereAresta(Grafo G, int origem, int destino){
    Lista *p;
    for(p = G->vertices[origem]; p != NULL; p = p->proximo){
        if(p->numero == destino)
            return;
    p = malloc(sizeof(Lista));
    p->numero = destino;
    p->proximo = G->vertices[origem];
    G->vertices[origem] = p;
    G->qtdA++;

    }
}

void exibirListaAdjacente(Grafo G){
    Lista *p;
    printf("%d %d\n", G->qtdV, G->qtdA);
    for(int i = 0; i < G-> qtdV; i++){
        for(p = G->vertices[i]; p != NULL; p = p->proximo){
            printf("%2d", p->numero);
        }
        printf("\n");
    }
}

Grafo liberaGrafo(Grafo G){
    Lista *p;
    for (int i = 0; i < G->qtdA; i++){
        p = G->vertices[i];
        while(p != NULL){
            G->vertices[i] = p;
            p = p->proximo;
            free(G->vertices[i]);
        }
        G->vertices[i] = NULL;
    }
    free(G->vertices);
    G->vertices = NULL;
    free(G);
    return NULL;
}