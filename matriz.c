#include <stdlib.h>
#include <stdio.h>
#include "matriz.h"

// Função para criar uma matriz com o número especificado de linhas e colunas
Mat *criarMatriz(int linha, int coluna) {
    // Aloca memória para a estrutura da matriz
    Mat *matriz = (Mat *)malloc(sizeof(Mat));
    if (matriz != NULL) {
        // Inicializa o número de linhas e colunas
        matriz->linhas = linha;
        matriz->colunas = coluna;

        // Aloca memória para os elementos da matriz
        matriz->data = (int *)malloc(sizeof(int) * linha * coluna);
        if (matriz->data == NULL) {
            free(matriz);
            return NULL;
        }
    }
    return matriz;
}

// Função para destruir uma matriz e liberar a memória alocada
void destruirMatriz(Mat *matriz) {
    if (matriz != NULL) {
        free(matriz->data);
        free(matriz);
    }
}

// Função para ler os elementos de uma matriz a partir da entrada padrão (teclado)
void lerMatriz(Mat *matriz) {
    if (matriz != NULL) {
        printf("Digite os elementos da matriz (%d x %d):\n", matriz->linhas, matriz->colunas);
        for (int i = 0; i < matriz->linhas; i++) {
            for (int j = 0; j < matriz->colunas; j++) {
                scanf("%d", &(matriz->data[i * matriz->colunas + j]));
            }
        }
    }
}

// Função para imprimir os elementos de uma matriz
void imprimirMatriz(Mat *matriz) {
    if (matriz != NULL) {
        for (int i = 0; i < matriz->linhas; i++) {
            for (int j = 0; j < matriz->colunas; j++) {
                printf("%d ", matriz->data[i * matriz->colunas + j]);
            }
            printf("\n");
        }
    }
}

// Função para multiplicar duas matrizes A e B e retornar o resultado em uma nova matriz
Mat *multMatriz(Mat *A, Mat *B) {
    if (A != NULL && B != NULL && A->colunas == B->linhas) {
        // Cria uma matriz para armazenar o resultado da multiplicação
        Mat *matrizC = criarMatriz(A->linhas, B->colunas);
        if (matrizC != NULL) {
            for (int i = 0; i < A->linhas; i++) {
                for (int j = 0; j < B->colunas; j++) {
                    matrizC->data[i * B->colunas + j] = 0;
                    for (int k = 0; k < A->colunas; k++) {
                        matrizC->data[i * B->colunas + j] += A->data[i * A->colunas + k] * B->data[k * B->colunas + j];
                    }
                }
            }
        }
        return matrizC;
    }
    return NULL;
}

// Função para calcular a transposta de uma matriz
Mat *transpostaMatriz(Mat *matriz) {
    if (matriz != NULL) {
        // Cria uma nova matriz com as dimensões trocadas
        Mat *transposta = criarMatriz(matriz->colunas, matriz->linhas);
        if (transposta != NULL) {
            for (int i = 0; i < matriz->linhas; i++) {
                for (int j = 0; j < matriz->colunas; j++) {
                    // Copia os elementos da matriz original na posição transposta
                    transposta->data[j * transposta->colunas + i] = matriz->data[i * matriz->colunas + j];
                }
            }
        }
        return transposta;
    }
    return NULL;
}
