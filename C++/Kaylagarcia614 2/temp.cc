#include <iostream>
#include <stack>

using namespace std;

void printSolution(int *board, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            cout << " " << board[i * size + j] << " ";
        printf("\n");
    }
}

bool isSafe(const int *board, int size, int row, int col) {
    int i, j;

    // Check current row
    for (i = 0; i < size; i++) {
        if (board[row * size + i])
            return false;
    }

    // Check current column
    for (i = 0; i < size; i++) {
        if (board[i * size + col])
            return false;
    }

    // Check main diagonal (UP)
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i * size + j])
            return false;

    // Check main diagonal (DOWN)
    for (i = row, j = col; i < size && j < size; i++, j++)
        if (board[i * size + j])
            return false;

    // Check secondary diagonal (DOWN)
    for (i = row, j = col; j >= 0 && i < size; i++, j--)
        if (board[i * size + j])
            return false;

    // Check secondary diagonal (UP)
    for (i = row, j = col; j < size && i >= 0; i--, j++)
        if (board[i * size + j])
            return false;
    return true;
}


//bool solveNQUtil(int *board, int size, int col, int *queens, int n_queens) {
//
//
//    /* base case: If all queens are placed
//      then return true */
//    if (col >= size)
//        return true;
//
//    // If a queen is placed in the current column
//    for (int j = 0; j < n_queens; ++j) {
//        if (queens[j * 2] == col)
//            return solveNQUtil(board, size, col + 1, queens, n_queens);
//    }
//
//    /* Consider this column and try placing
//       this queen in all rows one by one */
//    for (int i = 0; i < size; i++) {
//
//        /* Check if the queen can be placed on
//          board[i][col] */
//        if (isSafe(board, size, i, col)) {
//            /* Place this queen in board[i][col] */
//            board[i * size + col] = 1;
//
//            /* recur to place rest of the queens */
//
//            if (solveNQUtil(board, size, col + 1, queens, n_queens))
//                return true;
//
//            /* If placing queen in board[i][col]
//               doesn't lead to a solution, then
//               remove queen from board[i][col] */
//            board[i * size + col] = 0; // BACKTRACK
//        }
//    }
//
//    /* If the queen cannot be placed in any row in
//        this column col  then return false */
//    return false;
//}


bool solveNQUtilWithoutRecursion(int *board, int size, int col, const int *queens, int n_queens) {

    stack<int> placed_queens;
    int row_start = 0;

    while (true) {
        bool skip = false;
        bool backtrack = true;

        if (col >= size)
            return true;

        for (int j = 0; j < n_queens; ++j) {
            if (queens[j * 2] == col) {
                col++;
                skip = true;
                break;
            }
        }

        if (skip)
            continue;

        for (int i = row_start; i < size; i++) {

            /* Check if the queen can be placed on
              board[i][col] */
            if (isSafe(board, size, i, col)) {
                /* Place this queen in board[i][col] */
                board[i * size + col] = 1;

                /* recur to place rest of the queens */
                placed_queens.push(i * size + col);
                col++;
                row_start = 0;
                backtrack = false;
                break;
//                board[i * size + col] = 0; // BACKTRACK
            }
        }

        if (backtrack) {
            if (placed_queens.empty())
                return false;
            int top = placed_queens.top();
            placed_queens.pop();

            board[top] = 0;
            row_start = top / size + 1;
            col = top % size;
        }

    }
}


bool solveNQ(int *board, int size, int *queens, int n_queens) {


//    if (!solveNQUtil(board, size, 0, queens, n_queens)) {
//        cout << "Solution does not exist";
//        return false;
//    }
//
//    printSolution(board, size);
//    return true;


    if (!solveNQUtilWithoutRecursion(board, size, 0, queens, n_queens)) {
        cout << "Solution does not exist";
        return false;
    }

    printSolution(board, size);
    return true;
}

void initializeBoard(int *board, int size, int *queens, int num_queens) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            board[i * size + j] = 0;
        }
    }

    for (int i = 0; i < num_queens; ++i) {
        board[queens[(i * 2 + 1)] * size + queens[i * 2]] = 1;
    }
}

int main() {

    int size = 8;
    int *queens = new int[4];
    queens[0] = 4;
    queens[1] = 4;
    queens[2] = 6;
    queens[3] = 3;


    int *board = new int[size * size];
    initializeBoard(board, size, queens, 2);
    solveNQ(board, size, queens, 2);


//    printf("%d\n", isSafe(board, size, 1, 1));
//    printf("%d\n", isSafe(board, size, 1, 2));
//    printf("%d\n", isSafe(board, size, 2, 1));
//    printf("%d\n", isSafe(board, size, 2, 2));


    return 0;
}
