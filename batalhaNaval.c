#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define VALOR_NAVIO 3
#define AGUA 0

// Função para inicializar todo o tabuleiro com 0 (água)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para verificar se o navio horizontal pode ser colocado
int podeColocarHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] != AGUA) return 0;
    }
    return 1;
}

// Função para verificar se o navio vertical pode ser colocado
int podeColocarVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != AGUA) return 0;
    }
    return 1;
}

// Função para posicionar um navio horizontal no tabuleiro
void posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int navio[]) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = navio[i];
    }
}

// Função para posicionar um navio vertical no tabuleiro
void posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int navio[]) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = navio[i];
    }
}

// Função para imprimir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int navioHorizontal[TAMANHO_NAVIO] = {VALOR_NAVIO, VALOR_NAVIO, VALOR_NAVIO};
    int navioVertical[TAMANHO_NAVIO] = {VALOR_NAVIO, VALOR_NAVIO, VALOR_NAVIO};

    // Coordenadas definidas diretamente (como o enunciado permite)
    int linhaHorizontal = 2, colunaHorizontal = 3;
    int linhaVertical = 5, colunaVertical = 6;

    // Inicializa o tabuleiro com água (0)
    inicializarTabuleiro(tabuleiro);

    // Valida e posiciona navio horizontal
    if (podeColocarHorizontal(tabuleiro, linhaHorizontal, colunaHorizontal)) {
        posicionarNavioHorizontal(tabuleiro, linhaHorizontal, colunaHorizontal, navioHorizontal);
        printf("Navio horizontal posicionado em: ");
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            printf("(%d, %d) ", linhaHorizontal, colunaHorizontal + i);
        }
        printf("\n");
    } else {
        printf("Não foi possível posicionar o navio horizontal.\n");
    }

    // Valida e posiciona navio vertical
    if (podeColocarVertical(tabuleiro, linhaVertical, colunaVertical)) {
        posicionarNavioVertical(tabuleiro, linhaVertical, colunaVertical, navioVertical);
        printf("Navio vertical posicionado em: ");
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            printf("(%d, %d) ", linhaVertical + i, colunaVertical);
        }
        printf("\n");
    } else {
        printf("Não foi possível posicionar o navio vertical.\n");
    }

    // Exibe o tabuleiro no final
    exibirTabuleiro(tabuleiro);

    return 0;
}
