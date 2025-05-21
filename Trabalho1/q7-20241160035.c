#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char jogo[3][3];

void inicializarJogo() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            jogo[i][j] = ' ';
}


void imprimirTabuleiro() {
    printf("\n   1   2   3\n\n");
    printf("A  %c | %c | %c \n", jogo[0][0], jogo[0][1], jogo[0][2]);
    printf("  ---|---|---\n");
    printf("B  %c | %c | %c \n", jogo[1][0], jogo[1][1], jogo[1][2]);
    printf("  ---|---|---\n");
    printf("C  %c | %c | %c \n\n", jogo[2][0], jogo[2][1], jogo[2][2]);
}


int verificarVitoria(char simbolo) {
    for (int i = 0; i < 3; i++) {
        if (jogo[i][0] == simbolo && jogo[i][1] == simbolo && jogo[i][2] == simbolo) return 1;
        if (jogo[0][i] == simbolo && jogo[1][i] == simbolo && jogo[2][i] == simbolo) return 1;
    }
    if (jogo[0][0] == simbolo && jogo[1][1] == simbolo && jogo[2][2] == simbolo) return 1;
    if (jogo[0][2] == simbolo && jogo[1][1] == simbolo && jogo[2][0] == simbolo) return 1;

    return 0;
}


int verificarEmpate() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (jogo[i][j] == ' ')
                return 0;
    return 1;
}


int converterCoordenada(char linha, int coluna, int* lin, int* col) {
    linha = toupper(linha);
    if (linha < 'A' || linha > 'C' || coluna < 1 || coluna > 3) {
        return 0;
    }
    *lin = linha - 'A';
    *col = coluna - 1;
    return 1;
}

int main() {
    int jogador = 1;
    char simbolo;
    char linha;
    int coluna;
    int lin, col;
    int fim_jogo = 0;

    inicializarJogo();

    while (!fim_jogo) {
        imprimirTabuleiro();

        simbolo = (jogador % 2 == 1) ? 'X' : 'O';
        printf("Jogador %d (%c), digite sua jogada (ex: A1, B3): ", jogador, simbolo);
        scanf(" %c%d", &linha, &coluna);

        if (!converterCoordenada(linha, coluna, &lin, &col)) {
            printf("Entrada invalida! Tente novamente.\n\n");
            continue;
        }

        if (jogo[lin][col] != ' ') {
            printf("Posição ja ocupada! Tente novamente.\n\n");
            continue;
        }

        jogo[lin][col] = simbolo;

        if (verificarVitoria(simbolo)) {
            imprimirTabuleiro();
            printf("Parabens! Jogador %d venceu!\n", jogador);
            fim_jogo = 1;
        } else if (verificarEmpate()) {
            imprimirTabuleiro();
            printf("Empate!\n");
            fim_jogo = 1;
        } else {
            jogador = (jogador == 1) ? 2 : 1;
        }
    }

    return 0;
}
