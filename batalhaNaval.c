#include <stdio.h>
#include <string.h>

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5
#define AGUA 0
#define AREA_AFETADA 1

// Função para inicializar a matriz da habilidade com zeros
void inicializarMatriz(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    memset(matriz, AGUA, sizeof(int) * TAM_HABILIDADE * TAM_HABILIDADE);
}

// Função para criar a habilidade Cone
void criarCone(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    inicializarMatriz(habilidade);
    habilidade[0][2] = AREA_AFETADA;
    habilidade[1][1] = habilidade[1][2] = habilidade[1][3] = AREA_AFETADA;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        habilidade[2][i] = AREA_AFETADA;
    }
}

// Função para criar a habilidade Cruz
void criarCruz(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    inicializarMatriz(habilidade);
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        habilidade[2][i] = AREA_AFETADA; // Linha central
        habilidade[i][2] = AREA_AFETADA; // Coluna central
    }
}

// Função para criar a habilidade Octaedro
void criarOctaedro(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    inicializarMatriz(habilidade);
    habilidade[0][2] = AREA_AFETADA;
    habilidade[1][1] = habilidade[1][2] = habilidade[1][3] = AREA_AFETADA;
    habilidade[2][0] = habilidade[2][1] = habilidade[2][2] = habilidade[2][3] = habilidade[2][4] = AREA_AFETADA;
    habilidade[3][1] = habilidade[3][2] = habilidade[3][3] = AREA_AFETADA;
    habilidade[4][2] = AREA_AFETADA;
}

// Função para aplicar a habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int origemLinha, int origemColuna) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int linhaTabuleiro = origemLinha + i - 2;
            int colunaTabuleiro = origemColuna + j - 2;

            // Validar os limites do tabuleiro
            if (linhaTabuleiro >= 0 && linhaTabuleiro < TAM_TABULEIRO &&
                colunaTabuleiro >= 0 && colunaTabuleiro < TAM_TABULEIRO &&
                habilidade[i][j] == AREA_AFETADA) {
                tabuleiro[linhaTabuleiro][colunaTabuleiro] = AREA_AFETADA;
            }
        }
    }
}

// Função para exibir uma matriz (habilidade ou tabuleiro)
void exibirMatriz(int matriz[TAM_TABULEIRO][TAM_TABULEIRO], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    int habilidade[TAM_HABILIDADE][TAM_HABILIDADE];

    // Inicializar o tabuleiro com zeros
    inicializarMatriz(tabuleiro);

    // Criar e aplicar a habilidade Cone
    printf("Habilidade: Cone\n");
    criarCone(habilidade);
    exibirMatriz(habilidade, TAM_HABILIDADE);
    aplicarHabilidade(tabuleiro, habilidade, 4, 4);

    // Criar e aplicar a habilidade Cruz
    printf("\nHabilidade: Cruz\n");
    criarCruz(habilidade);
    exibirMatriz(habilidade, TAM_HABILIDADE);
    aplicarHabilidade(tabuleiro, habilidade, 7, 7);

    // Criar e aplicar a habilidade Octaedro
    printf("\nHabilidade: Octaedro\n");
    criarOctaedro(habilidade);
    exibirMatriz(habilidade, TAM_HABILIDADE);
    aplicarHabilidade(tabuleiro, habilidade, 2, 2);

    // Exibir o tabuleiro final
    printf("\nTabuleiro com áreas afetadas:\n");
    exibirMatriz(tabuleiro, TAM_TABULEIRO);

    return 0;
}