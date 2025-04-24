#include <stdio.h>

// Constantes para o tamanho do tabuleiro e dos navios
#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define NAVIO 3 // Representação de uma parte do navio no tabuleiro

// Função para inicializar o tabuleiro com o valor 0 (representando água)
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para posicionar um navio horizontalmente no tabuleiro
void posicionarNavioHorizontal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = NAVIO;
    }
}

// Função para posicionar um navio verticalmente no tabuleiro
void posicionarNavioVertical(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = NAVIO;
    }
}

// Função para posicionar um navio diagonalmente (da esquerda para a direita, de cima para baixo)
void posicionarNavioDiagonalPrincipal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna + i] = NAVIO;
    }
}

// Função para posicionar um navio diagonalmente (da direita para a esquerda, de cima para baixo)
void posicionarNavioDiagonalSecundaria(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna - i] = NAVIO;
    }
}

// Função para exibir o tabuleiro com coordenadas
void exibirTabuleiroComCoordenadas(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    // Imprime os títulos das colunas (A a J)
    printf("   ");
    for (char coluna = 'A'; coluna < 'A' + TAM_TABULEIRO; coluna++) {
        printf("%c ", coluna);
    }
    printf("\n");

    // Imprime o tabuleiro com números das linhas (1 a 10)
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%2d ", i + 1); // Imprime o número da linha
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Tabuleiro 10x10
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializar o tabuleiro com água
    inicializarTabuleiro(tabuleiro);

    // Coordenadas iniciais para os navios
    int linhaNavioHorizontal = 2, colunaNavioHorizontal = 3;
    int linhaNavioVertical = 5, colunaNavioVertical = 6;
    int linhaNavioDiagonalPrincipal = 0, colunaNavioDiagonalPrincipal = 0;
    int linhaNavioDiagonalSecundaria = 7, colunaNavioDiagonalSecundaria = 9;

    // Garantir que as coordenadas e tamanhos dos navios são válidos
    if (linhaNavioHorizontal < 0 || linhaNavioHorizontal >= TAM_TABULEIRO ||
        colunaNavioHorizontal < 0 || colunaNavioHorizontal + TAM_NAVIO > TAM_TABULEIRO ||
        linhaNavioVertical < 0 || linhaNavioVertical + TAM_NAVIO > TAM_TABULEIRO ||
        colunaNavioVertical < 0 || colunaNavioVertical >= TAM_TABULEIRO ||
        linhaNavioDiagonalPrincipal < 0 || linhaNavioDiagonalPrincipal + TAM_NAVIO > TAM_TABULEIRO ||
        colunaNavioDiagonalPrincipal < 0 || colunaNavioDiagonalPrincipal + TAM_NAVIO > TAM_TABULEIRO ||
        linhaNavioDiagonalSecundaria < 0 || linhaNavioDiagonalSecundaria + TAM_NAVIO > TAM_TABULEIRO ||
        colunaNavioDiagonalSecundaria - (TAM_NAVIO - 1) < 0) {
        printf("Erro: Coordenadas dos navios inválidas.\n");
        return 1;
    }

    // Posicionar os navios no tabuleiro
    posicionarNavioHorizontal(tabuleiro, linhaNavioHorizontal, colunaNavioHorizontal);
    posicionarNavioVertical(tabuleiro, linhaNavioVertical, colunaNavioVertical);
    posicionarNavioDiagonalPrincipal(tabuleiro, linhaNavioDiagonalPrincipal, colunaNavioDiagonalPrincipal);
    posicionarNavioDiagonalSecundaria(tabuleiro, linhaNavioDiagonalSecundaria, colunaNavioDiagonalSecundaria);

    // Exibir o tabuleiro com coordenadas
    printf("Tabuleiro após posicionar os navios:\n");
    exibirTabuleiroComCoordenadas(tabuleiro);

    return 0;
}