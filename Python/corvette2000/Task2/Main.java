import java.util.Scanner;

public class Main {

    public static void displayMenu() {
        System.out.println("\nMENU\n" +
                "u - Update player rating\n" +
                "a - Output players above a rating\n" +
                "r - Replace player\n" +
                "o - Output roster\n" +
                "q - Quit");
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Rosters rosters = new Rosters();
        for (int i = 0; i < 5; i++) {
            System.out.println("\nEnter player " + (i + 1) + "'s jersey number:");
            int jersey_number = Integer.parseInt(scanner.nextLine());

            System.out.println("Enter player " + (i + 1) + "'s rating:");
            int rating = Integer.parseInt(scanner.nextLine());

            rosters.addRoster(jersey_number, rating);

        }

        while (true) {
            displayMenu();
            System.out.print("\nChoose an option: ");
            char option = scanner.nextLine().charAt(0);

            if (option == 'u') {
                System.out.println("Enter a jersey number:");
                int jersey_number = Integer.parseInt(scanner.nextLine());
                System.out.println("Enter a new rating for player:");
                int new_rating = Integer.parseInt(scanner.nextLine());

                boolean status = rosters.updateRoster(jersey_number, new_rating);
                if(status)
                    System.out.println("Update player rating successfully!");
                else
                    System.out.println("Jersey number does not exist!");

            } else if (option == 'a') {
                System.out.println("Enter a rating:");
                int rating = Integer.parseInt(scanner.nextLine());
                rosters.outputPlayersAboveRating(rating);
            } else if (option == 'r') {
                System.out.println("Enter a jersey number:");
                int jersey_number = Integer.parseInt(scanner.nextLine());
                rosters.replacePlayer(jersey_number);
            } else if (option == 'o') {
                rosters.outputRoster();
            } else if (option == 'q') {
                break;
            } else {
                System.out.println("Invalid input!");
            }
        }

    }
}
