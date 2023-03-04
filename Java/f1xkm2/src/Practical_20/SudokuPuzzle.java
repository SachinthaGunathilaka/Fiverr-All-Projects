package Practical_20;

public class SudokuPuzzle {
    private int[][] board;

    public static void main(String[] args) {

        int[][] board1 = new int[][]{
                {1, 0, 4, 3, 8, 2, 9, 5, 6},
                {2, 0, 5, 4, 6, 7, 1, 3, 8},
                {3, 8, 6, 9, 5, 1, 4, 0, 2},
                {4, 6, 1, 5, 2, 3, 8, 9, 7},
                {7, 3, 8, 1, 4, 9, 6, 2, 5},
                {9, 5, 2, 8, 7, 6, 3, 1, 4},
                {5, 2, 9, 6, 3, 4, 7, 8, 1},
                {6, 0, 7, 2, 9, 8, 5, 4, 3},
                {8, 4, 3, 0, 1, 5, 2, 6, 9}
        };

        int[][] board2 = new int[][]{
                {0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 3, 0, 8, 5},
                {0, 0, 1, 0, 2, 0, 0, 0, 0},
                {0, 0, 0, 5, 0, 7, 0, 0, 0},
                {0, 0, 4, 0, 0, 0, 1, 0, 0},
                {0, 9, 0, 0, 0, 0, 0, 0, 0},
                {5, 0, 0, 0, 0, 0, 0, 7, 3},
                {0, 0, 2, 0, 1, 0, 0, 0, 0},
                {0, 0, 0, 0, 4, 0, 0, 0, 9},

        };

        int[][] board3 = new int[][]{
                {1, 9, 5, 8, 3, 0, 0, 0, 2},
                {6, 0, 7, 2, 0, 0, 0, 9, 8},
                {2, 8, 4, 7, 9, 0, 0, 5, 6},
                {5, 4, 8, 9, 7, 0, 2, 6, 1},
                {0, 6, 0, 4, 8, 2, 5, 3, 9},
                {9, 2, 3, 1, 6, 5, 4, 8, 7},
                {8, 1, 0, 3, 4, 7, 6, 0, 5},
                {3, 7, 0, 5, 0, 9, 8, 0, 4},
                {0, 5, 2, 0, 1, 6, 9, 0, 3},
        };

        SudokuPuzzle sudokuPuzzle1 = new SudokuPuzzle(board1);
        sudokuPuzzle1.solvePuzzle();

        SudokuPuzzle sudokuPuzzle2 = new SudokuPuzzle(board2);
        sudokuPuzzle2.solvePuzzle();

        SudokuPuzzle sudokuPuzzle3 = new SudokuPuzzle(board3);
        sudokuPuzzle3.solvePuzzle();

    }

    public SudokuPuzzle(int[][] board) {
        this.board = board;
    }

    public void solvePuzzle() {
        System.out.println("\nSolving Sudoku Puzzle");
        display();
        boolean isSolve = solvePuzzleRecursive(board, 0, 0);
        if (isSolve) {
            System.out.println("\nSudoku Puzzle Solved.");
            display();
        } else {
            System.out.println("\nSudoku puzzle cannot be solved.");
        }
    }

    boolean isSafe(int row, int col, int digit) {

        for (int k = 0; k < 9; k++) {
            if (board[k][col] == digit || board[row][k] == digit) {
                return false;
            }
        }

        int start_row = (row / 3) * 3;
        int start_col = (col / 3) * 3;

        for (int x = start_row; x < start_row + 3; x++) {
            for (int y = start_col; y < start_col + 3; y++) {
                if (board[x][y] == digit) {
                    return false;
                }
            }
        }
        return true;
    }


    public boolean solvePuzzleRecursive(int board[][], int row, int col) {
        if (row == 9) {
            return true;
        }

        if (col == 9) {
            return solvePuzzleRecursive(board, row + 1, 0);
        }

        if (SudokuPuzzle.this.board[row][col] != 0) {
            return solvePuzzleRecursive(board, row, col + 1);
        }

        for (int digit = 1; digit <= 9; digit++) {
            if (isSafe(row, col, digit)) {

                SudokuPuzzle.this.board[row][col] = digit;
                boolean status = solvePuzzleRecursive(board, row, col + 1);
                if (status) {
                    return true;
                }
            }

        }
        SudokuPuzzle.this.board[row][col] = 0;
        return false;
    }

    public void display() {

        System.out.println("\n+-----------------------------------+");
        for (int i = 0; i < 9; i++) {
            System.out.print("| ");
            for (int j = 0; j < 9; j++) {
                System.out.print(board[i][j] + " | ");
            }
            System.out.println("\n+-----------------------------------+");
        }
    }
}
