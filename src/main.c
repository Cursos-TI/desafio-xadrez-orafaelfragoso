#include <stdio.h>
#include <stdlib.h>

// Define o tamanho do tabuleiro (8x8)
#define BOARD_SIZE 8

// Estrutura para representar uma posição no tabuleiro
typedef struct
{
    int x;
    int y;
} Position;

// Funções para movimentação das peças
void moveBishop(Position pos, int steps);
void moveRook(Position pos, int steps);
void moveQueen(Position pos, int steps);
void moveKnight(Position pos);

// Funções auxiliares
void printBoard(Position pos);
int isValidPosition(int x, int y);

int main()
{
    int choice;
    Position start = {4, 4}; // Posição inicial padrão (centro do tabuleiro)

    printf("=== MateCheck - Movimentação das Peças ===\n");
    printf("Escolha uma peça para movimentar:\n");
    printf("1 - Bispo (5 casas na diagonal superior direita)\n");
    printf("2 - Torre (5 casas para a direita)\n");
    printf("3 - Rainha (8 casas para a esquerda)\n");
    printf("4 - Cavalo (movimento em L)\n");
    printf("0 - Sair\n");

    while (1)
    {
        printf("\nDigite sua escolha: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nMovimentando o Bispo...\n");
            moveBishop(start, 5);
            break;
        case 2:
            printf("\nMovimentando a Torre...\n");
            moveRook(start, 5);
            break;
        case 3:
            printf("\nMovimentando a Rainha...\n");
            moveQueen(start, 8);
            break;
        case 4:
            printf("\nMovimentando o Cavalo...\n");
            moveKnight(start);
            break;
        case 0:
            printf("Encerrando o programa.\n");
            return 0;
        default:
            printf("Opção inválida! Tente novamente.\n");
        }
    }

    return 0;
}

/**
 * @brief Movimenta o Bispo recursivamente.
 *
 * O Bispo se move na diagonal superior direita.
 * @param pos Posição inicial da peça.
 * @param steps Número de passos a serem dados.
 */
void moveBishop(Position pos, int steps)
{
    if (steps == 0 || !isValidPosition(pos.x + 1, pos.y + 1))
    {
        return;
    }

    pos.x += 1; // Move uma casa na diagonal superior direita
    pos.y += 1;

    printBoard(pos);            // Exibe a posição atual
    moveBishop(pos, steps - 1); // Chamada recursiva
}

/**
 * @brief Movimenta a Torre recursivamente.
 *
 * A Torre se move horizontalmente para a direita.
 * @param pos Posição inicial da peça.
 * @param steps Número de passos a serem dados.
 */
void moveRook(Position pos, int steps)
{
    if (steps == 0 || !isValidPosition(pos.x, pos.y + 1))
    {
        return;
    }

    pos.y += 1; // Move uma casa para a direita

    printBoard(pos);          // Exibe a posição atual
    moveRook(pos, steps - 1); // Chamada recursiva
}

/**
 * @brief Movimenta a Rainha recursivamente.
 *
 * A Rainha se move horizontalmente para a esquerda.
 * @param pos Posição inicial da peça.
 * @param steps Número de passos a serem dados.
 */
void moveQueen(Position pos, int steps)
{
    if (steps == 0 || !isValidPosition(pos.x, pos.y - 1))
    {
        return;
    }

    pos.y -= 1; // Move uma casa para a esquerda

    printBoard(pos);           // Exibe a posição atual
    moveQueen(pos, steps - 1); // Chamada recursiva
}

/**
 * @brief Movimenta o Cavalo utilizando loops aninhados.
 *
 * O Cavalo realiza movimentos em L.
 * @param pos Posição inicial da peça.
 */
void moveKnight(Position pos)
{
    int moves[8][2] = {
        {-2, -1}, {-2, +1}, // Movimentos para cima
        {+2, -1},
        {+2, +1}, // Movimentos para baixo
        {-1, -2},
        {-1, +2}, // Movimentos para esquerda
        {+1, -2},
        {+1, +2} // Movimentos para direita
    };

    for (int i = 0; i < 8; i++)
    {
        int newX = pos.x + moves[i][0];
        int newY = pos.y + moves[i][1];

        if (!isValidPosition(newX, newY))
        {
            continue; // Ignora movimentos inválidos
        }

        printf("Cavalo se moveu para (%d, %d)\n", newX, newY);

        if (i == 3)
        { // Exemplo de uso de break após um movimento específico
            printf("Interrompendo após o movimento %d.\n", i + 1);
            break;
        }
    }
}

/**
 * @brief Verifica se uma posição é válida no tabuleiro.
 *
 * @param x Coordenada x da posição.
 * @param y Coordenada y da posição.
 * @return int Retorna 1 se válido ou 0 caso contrário.
 */
int isValidPosition(int x, int y)
{
    return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
}

/**
 * @brief Imprime o tabuleiro com a posição atual da peça.
 *
 * @param pos Posição atual da peça.
 */
void printBoard(Position pos)
{
    printf("Peça movida para (%d, %d)\n", pos.x, pos.y);
}
