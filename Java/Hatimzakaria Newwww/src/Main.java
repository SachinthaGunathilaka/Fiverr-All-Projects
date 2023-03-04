import java.util.Scanner;

public class Main {


    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);


        while (true) {
            displayPrincipalMenu();
            System.out.print("\nEnter option : ");
            int principal_option = Integer.parseInt(scanner.nextLine());
            while (principal_option < 1 || principal_option > 3) {
                System.out.println("Invalid option");
                displayPrincipalMenu();
                System.out.print("\nEnter option : ");
                principal_option = Integer.parseInt(scanner.nextLine());
            }

            if (principal_option == 1) {
                System.out.println("Account creating");
            } else if(principal_option == 2) {
                while (true) {
                    displaySecondaryMenu();
                    System.out.print("\nEnter option : ");
                    int secondary_option = Integer.parseInt(scanner.nextLine());
                    while (secondary_option < 1 || secondary_option > 5) {
                        System.out.println("Invalid option");
                        displayPrincipalMenu();
                        System.out.print("\nEnter option : ");
                        secondary_option = Integer.parseInt(scanner.nextLine());
                    }

                    if (secondary_option == 1) {
                        System.out.println("Printing member profile");
                    } else if (secondary_option == 2) {
                        System.out.println("Printing list of articles");
                    } else if (secondary_option == 3) {
                        System.out.println("Printing a tool profile");
                    } else if (secondary_option == 4) {
                        System.out.println("Printing list of existing projects");
                    } else {
                        break;
                    }
                }

            }
            else {
                break;
            }
        }


    }

    public static void displayPrincipalMenu() {
        System.out.println("\nPrincipal Menu\n" +
                "------------------------\n" +
                "\t1) Account Creation\n" +
                "\t2) Account Access\n" +
                "\t3) Quit");
    }

    public static void displaySecondaryMenu() {
        System.out.println("\nSecondary Menu\n" +
                "--------------------------------------\n" +
                "\t1) Print member Profile\n" +
                "\t2) Print list of articles\n" +
                "\t3) Print a tool profile\n" +
                "\t4) Print list of existing projects\n" +
                "\t5) Return to main menu");
    }
}
