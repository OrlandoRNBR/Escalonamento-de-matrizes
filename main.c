#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void receber_matriz(int linhas, int colunas,float a [linhas][colunas]){
    for(int i = 0; i < linhas; i++){
        //printf("Looping em: %d\n", j); ta aqui por conta de um erro de logica
        for(int j = 0; j < colunas; j++){
            //printf("Looping em: %d\n", j); ta aqui por conta de um erro de logica
            printf("Item a%d,%d: ", i+1, j+1);
            scanf("%f",&a[i][j]); //recebe o elemento e armazena na posição especifica da matriz
            printf("\n");
        }
    }
}

void printar_matriz(int linhas, int colunas,float a [linhas][colunas]){
   for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("%g  ", a[i][j]);
        }
        printf("\n");
    }
}

int verify_null(int linhas, int colunas,float a [linhas][colunas]){
int matriz_nula = 0; //variavel controle que se falsa essa matriz é uma matriz nula.
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            if(a[0][0] == 0 && a[0][0] == a[i][j]) matriz_nula = 1;
             //verificação verifica se a11 é igual a 0 e se todos os itens são iguais a a logo todos os itens são iguais 0
        }
    }
    return matriz_nula;
}

void troca_linha(int linhas ,float a [linhas], float b[linhas]){
    float temp;
    for(int i = 0; i < linhas; i++){
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

void mul_linha(int linhas,float a[linhas], float k){
    for(int i = 0; i< linhas; i++){
        a[i] = a[i]*k;
    }
}

void sub_linha(int linhas ,float a [linhas], float b[linhas]){
    for(int i = 0; i < linhas; i++){
        a[i] = a[i] - b[i];
    }
}

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
    
    puts("Digite os elementos da matriz!");
    float a[linhas][colunas]; //declaração da matriz
    /*Recebe os elementos da matriz em um looping*/
    receber_matriz(linhas, colunas, a);
  
    /*Printa a matriz na tela para a visualizanção*/
    printar_matriz(linhas, colunas, a);


    int matriz_nula = verify_null (linhas, colunas, a); //variavel controle que se falsa essa matriz é uma matriz nula.
  
    if (matriz_nula == 1){ //retorna para o usuario que a matriz é nula.
        printf("Essa matriz é nula!\nE não pode ser escalonada.");
        return 0;
    }

    int controle = 0;//variavel de controle para caso a primeira coluna seja completamente 0
    if(a[0][0] == 0){ // se a [0][0] = 0  ele procura uma linha q seja diferente de 0 para trocar
        for (int i = 1; i < linhas; i++){ //navega pela coluna
            if (a[i][0] !=0 ){ // se achar um elemento diferente de 0 troca as linhas
                troca_linha(linhas, a[i], a[0]);  //troca as linhas.
            }  else if (a[0][0] == 0 && a[i][0] == a[0][0]) controle++; // se não achar a primera coluna inteira é 0 essa varivel vai ser usada para 
                                                                                                            //somar nas proxima alaterações para ele não mecher nessa coluna.
        }
    }
    //verficação da matriz
    for (int i = 0; i   < linhas; i++){//navega pelas linhas
        for(int j = 0; j < colunas; j++){ //navega pelas colunas
            if(i == j){ // se ele estiver olhando para o elemento da diagonal principal A mn ele execulta esse bloco
                for(int b = i + 1; b < linhas; b++){ //navega só pela coluna que esta esse elemento
                    if (a[b][j] == 0){ //se for igual a 0 mostra essa mensagem
                        printf("escalonado matriz pivo a%d,%d nenhuma alteração feita na linha %d\n", i , j, b);
                    }
                }
            }
        }
    }

}






   /*
 int matriz_escalonada = 0, matriz_escalonada_vetor = 0;

esse bolo de for e if verifica se a matriz esta escalonada
    for(int i = 0; i < linhas; i++){ //navega pela matriz
        for(int j = 0; j < colunas; j++){
            if(i == j){ //verifica se o elemento é da diagonal
                for(int b = 0; b < linhas; b++){ //navega por uma coluna especifica para verificar se os elementos são iguais a 0
                    if(a[b][j] == 0) { // verifica se o elemento é igual a 0
                       matriz_escalonada = 1;
                        printf(" a[%d][%d] =%g\n ", b, j , a[b][j]); // mostra os elementos que apareceram
                    } else if (a[b][j] != 0 && i != j){
                        verif[b] = a[b][j]; //bota os elementos q não são 0 no vetor 
                        matriz_escalonada = 0;
                    }
                }
            }
        }
    }

     for(int i = 0; i < 10; i++) printf("%g", verif[i]);
     printf("\n");
    for(int w = 0; w < 10; w++){ // verifica se a ,atriz esta escalonada
        if (verif[9] == 0 && verif[0] == verif[w]) matriz_escalonada_vetor = 1;
        else matriz_escalonada_vetor = 0;
    }

    if(matriz_escalonada == 1 && matriz_escalonada_vetor == 1){ //printa se a matrris esta escalonada
        printf("Essa matriz ja esta escalonada!\n");
        return 0;
    }else printf("Essa matriz não está escalonada!\n"); // printa se ela está.
*/








 /*
 tava na linha 71
 
 int matriz_identidade = 0;
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            if((a[0][0] == 0 && a[0][0] == a[i][j] )|| (a[i][i] == 1 && a[2][0] == 0 && a[0][2] == 0) ) matriz_identidade = 1;
        }
    }
    if (matriz_identidade == 1){ //retorna para o usuario que a matriz é a a matris identidade.
        printf("Essa matriz é a matriz identidade\nE já está escalonada!");
        return 0;
    }
   esse for para verificar se a matriz ja esta escalonada não funciona ainda
    1 1 1 1
    1 0 1 1
    1 0 0 1 essa matriz foi verificada como escalonada*/