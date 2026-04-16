#include "matriz.h"


int main (void){
    unsigned int colunas = 1, linhas = 1;
    /* unsigned int pois a matriz não pode ter colunas ou linhas negativas*/

    /*Recebe os valores de linhas e colunas*/
    puts("#Escalonamento de matrizes!#");
    puts("Qual é o tamanho da matriz?");
    printf("Tamanho da linha: ");//tamanho da linha
    scanf("%d", &linhas);
    printf("\n");
    printf("Tamanho da colunas: ");//tamano da coluna
    scanf("%d", &colunas);
    printf("\n");
    
    puts("Digite os elementos da matriz!\n");
    float a[linhas][colunas]; //declaração da matriz
    /*Recebe os elementos da matriz em um looping*/
    receber_matriz(linhas, colunas, a);
  
    /*Printa a matriz na tela para a visualizanção*/
    printar_matriz(linhas, colunas, a);

    int matriz_nula = verify_null (linhas, colunas, a); //variavel controle que se falsa essa matriz é uma matriz nula.
  
    if (matriz_nula == 1){ //retorna para o usuario que a matriz é nula.
        printf("Essa matriz é nula!\nE não pode ser escalonada.\n");
        return 0;
    }
    escalonar_matriz(linhas, colunas, a);

    puts("#matriz escalonada#");
    printar_matriz(linhas, colunas, a);

}

