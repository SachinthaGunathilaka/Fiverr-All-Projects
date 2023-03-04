import java.util.Locale;
import java.util.Scanner;

public class Main {

    // Function to display the menu
    public static void displayMenu() {
        System.out.println("\nPatient Collection: Main Menu\n");

        System.out.println("\t1) Add new patient\n" +
                "\t2) Edit patient (by ID)\n" +
                "\t3) Remove patient (by ID)\n" +
                "\t4) Search patient\n" +
                "\t5) Sort list\n" +
                "\t6) Print list\n" +
                "\t7) Clear list\n" +
                "\t8) Show list size\n\n" +
                "\t0) Quit application\n");
    }

    public static void displayEditMenu() {
        System.out.println("\nPatient Collection: Edit Menu\n");

        System.out.println("\t1) Edit name\n" +
                "\t2) Edit age\n" +
                "\t3) Edit gender\n" +
                "\t4) Edit address\n\n" +
                "\t0) Back to main menu\n");
    }

    public static void displaySortMenu() {
        System.out.println("\nPatient Collection: Sort Menu\n");

        System.out.println("\t1) Sort by name\n" +
                "\t2) Sort by age\n" +
                "\t3) Edit address\n\n" +
                "\t0) Back to main menu\n");
    }

    // Function to get an option from user
    public static int getOption(int menu_size) {
        Scanner scanner = new Scanner(System.in);
        int option;
        System.out.print("Enter a menu entry: ");
        option = Integer.parseInt(scanner.nextLine());

        // Handle invalid inputs
        while (option < 0 || option > menu_size) {
            System.out.println("Invalid menu entry.");
            System.out.print("Enter a menu entry: ");
            option = Integer.parseInt(scanner.nextLine());
        }

        return option;
    }

    // Function to get gender from user
    public static String getGender() {
        Scanner scanner = new Scanner(System.in);
        String sex;
        System.out.print("Enter gender (male/female): ");
        sex = scanner.nextLine().toUpperCase(Locale.ROOT);

        // Handle invalid inputs
        while (!sex.equals("MALE") && !sex.equals("FEMALE")) {
            System.out.println("Invalid gender. (male/female)");
            System.out.print("Enter gender: ");
            sex = scanner.nextLine().toUpperCase(Locale.ROOT);
        }
        return sex;
    }

    // Function to get age from user
    public static int getInteger(String message) {
        Scanner scanner = new Scanner(System.in);
        int age;

        // Handle invalid inputs
        while (true) {
            try {
                System.out.print("Enter " + message + " : ");
                age = Integer.parseInt(scanner.nextLine());
                if (age < 0)
                    throw new Exception();

                break;
            } catch (Exception e) {
                System.out.println("Invalid " + message + " .");
            }

        }

        return age;
    }

    // main function
    public static void main(String[] args) {

        // Create PatientsList object to hold all the patients details
        PatientsList patientsList = new PatientsList();
        Scanner scanner = new Scanner(System.in);
        String name, sex, address;
        int id, age;

        Patient patient1 = new Patient("john", 24, "Male", "address1");
        Patient patient2 = new Patient("clara", 20, "Female", "address2");
        Patient patient3 = new Patient("mary", 16, "Female", "mary address");
        Patient patient4 = new Patient("arnold", 27, "Male", "address3");

        patientsList.addPatient(patient1);
        patientsList.addPatient(patient2);
        patientsList.addPatient(patient3);
        patientsList.addPatient(patient4);

        // This loop runs until user wants to exit
        while (true) {
            // Display menu
            displayMenu();

            // Get option from user
            int option = getOption(8);

            // If user wants to add a patient
            if (option == 1) {
                System.out.print("\nEnter name: ");
                name = scanner.nextLine();
                age = getInteger("age");
                sex = getGender();
                System.out.print("Enter address: ");
                address = scanner.nextLine();

                Patient patient = new Patient(name, age, sex, address);
                patientsList.addPatient(patient);
            }

            // If user wants to edit a patient
            else if (option == 2) {

                id = getInteger("id");
                Patient patient = patientsList.searchPatient(id);

                if (patient == null) {
                    System.out.println("Patient does not found.");
                    continue;
                }

                System.out.println();
                System.out.printf("%-3s | %-20s | %-5s | %-10s | %-30s\n", "ID", "Name", "Age", "Gender", "Address");
                System.out.printf("-------------------------------------------------------------------------------------------------\n");

                patient.display();
                while (true) {
                    displayEditMenu();
                    int edit_option = getOption(4);

                    if (edit_option == 0)
                        break;

                    else if (edit_option == 1) {
                        System.out.print("Enter new name: ");
                        name = scanner.nextLine();
                        patient.setName(name);
                    } else if (edit_option == 2) {
                        age = getInteger("age");
                        patient.setAge(age);

                    } else if (edit_option == 3) {
                        sex = getGender();
                        patient.setSex(sex);

                    } else if (edit_option == 4) {
                        System.out.print("Enter new address: ");
                        address = scanner.nextLine();
                        patient.setAddress(address);

                    }
                }


                patientsList.editPatient(patient);
            }

            // If user wants to remove a patient
            else if (option == 3) {
                id = getInteger("id");
                patientsList.deletePatient(id);
            }

            // If user wants to search for a patient
            else if (option == 4) {
                id = getInteger("id");

                Patient patient = patientsList.searchPatient(id);
                if (patient == null)
                    System.out.println("Patient does not found.");
                else {
                    System.out.println();
                    System.out.printf("%-3s | %-20s | %-5s | %-10s | %-30s\n", "ID", "Name", "Age", "Gender", "Address");
                    System.out.printf("-------------------------------------------------------------------------------------------------\n");
                    patient.display();
                }
            }

            // If user wants to sort the patients list by name
            else if (option == 5) {

                while (true) {
                    displaySortMenu();
                    int sort_option = getOption(3);

                    if (sort_option == 1)
                        patientsList.sortList(1);

                    else if (sort_option == 2)
                        patientsList.sortList(2);

                    else if (sort_option == 3)
                        patientsList.sortList(3);

                    else
                        break;

                }

            }

            // If user wants to display all the patients
            else if (option == 6) {
                patientsList.displayPatients();
            } else if (option == 7) {
                patientsList.clearList();
            } else if (option == 8) {
                System.out.println("\nPatients list size: " + patientsList.size);
            }

            // If user wants to quit from the program
            else {
                System.out.println("\nThank you!");
                break;
            }


        }
    }
}
