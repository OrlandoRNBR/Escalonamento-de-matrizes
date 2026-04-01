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
            printf("Item a%d,%d: ", i+1, j+1);
            scanf("%f",&a[i][j]); //recebe o elemento e armazena na posição especifica da matriz
            printf("\n");
        }
    }
    /*Printa a matriz na tela para a visualizanção*/
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("%g  ", a[i][j]);
        }
        printf("\n");
    }


    int matriz_nula = 0; //variavel controle que se falsa essa matriz é uma matriz nula.
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            if(a[0][0] == 0 && a[0][0] == a[i][j]) matriz_nula = 1;
             //verificação verifica se a11 é igual a 0 e se todos os itens são iguais a a logo todos os itens são iguais 0
        }
    }
    if (matriz_nula == 1){ //retorna para o usuario que a matriz é nula.
        printf("Essa matriz é nula!\nE não pode ser escalonada.");
        return 0;
    }

    /*int matriz_identidade = 0;
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            if((a[0][0] == 0 && a[0][0] == a[i][j] )|| (a[i][i] == 1 && a[2][0] == 0 && a[0][2] == 0) ) matriz_identidade = 1;
        }
    }
    if (matriz_identidade == 1){ //retorna para o usuario que a matriz é a a matris identidade.
        printf("Essa matriz é a matriz identidade\nE já está escalonada!");
        return 0;
    }*/
   
   /*esse for para verificar se a matriz ja esta escalonada não funciona ainda
    1 1 1 1
    1 0 1 1
    1 0 0 1 essa matriz foi verificada como escalonada*/
 int matriz_escalonada = 0, matriz_escalonada_vetor = 0;

 float v[100]; //vetor para verificar matriz é escalonada
 for(int k = 0; k < 100; k++) v[k] = 0; // deveria encher o vetor de 0 mas não faz
 for(int f = 0; f < 100; f++) printf("%d", v[f] ); //mostra se o vetor estar cheio de zeros mas não ta amostrnado
 /*consertar isso ai depois */
/*esse bolo de for e if verifica se a matriz esta escalonada*/
    for(int i = 0; i < linhas; i++){ //navega pela matriz
        for(int j = 0; j < colunas; j++){
            if(i == j){ //verifica se o elemento é da diagonal
                for(int b = 0; b < linhas; b++){ //navega por uma coluna especifica para verificar se os elementos são iguais a 0
                    if(a[b][j] == 0) { // verifica se o elemento é igual a 0
                       //matriz_escalonada = 1;
                        v[b] = a[b][j]; 
                        printf(" a[%d][%d] =%g\n ", b, j , a[b][j]); // mostra os elementos que apareceram
                    } else v[b] = a[b][j]; //bota os elementos q não são 0 no vetor 
                }
            }
        }
    }

    for(int w = 0; w < 100; w++){ // verifica se a ,atriz esta escalonada
        if (v[0] == 0 && v[0] == v[w]) matriz_escalonada_vetor = 1;
    }

    if(matriz_escalonada == 1 && matriz_escalonada_vetor == 1){ //printa se a matrris esta escalonada
        printf("Essa matriz ja esta escalonada!\n");
        return 0;
    }else printf("Essa matriz não está escalonada!\n"); // printa se ela está.

    /*
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            
        }

    }*/


}