#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct {
    int linhas;
    int colunas;
    int *data;
} Mat;

Mat *criarMatriz(int linha, int coluna);
void destruirMatriz(Mat *matriz);
void lerMatriz(Mat *matriz);
void imprimirMatriz(Mat *matriz);
Mat *multMatriz(Mat *A, Mat *B);
Mat *transpostaMatriz(Mat *matriz);

#endif 