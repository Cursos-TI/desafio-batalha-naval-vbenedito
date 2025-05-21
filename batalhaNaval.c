#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define VALOR_AGUA 0
#define VALOR_NAVIO 3

// Função para inicializar o tabuleiro com 0 (água)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = VALOR_AGUA;
        }
    }
}

// Função para verificar se o navio pode ser colocado (sem sair dos limites e sem sobrepor)
int podeColocarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char direcao) {
    if (direcao == 'H') {
        // Verifica se cabe horizontalmente
        if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;
        // Verifica se há sobreposição
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha][coluna + i] != VALOR_AGUA) return 0;
        }
    } else if (direcao == 'V') {
        // Verifica se cabe verticalmente
        if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;
        // Verifica se há sobreposição
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna] != VALOR_AGUA) return 0;
        }
    }
    return 1; // Pode colocar
}

// Função para posicionar o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char direcao) {
    if (direcao == 'H') {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha][coluna + i] = VALOR_NAVIO;
        }
    } else if (direcao == 'V') {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha + i][coluna] = VALOR_NAVIO;
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa tabuleiro com água
    inicializarTabuleiro(tabuleiro);

    // Define coordenadas iniciais para os navios
    int linhaHorizontal = 2, colunaHorizontal = 4;
    int linhaVertical = 5, colunaVertical = 7;

    // Verifica e posiciona navios (horizontal e vertical)
    if (podeColocarNavio(tabuleiro, linhaHorizontal, colunaHorizontal, 'H')) {
        posicionarNavio(tabuleiro, linhaHorizontal, colunaHorizontal, 'H');
    } else {
        printf("Erro ao posicionar navio horizontal!\n");
    }

    if (podeColocarNavio(tabuleiro, linhaVertical, colunaVertical, 'V')) {
        posicionarNavio(tabuleiro, linhaVertical, colunaVertical, 'V');
    } else {
        printf("Erro ao posicionar navio vertical!\n");
    }

    // Exibe o tabuleiro com os navios
    exibirTabuleiro(tabuleiro);

    return 0;
}
