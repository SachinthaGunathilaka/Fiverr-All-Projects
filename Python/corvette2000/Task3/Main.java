import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        VendingMachine vendingMachine = new VendingMachine();
        Scanner scanner = new Scanner(System.in);

        String[] input_data = scanner.nextLine().split(" ");
        vendingMachine.purchase(Integer.parseInt(input_data[0]));
        vendingMachine.restock(Integer.parseInt(input_data[1]));

        vendingMachine.report();
    }

}
