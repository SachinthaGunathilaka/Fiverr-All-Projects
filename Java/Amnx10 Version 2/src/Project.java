import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Project {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("----------------------------------");
        System.out.println("   Choose an option from Below    ");
        System.out.println("----------------------------------");
        System.out.println("\n1) Control application manually\n" +
                "2) Control application automatically");
        System.out.println("----------------------------------");

        System.out.print("\nChoose option: ");
        int choice = Integer.parseInt(scanner.nextLine());
        while (choice < 1 || choice > 2) {
            System.out.println("Choose option between 1 and 2");
            System.out.println("\n1) Control application manually\n" +
                    "2) Control application automatically");
            System.out.print("\nChoose option: ");
            choice = Integer.parseInt(scanner.nextLine());
        }

        try {


            if (choice == 2) {
                System.out.print("\nEnter filename which contains inputs : ");
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
                        String name = data[1].trim();
                        AllUsers.addMember(member_id, name);

                    } catch (Exception e) {
                        continue;
                    }
                }
                myReader.close();
            } catch (FileNotFoundException e) {
                System.out.println(member_filename + " file not found!");
            }


            // Read item file
            try {
                File item_file = new File(item_filename);
                Scanner myReader = new Scanner(item_file);
                while (myReader.hasNextLine()) {
                    try {
                        String[] data = myReader.nextLine().split(",");
                        int item_number = Integer.parseInt(data[0]);
                        String title = data[1].trim();
                        int available = Integer.parseInt(data[2]);

                        AllItems.addItem(item_number, title, available);

                    } catch (Exception e) {
                        continue;
                    }
                }
                myReader.close();
            } catch (FileNotFoundException e) {
                System.out.println(item_filename + " file not found!");
            }


            // Read transaction file
            try {
                File transaction_file = new File(transaction_filename);
                Scanner myReader = new Scanner(transaction_file);
                while (myReader.hasNextLine()) {
                    try {
                        String[] data = myReader.nextLine().split(",");
                        String transaction_id = data[0].trim();
                        int item_id = Integer.parseInt(data[1]);
                        int member_id = Integer.parseInt(data[2]);
                        String title = data[3].trim();

                        AllTransactions.readFromFile(transaction_id, item_id, member_id, title);

                    } catch (Exception e) {
                        continue;
                    }
                }
                myReader.close();
            } catch (FileNotFoundException e) {
                System.out.println(transaction_filename + " file not found!");
            }


//        Members.displayMembers();

            while (true) {
                AllTransactions.checkForExpiredItems();
                Dashboard();

                System.out.print("\nChoose option : ");
                int option = Integer.parseInt(scanner.nextLine());
                while (option < 1 || option > 8) {
                    System.out.println("Choose option between 1 and 8");
                    System.out.print("\nChoose option : ");
                    option = Integer.parseInt(scanner.nextLine());
                }

                if (option == 1) {
                    System.out.print("Enter item number: ");
                    int item_number = Integer.parseInt(scanner.nextLine());

                    System.out.print("Enter member id: ");
                    int member_id = Integer.parseInt(scanner.nextLine());

                    AllUsers.requestItem(member_id, item_number);
                } else if (option == 2) {
                    System.out.print("Enter item number: ");
                    int item_number = Integer.parseInt(scanner.nextLine());
                    AllItems.searchByItemNumber(item_number);

                } else if (option == 3) {
                    System.out.print("Enter title: ");
                    String title = scanner.nextLine();
                    AllItems.searchByTitle(title);


                } else if (option == 4) {
                    AllItems.displayItems();

                } else if (option == 5) {
                    AllUsers.displayMembers();


                } else if (option == 6) {
                    AllTransactions.displayTransactions();

                } else if (option == 7) {
                    System.out.print("Enter member id: ");
                    int member_id = Integer.parseInt(scanner.nextLine());

                    System.out.print("Enter username: ");
                    String username = scanner.nextLine();

                    AllUsers.addMember(member_id, username);
                } else{
                    break;
                }

            }
        } catch (Exception e) {
            System.out.println("Something went wrong!");
        }


    }

    public static void Dashboard() {
        System.out.println("\n-------------------------------------------------------------------");
        System.out.println("                            Menu                                   ");
        System.out.println("-------------------------------------------------------------------");
        System.out.println("\n1) Borrow/Request item\n" +
                "2) Search an item (By item number)\n" +
                "3) Search an item (By title)\n" +
                "4) Show all items\n" +
                "5) Show all users\n" +
                "6) Show all transactions\n" +
                "7) Create new member\n" +
                "8) Exit");
        System.out.println("-------------------------------------------------------------------");
    }
}

