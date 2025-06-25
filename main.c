#include <stdio.h>
#include <stdlib.h>

#define TAM 10

void exibirTabuleiro(char tabuleiro[TAM][TAM]) {
    printf("   ");
    for (int i = 0; i < TAM; i++) printf("%d ", i);
    printf("\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d: ", i);
        for (int j = 0; j < TAM; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void preencherAgua(char tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = '~';
}

void posicionarNavios(char tabuleiro[TAM][TAM]) {
    tabuleiro[1][1] = 'N';
    tabuleiro[2][2] = 'N';
    tabuleiro[3][3] = 'N';
    tabuleiro[4][1] = 'N';
    tabuleiro[6][7] = 'N';
}

void ataqueNormal(char tabuleiro[TAM][TAM], int x, int y) {
    tabuleiro[x][y] = 'X';
}

void ataqueCruz(char tabuleiro[TAM][TAM], int x, int y) {
    if (x >= 0 && x < TAM && y >= 0 && y < TAM) tabuleiro[x][y] = '+';
    if (x > 0) tabuleiro[x-1][y] = '+';
    if (x < TAM-1) tabuleiro[x+1][y] = '+';
    if (y > 0) tabuleiro[x][y-1] = '+';
    if (y < TAM-1) tabuleiro[x][y+1] = '+';
}

void ataqueCone(char tabuleiro[TAM][TAM], int x, int y) {
    for (int i = 0; i < 3; i++)
        for (int j = -i; j <= i; j++)
            if (x+i < TAM && y+j >= 0 && y+j < TAM)
                tabuleiro[x+i][y+j] = '*';
}

void ataqueOctaedro(char tabuleiro[TAM][TAM], int x, int y) {
    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {
            if (abs(i) + abs(j) <= 2) {
                int nx = x + i, ny = y + j;
                if (nx >= 0 && nx < TAM && ny >= 0 && ny < TAM)
                    tabuleiro[nx][ny] = '#';
            }
        }
    }
}

int main() {
    char tabuleiro[TAM][TAM];
    preencherAgua(tabuleiro);
    posicionarNavios(tabuleiro);

    printf("Tabuleiro Inicial:\n");
    exibirTabuleiro(tabuleiro);

    ataqueNormal(tabuleiro, 1, 1);
    ataqueCruz(tabuleiro, 4, 4);
    ataqueCone(tabuleiro, 2, 6);
    ataqueOctaedro(tabuleiro, 7, 7);

    printf("\nTabuleiro Apos Ataques:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
