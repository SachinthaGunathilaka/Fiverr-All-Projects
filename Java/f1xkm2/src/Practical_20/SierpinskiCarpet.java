package Practical_20;

public class SierpinskiCarpet {
    private char[][] board;
    private int size;

    public static void main(String[] args) {
        SierpinskiCarpet sierpinskiCarpet3 = new SierpinskiCarpet(3);
        sierpinskiCarpet3.removeSubArray();
        sierpinskiCarpet3.display();

        SierpinskiCarpet sierpinskiCarpet9 = new SierpinskiCarpet(9);
        sierpinskiCarpet9.removeSubArray();
        sierpinskiCarpet9.display();

        SierpinskiCarpet sierpinskiCarpet27 = new SierpinskiCarpet(27);
        sierpinskiCarpet27.removeSubArray();
        sierpinskiCarpet27.display();

        SierpinskiCarpet sierpinskiCarpet81 = new SierpinskiCarpet(81);
        sierpinskiCarpet81.removeSubArray();
        sierpinskiCarpet81.display();

    }

    public SierpinskiCarpet(int size) {
        this.size = size;
        this.board = new char[size][size];

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                this.board[i][j] = '*';
            }
        }
    }

    public void removeSubArrayRecur(char[][] board, int start_row, int start_col, int cur_size) {

        if (cur_size == 1)
            return;

        int sub_arr_start_row = start_row + cur_size / 3;
        int sub_arr_start_col = start_col + cur_size / 3;
        for (int i = sub_arr_start_row; i < sub_arr_start_row + cur_size / 3; i++) {
            for (int j = sub_arr_start_col; j < sub_arr_start_col + cur_size / 3; j++) {
                board[i][j] = ' ';
            }
        }

        int step = cur_size / 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                removeSubArrayRecur(board, start_row + step * i, start_col + step * j, step);
            }
        }

    }

    public void removeSubArray() {
        removeSubArrayRecur(board, 0, 0, size);
    }

    public void display() {
        System.out.println("\nSierpinski Carpet (" + size + " X " + size + ")\n");
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
    }
}
