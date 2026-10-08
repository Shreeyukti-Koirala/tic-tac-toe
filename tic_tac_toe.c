#include <stdio.h>

void show_board(const char board[9])
{
    printf("\n %c | %c | %c\n", board[0], board[1], board[2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[3], board[4], board[5]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n\n", board[6], board[7], board[8]);
}

int has_won(const char board[9], char player)
{
    const int lines[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
        {0, 4, 8}, {2, 4, 6}
    };

    for (int i = 0; i < 8; i++) {
        if (board[lines[i][0]] == player &&
            board[lines[i][1]] == player &&
            board[lines[i][2]] == player) {
            return 1;
        }
    }

    return 0;
}

int main(void)
{
    char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char player = 'X';
    char input[64];
    int move;
    char extra;

    printf("Tic-Tac-Toe\n");
    printf("Two players take turns. Pick a number from 1 to 9.\n");

    for (int turns = 0; turns < 9; ) {
        show_board(board);
        printf("Player %c, choose a square: ", player);

        if (fgets(input, sizeof input, stdin) == NULL) {
            printf("\nGame ended.\n");
            return 0;
        }

        if (sscanf(input, " %d %c", &move, &extra) != 1 ||
            move < 1 || move > 9) {
            printf("Please enter one number from 1 to 9.\n");
            continue;
        }

        if (board[move - 1] == 'X' || board[move - 1] == 'O') {
            printf("That square is already taken. Try another.\n");
            continue;
        }

        board[move - 1] = player;
        turns++;

        if (has_won(board, player)) {
            show_board(board);
            printf("Player %c wins!\n", player);
            return 0;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    show_board(board);
    printf("It's a draw!\n");
    return 0;
}

