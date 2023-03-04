import java.util.Scanner;

public class LabProgram {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int baseChar;
        int headChar;

        String [] input = scanner.nextLine().split(" ");
        baseChar = Integer.parseInt(input[0]);
        headChar = Integer.parseInt(input[1]);
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 5; j++) {
                if (i < 2 || i > 4)
                    System.out.print(" ");
                else
                    System.out.print(baseChar);

            }

            if(i < 4){
                for (int j = 0; j < i+1; j++) {
                    System.out.print(headChar);
                }
            }

            else{
                for (int j = 0; j < 7-i; j++) {
                    System.out.print(headChar);
                }
            }

            System.out.println();


        }

    }
}
