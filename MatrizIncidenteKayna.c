#include <stdio.h>



void createMatriz(int **mat, int origin, int nvertice, int destin, int *graus, int naresta, int direct);
void imprimiGrau(int *graus, int nvertice);
void grafoComplementar(int **mat, int nvertice, int naresta);
void grafoSubjacente(int **mat, int nvertice, int naresta);

int main(){
    
    int choice;

    // inicializa as variaveis
    int nvertice, naresta, origin, destin, direct;

    printf("Grafo Orientado(1) ou nao orientado(0): ");
    scanf("%d", &direct);

    printf("Digite o numero de vertices: ");
    scanf("%d", &nvertice);

    printf("Digite o numero de aresta: ");
    scanf("%d", &naresta);

    int **mat = malloc(nvertice * sizeof(int));
    int *graus = malloc(nvertice * sizeof(int));

    // inicializa a matriz e o array com zeros(0's)
    for(int x = 0; x < nvertice; x++){
        for(int y = 0; y < naresta; y++){
            mat[x] = malloc(naresta * sizeof(int));
            mat[x][y]=0;
        }
        graus[x] = 0;
    }


    // inicia o menu
    while(1) {
        printf("\n*** Menu ***\n");
        printf("1. Resultado\n");
        printf("2. Ordem e Tamanho\n");
        printf("3. Vizinhanca e Graus\n");
        printf("4. grafo complementar\n");
        printf("5. grafo subjacente\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Você escolheu a Opção 1.\n");
                createMatriz(mat, origin,nvertice, destin,graus,naresta,direct);
                
                break;
            case 2:
                printf("Ordem: %d\nTamanho: %d\n", nvertice, naresta);
                
                break;
            case 3:
                printf("Você escolheu a Opção 3.\n");
                imprimiGrau(graus, nvertice);
                break;
            case 4:
                grafoComplementar(mat, nvertice, naresta);
                break;
            case 5:
                if(direct){
                    grafoSubjacente(mat, nvertice, naresta);
                    
                } else {
                    printf("Seu grafo nao eh direcionado");
                }
                return 0;
            default:
                printf("Opção inválida. Por favor, escolha uma opção válida.\n");
        }
    }

    free(mat);
    free(graus);
    return 0;
}



void createMatriz(int **mat, int origin, int nvertice, int destin, int *graus, int naresta, int direct){

    for(int x = 0; x < naresta; x++){
        printf("Insira a relacao de incidencia entre origin e destino: ");
        scanf("%d %d", &origin,&destin);

        mat[origin][x] = 1;
        mat[destin][x] = (direct ? -1 : 1);

        
        if(origin == destin){
            graus[origin] += 2;
        } else {
            graus[origin]++;
            graus[destin]++;
        }
        
    }

    for(int x = 0; x < nvertice; x++){
        for(int y = 0; y < naresta; y++){
            printf("%d  ", mat[x][y]);
        }
        printf("\n");
    }
}


void imprimiGrau(int *graus, int nvertice){
    // imprimi os graus dos vertices
    for(int x = 0; x < nvertice; x++){  
        printf("graus(%d) : %d\n",x, graus[x]);
    }
}


void grafoComplementar(int **mat, int nvertice, int naresta){
    // monta grafo complementar
    for (int x = 0; x < nvertice; x++){
        for (int y = 0; y < naresta; y++){
            if(mat[x][y] == 0){
                mat[x][y] = 1;
            } else {
                mat[x][y] = 0;
            }
        }
    }

    // printa grafo complementar
    for(int x = 0; x < nvertice; x++){
        for(int y = 0; y < naresta; y++){
            printf("%d  ", mat[x][y]);
        }
        printf("\n");
    }
}

void grafoSubjacente(int **mat, int nvertice, int naresta){
    // monta grafo complementar
    for (int x = 0; x < nvertice; x++){
        for (int y = 0; y < naresta; y++){
            if(mat[x][y] == -1){
                mat[x][y] = 1;
            }
        }
    }

    // printa grafo complementar
    for(int x = 0; x < nvertice; x++){
        for(int y = 0; y < naresta; y++){
            printf("%d  ", mat[x][y]);
        }
        printf("\n");
    }
}