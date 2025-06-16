#include <stdio.h>

#define TAM 10
#define TAM_HAB 5
#define NAVIO 3
#define AGUA 0
#define HABILIDADE 5

// Exibição clara do tabuleiro
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Cria matriz cone (forma piramidal apontando para baixo)
void criarCone(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (j >= TAM_HAB / 2 - i && j <= TAM_HAB / 2 + i)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Cria matriz cruz (horizontal e vertical com centro)
void criarCruz(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Cria matriz octaedro (losango frontal)
void criarOctaedro(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - TAM_HAB / 2) + abs(j - TAM_HAB / 2) <= TAM_HAB / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Sobrepõe a habilidade no tabuleiro com base na origem
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HAB][TAM_HAB], int origemLinha, int origemColuna) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int linhaTab = origemLinha - TAM_HAB / 2 + i;
            int colTab = origemColuna - TAM_HAB / 2 + j;

            if (linhaTab >= 0 && linhaTab < TAM && colTab >= 0 && colTab < TAM) {
                if (habilidade[i][j] == 1 && tabuleiro[linhaTab][colTab] == AGUA) {
                    tabuleiro[linhaTab][colTab] = HABILIDADE;
                }
            }
        }
    }
}

// Posiciona manualmente navios para visualização
void posicionarNavios(int tabuleiro[TAM][TAM]) {
    // Horizontal
    for (int i = 0; i < 3; i++)
        tabuleiro[2][4 + i] = NAVIO;

    // Vertical
    for (int i = 0; i < 3; i++)
        tabuleiro[5 + i][1] = NAVIO;

    // Diagonal \
    for (int i = 0; i < 3; i++)
        tabuleiro[0 + i][0 + i] = NAVIO;

    // Diagonal /
    for (int i = 0; i < 3; i++)
        tabuleiro[5 + i][5 - i] = NAVIO;
}

int main() {
    int tabuleiro[TAM][TAM] = {0};

    // Matrizes das habilidades
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    // Criação das formas
    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Posiciona os navios fixos
    posicionarNavios(tabuleiro);

    // Aplica as habilidades no tabuleiro com ponto de origem
    aplicarHabilidade(tabuleiro, cone, 2, 2);       // Cone centrado em (2,2)
    aplicarHabilidade(tabuleiro, cruz, 5, 5);       // Cruz centrado em (5,5)
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);   // Octaedro centrado em (7,7)

    // Exibe resultado final
    exibirTabuleiro(tabuleiro);

    return 0;
}
