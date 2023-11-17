#include <stdio.h>
#include "matriz.h"
#include <stdbool.h>

int main() {
  Mat *matA = NULL, *matB = NULL, *matC = NULL;
  int opcao = 0;

  while (true) {
    printf("======= MENU =======\n\n");
    printf("1- Criar matriz A\n");
    printf("2- Criar matriz B\n");
    printf("3- Ler e inserir os dados da matriz A\n");
    printf("4- Ler e inserir os dados da matriz B\n");
    printf("5- Calcular a multiplicação de A por B e imprimir o resultado\n");
    printf("6- Calcular a transposta de A e imprimir o resultado\n");
    printf("7- Destruir a matriz A\n");
    printf("8- Destruir a matriz B\n");
    printf("9- Sair\n");

    printf("Digite a opção que você quer: ");
    scanf("%d", &opcao);

    switch (opcao) {
      case 1:
          if (matA == NULL) {
              int linhaA = 0, colunaA = 0;
              printf("Digite o número de linhas e colunas para matriz A: ");
              scanf("%d %d", &linhaA, &colunaA);
              matA = criarMatriz(linhaA, colunaA);
              printf("A matriz A foi criada.\n\n");
          } else {
              printf("Matriz A já foi criada.\n");
          }
          break;
      case 2:
          if (matB == NULL) {
              int linhaB = 0, colunaB = 0;
              printf("Digite o número de linhas e colunas para matriz B: ");
              scanf("%d %d", &linhaB, &colunaB);
              matB = criarMatriz(linhaB, colunaB);
              printf("Matriz B foi criada.\n\n");
          } else {
              printf("Matriz B já foi criada.\n");
          }
          break;
      case 3:
          if (matA != NULL) {
              lerMatriz(matA);
          } else {
              printf("A matriz A não foi criada.\n");
          }
          break;
      case 4:
          if (matB != NULL) {
              printf("Digite os elementos da matriz B:\n");
              lerMatriz(matB);
          } else {
              printf("A matriz B não foi criada.\n");
          }
          break;
      case 5:
          if (matA != NULL && matB != NULL) {
              matC = multMatriz(matA, matB);
              if (matC != NULL) {
                  printf("Resultado da multiplicação:\n");
                  imprimirMatriz(matC);
              } else {
                  printf("A multiplicação não é possível. Verifique as dimensões das matrizes.\n");
              }
          } else {
              printf("As matrizes A e B devem ser criadas antes da multiplicação.\n");
          }
          break;
      case 6:
          if (matA != NULL) {
              Mat *transpostaA = transpostaMatriz(matA);
              if (transpostaA != NULL) {
                  printf("Transposta de A:\n");
                  imprimirMatriz(transpostaA);
                  destruirMatriz(transpostaA);
              } else {
                  printf("Erro ao calcular a transposta de A.\n");
              }
          } else {
              printf("A matriz A deve ser criada antes de calcular a transposta.\n");
          }
          break;
      case 7:
          if (matA != NULL) {
              destruirMatriz(matA);
              matA = NULL;
              printf("Matriz A destruída.\n");
          } else {
              printf("A matriz A não foi criada.\n");
          }
          break;
      case 8:
          if (matB != NULL) {
              destruirMatriz(matB);
              matB = NULL;
              printf("Matriz B destruída.\n");
          } else {
              printf("A matriz B não foi criada.\n");
          }
          break;
      case 9:
          // sair
          if (matA != NULL) {
              destruirMatriz(matA);
          }
          if (matB != NULL) {
              destruirMatriz(matB);
          }
          if (matC != NULL) {
              destruirMatriz(matC);
          }
          return false;
          break;
      default:
          printf("Opção inválida. Tente novamente.\n\n");
          break;
    }
  }

  return 0;
}
