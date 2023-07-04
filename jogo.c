#include <stdio.h>
#include "funcoes.h"

void escreverTabuleiro(char matriz[][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("| %c ", matriz[i][j]);
        }
        printf("|\n");
        if (i != TAM - 1) {
            printf("- - - - - - -\n");
        }
    }
}

void preencherTabuleiro(char matriz[][TAM], int linha, int coluna, char jogador) {
    matriz[linha][coluna] = jogador; // Preenche a posição escolhida com o jogador atual
}

bool verificarVitoria(char matriz[][TAM], char jogador) {
    // Verificar linhas e colunas
    for (int i = 0; i < TAM; i++) {
        if (matriz[i][0] == jogador && matriz[i][1] == jogador && matriz[i][2] == jogador)
            return true; // Vitoria na linha i
        if (matriz[0][i] == jogador && matriz[1][i] == jogador && matriz[2][i] == jogador)
            return true; // Vitoria na coluna i
    }

    // Verificar diagonais
    if (matriz[0][0] == jogador && matriz[1][1] == jogador && matriz[2][2] == jogador)
        return true; // Vitoria na diagonal principal
    if (matriz[0][2] == jogador && matriz[1][1] == jogador && matriz[2][0] == jogador)
        return true; // Vitoria na diagonal secundária

    return false; // Nenhuma vitoria encontrada
}

bool verificarEmpate(char matriz[][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (matriz[i][j] == '.')
                return false; // Ainda há espaços vazios, não é empate
        }
    }
    return true; // Todos os espaços estão preenchidos, é empate
}

void verificaJogo(char matriz[][TAM], char jogador) {
    if (verificarVitoria(matriz, jogador))
        printf("O jogador %c ganhou!\n", jogador);
    else if (verificarEmpate(matriz))
        printf("O jogo terminou em empate!\n");
}

bool jogarNovamente() {
    char resposta;
    printf("Deseja jogar novamente? (S/N): ");
    scanf(" %c", &resposta);
    return (resposta == 'S' || resposta == 's');
}

void reiniciarJogo(char matriz[][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            matriz[i][j] = '.';
        }
    }
}

int main() {
    char tabuleiro[TAM][TAM];
    bool jogar = true;

    printf("Jogo da Velha\n");

    while (jogar) {
        reiniciarJogo(tabuleiro);

        int jogadas = 0;
        int linha, coluna;
        char jogador = 'X';

        while (1) {
            escreverTabuleiro(tabuleiro);

            printf("Jogador %c, informe a linha (0-2): ", jogador);
            scanf("%d", &linha);
            printf("Jogador %c, informe a coluna (0-2): ", jogador);
            scanf("%d", &coluna);

            preencherTabuleiro(tabuleiro, linha, coluna, jogador);

            jogadas++;

            verificaJogo(tabuleiro, jogador);

            if (jogadas >= 9 || verificarVitoria(tabuleiro, jogador) || verificarEmpate(tabuleiro))
                break;

            jogador = (jogador == 'X') ? 'O' : 'X'; // Alternar jogador
        }

        escreverTabuleiro(tabuleiro);

        if (!jogarNovamente())
            jogar = false;
    }

    return 0;
}
