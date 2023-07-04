#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdbool.h>

// Tamanho do tabuleiro
const int TAM = 3;

// Constantes para verdadeiro e falso
const int VERDADEIRO = 1;
const int FALSO = 0;

// Protótipos das funções
void escreverTabuleiro(char matriz[][TAM]);
void preencherTabuleiro(char matriz[][TAM], int linha, int coluna, char jogador);
bool verificarVitoria(char matriz[][TAM], char jogador);
bool verificarEmpate(char matriz[][TAM]);
void verificaJogo(char matriz[][TAM], char jogador);
bool jogarNovamente();
void reiniciarJogo(char matriz[][TAM]);

#endif  // FUNCOES_H
