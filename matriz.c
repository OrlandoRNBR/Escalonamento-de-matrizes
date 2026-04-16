#include "matriz.h"

void receber_matriz(int linhas, int colunas,float a [linhas][colunas]){ //recebe uma matriz 
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

void printar_matriz(int linhas, int colunas,float a [linhas][colunas]){//mostra a matriz na tela
   for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("%g  ", a[i][j]); //printa uma elemento especificamente uma linha
        }
        puts("|"); // pula a linha.
    }
}

int verify_null(int linhas, int colunas,float a [linhas][colunas]){ //verifica se a matriz é nula
int matriz_nula = 0; //variavel controle que se falsa essa matriz é uma matriz nula.
    for(int i = 0; i < linhas; i++){ 
        for(int j = 0; j < colunas; j++){
            if(a[0][0] == 0 && a[0][0] == a[i][j]) matriz_nula = 1;
             //verificação verifica se a11 é igual a 0 e se todos os itens são iguais a a logo todos os itens são iguais 0
             else matriz_nula = 0;
        }
    }
    return matriz_nula;
}

void troca_linha(int linhas ,float a [linhas], float b[linhas]){ //troca as linhas da matriz de lugar
    float temp; //variavel temporaria
    for(int i = 0; i < linhas; i++){ //looping que troca elemento por elemento da matriz
        temp = a[i]; 
        a[i] = b[i];
        b[i] = temp;
    }
}

void pivo_sub (int colunas,float l1[colunas],float l2[colunas], int indice_pivo){
    float pivo = l2[indice_pivo]/l1[indice_pivo]; //escalar que multilica a linha
    for(int i = 0; i < colunas; i++)  l2[i] = l2[i] - (pivo*l1[i]); // looping que faz a operação de multiplicação e subtração
    
}


void mul_linha(int linhas,float a[linhas], float k){ //multiplica a linha inteira por um escalar
    for(int i = 0; i< linhas; i++){
        a[i] = a[i]*k;
    }
}

void sub_linha(int linhas ,float a [linhas], float b[linhas]){ //subtrai uma linha de outra
    for(int i = 0; i < linhas; i++){ // subtrai item por item da linha e armazena na prineira
        a[i] = a[i] - b[i];
    }
}

void add_linha(int linhas ,float a [linhas], float b[linhas]){ //soma uma linha de outra
    for(int i = 0; i < linhas; i++){ // soma item por item da linha e armazena na prineira
        a[i] = a[i] + b[i];
    }
}

void escalonar_matriz(int linhas, int colunas, float a[linhas][colunas]){

    int j = 0;
    for (int i  = 0; i < linhas; i++){ // looping para escalonar a matriz
        int controle = 0;//variavel de controle para caso a primeira coluna seja completamente 0
        if(a[0][0] == 0){ // se a [0][0] = 0  ele procura uma linha q seja diferente de 0 para trocar
            for (int i = 1; i < linhas; i++){ //navega pela coluna
                if (a[i][0] !=0 ){ // se achar um elemento diferente de 0 troca as linhas
                    troca_linha(linhas, a[i], a[0]);  //troca as linhas.
                }else if (a[0][0] == 0 && a[i][0] == a[0][0]) controle++; // se não achar a primera coluna inteira é 0 essa varivel vai ser usada para 
                                                                                                            //somar nas proxima alaterações para ele não mecher nessa coluna.
            }
        }
    
        for (int b = i +1; b < linhas; b++) //navega pela linha do pivo
            if(a[b][j] != 0) // se o elemento for diferente de zero faz a operação
                pivo_sub(colunas, a[i], a[b], i);//faz aoperação elementar
        
        j++;
    }
}
