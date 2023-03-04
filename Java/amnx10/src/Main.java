import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.text.ParseException;
import java.util.Scanner;

public class Main {
    public static void displayMenu() {
        System.out.println("\n1) Borrow item\n" +
                "2) Create new user\n" +
                "3) Search for an item using item number\n" +
                "4) Search for an item using title\n" +
                "5) Display all the items\n" +
                "6) Display all the users\n" +
                "7) Display all the transactions\n" +
                "8) Quit");
    }


    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("\n1) Manual Input\n" +
                "2) Input from file");

        System.out.print("\nEnter option: ");
        int choice = Integer.parseInt(scanner.nextLine());
        while (choice < 1 || choice > 2) {
            System.out.println("Invalid input");
            System.out.println("\n1) Manual Input\n" +
                    "2) Input from file");
            System.out.print("\nEnter option: ");
            choice = Integer.parseInt(scanner.nextLine());
        }

        try {


            if (choice == 2) {
                System.out.print("\nEnter input filename: ");
                String filename = scanner.nextLine();
                System.out.println(filename);
                System.setIn(new FileInputStream(new File(filename)));
                scanner = new Scanner(System.in);

            }


            String member_filename = "DADSA CWK MEMBER.csv";
            String item_filename = "DADSA CWK ITEM.csv";
            String transaction_filename = "DADSA CWK TRANSACTION.csv";


            // Read member file
            try {

                File member_file = new File(member_filename);
                Scanner myReader = new Scanner(member_file);
                while (myReader.hasNextLine()) {
                    try {
                        String[] data = myReader.nextLine().split(",");
                        int member_id = Integer.parseInt(data[0]);
                        String name = data[1].strip();
                        Members.addMember(member_id, name);

                    } catch (Exception e) {
                        continue;
                    }
                }
                myReader.close();
            } catch (FileNotFoundException e) {
                System.out.println("Members file not found!");
            }


            // Read item file
            try {
                File item_file = new File(item_filename);
                Scanner myReader = new Scanner(item_file);
                while (myReader.hasNextLine()) {
                    try {
                        String[] data = myReader.nextLine().split(",");
                        int item_number = Integer.parseInt(data[0]);
                        String title = data[1].strip();
                        int available = Integer.parseInt(data[2]);

                        Items.addItem(item_number, title, available);

                    } catch (Exception e) {
                        continue;
                    }
                }
                myReader.close();
            } catch (FileNotFoundException e) {
                System.out.println("Item file not found!");
            }

//        Items.displayItems();


            // Read transaction file
            try {
                File transaction_file = new File(transaction_filename);
                Scanner myReader = new Scanner(transaction_file);
                while (myReader.hasNextLine()) {
                    try {
                        String[] data = myReader.nextLine().split(",");
                        String transaction_id = data[0].strip();
                        int item_id = Integer.parseInt(data[1]);
                        int member_id = Integer.parseInt(data[2]);
                        String title = data[3].strip();

                        Transactions.readFromFile(transaction_id, item_id, member_id, title);

                    } catch (Exception e) {
                        continue;
                    }
                }
                myReader.close();
            } catch (FileNotFoundException e) {
                System.out.println("Transaction file not found!");
            }

//        Transactions.displayTransactions();

//        Members.displayMembers();

            while (true) {
                Transactions.checkForExpiredItems();
                displayMenu();

                System.out.print("\nSelect option : ");
                int option = Integer.parseInt(scanner.nextLine());
                while (option < 1 || option > 8) {
                    System.out.println("\nInvalid input");
                    System.out.print("Select option : ");
                    option = Integer.parseInt(scanner.nextLine());
                }

                if (option == 1) {
                    System.out.print("Enter item number: ");
                    int item_number = Integer.parseInt(scanner.nextLine());

                    System.out.print("Enter member id: ");
                    int member_id = Integer.parseInt(scanner.nextLine());

                    Members.requestItem(member_id, item_number);
                } else if (option == 2) {
                    System.out.print("Enter member id: ");
                    int member_id = Integer.parseInt(scanner.nextLine());

                    System.out.println("Enter username: ");
                    String username = scanner.nextLine();

                    Members.addMember(member_id, username);


                } else if (option == 3) {

                    System.out.print("Enter item number: ");
                    int item_number = Integer.parseInt(scanner.nextLine());
                    Items.searchByItemNumber(item_number);
                } else if (option == 4) {
                    System.out.print("Enter title: ");
                    String title = scanner.nextLine();
                    Items.searchByTitle(title);
                } else if (option == 5) {
                    Items.displayItems();

                } else if (option == 6) {
                    Members.displayMembers();

                } else if (option == 7) {
                    Transactions.displayTransactions();

                } else if (option == 8) {
                    break;
                } else {
                    System.out.println("Invalid input!");
                }

            }
        } catch (Exception e) {
            System.out.println("An error occurred!");
        }


    }
}
