#include <stdio.h>


float soma_de_matrizes (float A[][], float B [][], int num_linhas,int num_colunas){
    float c[num_linhas][num_colunas];
    for(int i = 0; i < num_linhas;i++){
        for(int j = 0; j < num_colunas;j++ ){
            c[i][j] = A[i][j] + B[i][j];
        }
    }
    return c;
}