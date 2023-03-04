public class Main {
    public static void main(String[] args) {
        double[][] studentGrade = {{10, 20, 0}, {20, 40, 0}};
        computeAvg(studentGrade);
    }

    public static void computeAvg(double[][] studentGrade) {
        double result_col1 = 0;
        double result_col2 = 0;


        for (int i = 0; i < studentGrade.length; i++) {
            result_col1 += studentGrade[i][0];
            result_col2 += studentGrade[i][1];
        }

        result_col1 = result_col1 / studentGrade.length;
        result_col2 = result_col2 / studentGrade.length;

        studentGrade[0][2] = result_col1;
        studentGrade[1][2] = result_col2;

        for (int i = 0; i < studentGrade.length; i++) {
            for (int j = 0; j < studentGrade[0].length; j++) {
                System.out.print(studentGrade[i][j] + " ");
            }
            System.out.println();
        }



    }
}
