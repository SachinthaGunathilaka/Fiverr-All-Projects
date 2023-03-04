#include "nim.h"
#include<stdlib.h>

int *new_board(int board_size) {
    int *board = (int *) malloc(board_size * sizeof(int));
    return board;
}

struct node *mk_nim_hash(int max_hash, int board_size, int *start_board) {
    struct node *nodes = (struct node *) malloc(sizeof(struct node) * max_hash);

    for (int i = 0; i < max_hash; ++i) {
        nodes[i].moves = -1;
        nodes[i].move = NULL;
        nodes[i].nimsum = -1;
        nodes[i].board = hash2board(board_size, start_board, i);

    }
    return nodes;
}

int *board_from_argv(int board_size, char **argv) {
    int *board = new_board(board_size);
    for (int i = 0; i < board_size; ++i) {
        board[i] = atoi(argv[i]);
    }

    return board;
}

void free_board(int *board) {
    free(board);
}

void free_nim_hash(int max_hash, struct node *nim_hash) {
    for (int i = 0; i < max_hash; ++i) {
        free(nim_hash->move);
        free(nim_hash->board);
    }

    free(nim_hash);
}

int *copy_board(int board_size, int *board) {
    int *copied_board = (int *) malloc(sizeof(int) * board_size);
    for (int i = 0; i < board_size; ++i) {
        copied_board[i] = board[i];
    }

    return copied_board;
}

int game_over(int board_size, int *board) {
    int matches_count = 0;
    for (int i = 0; i < board_size; ++i) {
        matches_count += board[i];
    }
    if (matches_count == 1)
        return 1;

    return 0;
}

void join_graph(struct node *nim_hash, int hash, int board_size,
                int *start_board) {

    if (nim_hash[hash].moves != -1)
        return;

    nim_hash[hash].moves = 0;
    for (int row = 0; row < board_size; ++row) {
        nim_hash[hash].moves += nim_hash[hash].board[row];
    }

    nim_hash[hash].nimsum = compute_nimsum(board_size, nim_hash[hash].board);


    nim_hash[hash].move = (struct move *) malloc(sizeof(struct move) * nim_hash[hash].moves);

    int index = 0;
    for (int row = 0; row < board_size; ++row) {
        for (int matches = 1; matches <= nim_hash[hash].board[row]; ++matches) {
            nim_hash[hash].move[index].row = row;
            nim_hash[hash].move[index].matches = matches;

            int *result = copy_board(board_size, nim_hash[hash].board);
            result[row] -= matches;


            int new_hash = board2hash(board_size, start_board, result);
            nim_hash[hash].move[index].hash = new_hash;
            index++;
            join_graph(nim_hash, new_hash, board_size, start_board);

        }
    }
}


int compute_nimsum(int board_size, int *board) {
    int type = 1;
    int nim_sum;
    for (int i = 0; i < board_size; ++i) {
        if (board[i] > 1) {
            type = 2;
            break;
        }
    }

    nim_sum = board[0];
    for (int i = 1; i < board_size; ++i) {
        nim_sum ^= board[i];
    }


    if (type == 1) {
        nim_sum = !nim_sum;
    }

//    if (nim_sum == 0)
//        return 1;
//
//    if (nim_sum == 1)
//        return 0;


    return nim_sum;


}