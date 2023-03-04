import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String input = scanner.nextLine();

        String [] input_data = input.split(" ");
        int threshold = Integer.parseInt(input_data[input_data.length-1]);

        for (int i = 1; i < input_data.length-1; i++) {
            if(Integer.parseInt(input_data[i]) <= threshold)
                System.out.print(input_data[i] + ",");
        }
        System.out.println();
    }
}
