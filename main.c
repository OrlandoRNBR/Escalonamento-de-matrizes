#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

    int j = 0;
    for (int i  = 0; i < linhas; i++){ // looping para escalonar a matriz
        int controle = 0;//variavel de controle para caso a primeira coluna seja completamente 0
        if(a[0][0] == 0){ // se a [0][0] = 0  ele procura uma linha q seja diferente de 0 para trocar
            puts("Elemento a[0][0] = a 0 execultando troca de linha!");
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

    puts("#matriz escalonada#");
    printar_matriz(linhas, colunas, a);

}





/*#ERROS DE LOGICA #*/
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

    /*
    for (int i = 0; i   < linhas; i++){//navega pelas linhas
        for(int j = 0; j < colunas; j++){ //navega pelas colunas
            
            
            
            if(i == j){ // se ele estiver olhando para o elemento da diagonal principal A mn ele execulta esse bloco
                
               /* float v_temp[linhas];
               for (int c = 0; c < linhas; c++) v_temp[c] = a[i][c];
                for (int c = 0; c < linhas; c++) printf("%g",v_temp[c]);
                printf("\n");*/
/*
                for(int b = i + 1; b < linhas; b++){ //navega só pela coluna que esta esse elemento
                    if (a[b][j] == 0 && i != j){ //se for igual a 0 mostra essa mensagem
                        printf("escalonando matriz: pivo a[%d][%d]\nnenhuma alteração feita na linha %d\n", i , j, b);
                    } else{
                        printf("Escalonando matriz: pivo a[%d][%d]\nEscalonado linha do elemento a[%d][%d]\n", a[b][j]);
                            pivo_sub(colunas, a[i], a[b], b);
                        printar_matriz(linhas, colunas, a);
                    }
                }
            }
        }
    }*/