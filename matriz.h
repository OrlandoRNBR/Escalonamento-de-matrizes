#pragma once

#include <stdio.h>
#include <stdlib.h>


void receber_matriz(int linhas, int colunas,float a [linhas][colunas]);

void printar_matriz(int linhas, int colunas,float a [linhas][colunas]);

int verify_null(int linhas, int colunas,float a [linhas][colunas]);

void troca_linha(int linhas ,float a [linhas], float b[linhas]);

void pivo_sub (int colunas,float l1[colunas],float l2[colunas], int indice_pivo);

void mul_linha(int linhas,float a[linhas], float k);

void sub_linha(int linhas ,float a [linhas], float b[linhas]);

void add_linha(int linhas ,float a [linhas], float b[linhas]);

void escalonar_matriz(int linhas, int colunas, float a[linhas][colunas]);

void add_matriz(int linhas, int colunas, float a[linhas][colunas], float b[linhas][colunas]);

void sub_matriz(int linhas, int colunas,float a[linhas][colunas],float b[linhas][colunas]);

void mul_matriz(int linhas, int colunas, a[linhas][colunas], b[linhas][colunas]);