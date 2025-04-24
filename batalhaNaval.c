#include <stdio.h>

// Constantes para o tamanho do tabuleiro e dos navios
#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

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
        tabuleiro[linha][coluna + i] = 3; // 3 representa a parte de um navio
    }
}

// Função para posicionar um navio verticalmente no tabuleiro
void posicionarNavioVertical(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = 3; // 3 representa a parte de um navio
    }
}

// Função para exibir o tabuleiro com coordenadas
void exibirTabuleiroComCoordenadas(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    // Imprime os títulos das colunas (A a J)
    printf("   "); // Espaço para alinhar com os números das linhas
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

    // Coordenadas iniciais dos navios
    int linhaNavioHorizontal = 2; // Linha 3 (índice 2)
    int colunaNavioHorizontal = 3; // Coluna D (índice 3)
    int linhaNavioVertical = 5; // Linha 6 (índice 5)
    int colunaNavioVertical = 6; // Coluna G (índice 6)

    // Garantir que os navios estão dentro dos limites e não se sobrepõem
    if (linhaNavioHorizontal < 0 || linhaNavioHorizontal >= TAM_TABULEIRO ||
        colunaNavioHorizontal < 0 || colunaNavioHorizontal + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: Coordenadas do navio horizontal inválidas.\n");
        return 1;
    }

    if (linhaNavioVertical < 0 || linhaNavioVertical + TAM_NAVIO > TAM_TABULEIRO ||
        colunaNavioVertical < 0 || colunaNavioVertical >= TAM_TABULEIRO) {
        printf("Erro: Coordenadas do navio vertical inválidas.\n");
        return 1;
    }

    // Posicionar os navios no tabuleiro
    posicionarNavioHorizontal(tabuleiro, linhaNavioHorizontal, colunaNavioHorizontal);
    posicionarNavioVertical(tabuleiro, linhaNavioVertical, colunaNavioVertical);

    // Exibir o tabuleiro com coordenadas
    printf("     BATALHA NAVAL\n");
    exibirTabuleiroComCoordenadas(tabuleiro);

    return 0;
}
