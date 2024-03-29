#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */

#define CELL_MAX (5 * 5 - 1)

void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
    printf("\n");

}

void print_board(char board[5][5])
{
    int cell = 0;

    print_sep(5);
    for (int row = 0; row < 5; ++row) {
        for (int column = 0; column < 5; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(5);
    }
}

char get_winner(char board[5][5])
{
    char winner = '-';

    int count1 = 0;


    for(int j=0; j<5; j++){
        if(board[0][0] == board[j][j] && board[j][j] != '-'){
            count1 += 1;
        }
    }

    if(count1 == 5){
        winner = board[0][0];
    }
    
    count1 = 0;

    for(int j=0; j<5-1; j++){
        if(board[j][5-1-j] == board[j+1][1-j] && board[j+1][1-j] != '-'){
            count1 += 1;
            }
    }

    if(count1 == 5-1){
        winner = board[1][1];
    }

    count1 = 0;

    for(int j=0; j<5; j++){
        for(int i=0; i<5-1; i++){
            if(board[j][i] == board[j][i+1] && board[j][i] != '-'){
                count1 += 1;
            }
        }
        if(count1 == 5-1){
            winner = board[j][0];
        }
        count1 = 0;
    }

    for(int j=0; j<5; j++){
        for(int i=0; i<5-1; i++){
            if(board[i][j] == board[i+1][j] && board[i][j] != '-'){
                count1 += 1;
            }
        }
        if(count1 == 5-1){
            winner = board[j][0];
        }
        count1 = 0;
    }

    return winner;
}

bool has_free_cell(char board[5][5])
{
    bool free_cell=false;

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(board[i][j] == '-'){
            free_cell = true;
        }    }
    }

    return free_cell;
}

int main(void)
{   
    printf("TicTacToe [InCoMpLeTo :'(]\n");

    char board[5][5] = {
        { '-', '-', '-', '-', '-' },
        { '-', '-', '-', '-', '-' },
        { '-', '-', '-', '-', '-' },
        { '-', '-', '-', '-', '-' },
        { '-', '-', '-', '-', '-' }
    };

    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posición (número del 0 al %d): ", turn,
               CELL_MAX);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / 5;
            int colum = cell % 5;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda inválida!\n");
        }
    }
    print_board(board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Ganó %c\n", winner);
    }
    return 0;
}