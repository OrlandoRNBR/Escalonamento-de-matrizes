#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

    /*Recebe os elementos da matriz em um looping*/
    puts("Digite os elementos da matriz!");
    float a[linhas][colunas]; //declaração da matriz
    for(int i = 0; i < linhas; i++){
        //printf("Looping em: %d\n", j); ta aqui por conta de um erro de logica
        for(int j = 0; j < colunas; j++){
            //printf("Looping em: %d\n", j); ta aqui por conta de um erro de logica
            printf("Item a%d%d: ", i+1, j+1);
            scanf("%f",&a[i][j]); //recebe o elemento e armazena na posição especifica da matriz
            printf("\n");
        }
    }
    /*Printa a matriz na tela para a visualizanção*/
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("%g", a[i][j]);
        }
        printf("\n");
    }
}