#include <iostream>
#include <stack>
#include <fstream>
#include <sstream>

using namespace std;

// Function to display the chessboard (With the placed queens)
void printSolution(int *board, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            cout << " " << board[i * size + j] << " ";
        printf("\n");
    }
}


// Function to check whether is it okay to place a queen in the given location
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

// Helper function to solve N-Queens problem
bool solveNQueensHelper(int *board, int size, int col, const int *queens, int n_queens) {

    // Create empty stack to store queens positions
    stack<int> placed_queens;
    int row_start = 0;

    while (true) {
        bool skip = false;
        bool backtrack = true;

        // If the problem is solved
        if (col >= size)
            return true;

        // Check whether a queen is already placed in the current column
        for (int j = 0; j < n_queens; ++j) {
            if (queens[j * 2] == col) {
                col++;
                skip = true;
                break;
            }
        }

        if (skip)
            continue;

        // Check each cell in the given column
        for (int i = row_start; i < size; i++) {

            // Check if the queen can be placed on the current cell
            if (isSafe(board, size, i, col)) {
                // Place this queen in the current cell
                board[i * size + col] = 1;

                // Add queen position to the stack
                placed_queens.push(i * size + col);
                col++;
                row_start = 0;
                backtrack = false;
                break;
            }
        }

        // If the next queen cannot be placed, we have to backtrack
        if (backtrack) {

            // If the stack is empty, problem cannot be solved
            if (placed_queens.empty())
                return false;

            // Get the top node from the stack
            int top = placed_queens.top();
            placed_queens.pop();

            // Backtracking
            board[top] = 0;
            row_start = top / size + 1;
            col = top % size;
        }

    }
}


// Function to initialize the board
void initializeBoard(int *board, int size, const int *queens, int num_queens) {
    // Put 0 to every position of the board
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            board[i * size + j] = 0;
        }
    }

    // Place given queens
    for (int i = 0; i < num_queens; ++i) {
        board[queens[(i * 2 + 1)] * size + queens[i * 2]] = 1;
    }
}


// Main function
int main(int argc, char **argv) {

    // Validate arguments
    if (argc != 3) {
        cout << "usage: ./NQueens <input file> <output file>" << endl;
        return 0;
    }

    string input_file = argv[1];
    string output_file = argv[2];

    ifstream infile(input_file);

    // Read the input file and store data
    string line;
    int size;
    int *queens;
    int n_queens;

    // Open output file
    ofstream outfile(output_file);

    while (getline(infile, line)) {
        istringstream ss(line);

        ss >> size;
        queens = new int[size];

        int col, row;
        n_queens = 0;
        while (ss >> col >> row) {
            queens[n_queens * 2] = col - 1;
            queens[n_queens * 2 + 1] = row - 1;
            n_queens++;
        }

        // Allocate memory for the board
        int *board = new int[size * size];

        // Initialize the board
        initializeBoard(board, size, queens, n_queens);

        // If the problem cannot be solved
        if (!solveNQueensHelper(board, size, 0, queens, n_queens)) {
            outfile << "No solution" << endl;
        } else {
            // Display the positions of the queens
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    if (board[j * size + i] == 1) {
                        if (i == size - 1)
                            outfile << i + 1 << " " << j + 1 << endl;
                        else
                            outfile << i + 1 << " " << j + 1 << " ";
                    }
                }
            }
        }





        // Free the memory
        delete[] board;
        delete queens;

    }
    return 0;
}
