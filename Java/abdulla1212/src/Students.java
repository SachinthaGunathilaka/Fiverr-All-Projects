import java.io.*;
import java.util.Scanner;

public class Students {
    static String names[] = new String[20];
    static String ids[] = new String[20];
    static int exams[] = new int[20];
    static int assignments[] = new int[20];
    static int totals[] = new int[20];
    static int examsW = 40;
    static int assignsW = 60;
    static int regStudents;


    public static void readData() {
        System.out.print("Enter the file name: ");
        Scanner scanner = new Scanner(System.in);
        String filename = scanner.nextLine();
        System.out.print("Enter number of students (1-20): ");
        regStudents = Integer.parseInt(scanner.nextLine());

        try {
            int index = 0;
            FileInputStream fis = new FileInputStream(filename);
            Scanner sc = new Scanner(fis);
            while (sc.hasNextLine()) {
                if (index == 20)
                    break;
                String line = sc.nextLine();
                String[] data = line.split(" ");
                names[index] = data[0].strip();
                ids[index] = data[1].strip();
                assignments[index] = Integer.parseInt(data[2]);
                exams[index] = Integer.parseInt(data[3]);
                totals[index] = assignments[index] + exams[index];

                index++;
            }
            sc.close();
        } catch (IOException e) {
            System.out.println("File not found!");
        }

        for (int i = 0; i < regStudents; i++) {
            setValidName(i);
            setValidID(i);
            setValidMark(i, 'A');
            setValidMark(i, 'E');
        }

        System.out.println("Data is successfully saved!!");
    }

    public static void setValidName(int index) {
        boolean isValid = true;
        Scanner scanner = new Scanner(System.in);
        for (int i = 0; i < names[index].length(); i++) {
            if (!(Character.isAlphabetic(names[index].charAt(i)) || names[index].charAt(i) == '_')) {
                isValid = false;
                break;
            }
        }

        if (isValid)
            return;

        System.out.print("Error in name at index " + index + " (" + names[index] + ").");
        System.out.print(" Please enter correct name: ");
        names[index] = scanner.nextLine();
        setValidName(index);
    }

    public static void setValidID(int index) {
        boolean isValid = true;
        Scanner scanner = new Scanner(System.in);
        for (int i = 0; i < ids[index].length(); i++) {
            if (!Character.isDigit(ids[index].charAt(i))) {
                isValid = false;
                break;
            }
        }

        if (isValid)
            return;

        System.out.print("Error in ID at index " + index + " (" + ids[index] + ").");
        System.out.print(" Please enter correct id: ");
        ids[index] = scanner.nextLine();
        setValidID(index);
    }

    public static void setValidMark(int index, char type) {
        boolean isValid = true;
        Scanner scanner = new Scanner(System.in);

        int max_weight = type == 'A' ? assignsW : examsW;
        int[] marks = type == 'A' ? assignments : exams;
        String text = type == 'A' ? "Assignment" : "Exam";


        if (marks[index] < 0 || marks[index] > max_weight) {
            System.out.print("Error in " + text + " at index " + index + " (" + marks[index] + ").");
            System.out.print(" Please enter correct mark (0-" + max_weight + "): ");
            marks[index] = Integer.parseInt(scanner.nextLine());
            setValidMark(index, type);
        }

    }

    public static int getIndexByID(String id) {
        for (int i = 0; i < regStudents; i++) {
            if (ids[i].equals(id)) {
                return i;
            }
        }

        return -1;
    }

    public static int getMaxIndex(char type) {
        int[] marks = type == 'E' ? exams : type == 'A' ? assignments : totals;

        int maximum_mark = marks[0];
        int index = 0;
        for (int i = 1; i < regStudents; i++) {
            if (maximum_mark < marks[i]) {
                maximum_mark = marks[i];
                index = i;
            }
        }

        return index;
    }

    public static int getMinIndex(char type) {
        int[] marks = type == 'E' ? exams : type == 'A' ? assignments : totals;

        int minimum_mark = marks[0];
        int index = 0;
        for (int i = 1; i < regStudents; i++) {
            if (minimum_mark > marks[i]) {
                minimum_mark = marks[i];
                index = i;
            }
        }

        return index;
    }

    public static int getAvg(char type) {
        int[] marks = type == 'E' ? exams : type == 'A' ? assignments : totals;
        System.out.println(marks[0]);

        double sum = 0;
        for (int i = 0; i < regStudents; i++) {
            sum += marks[i];
        }

        return (int) Math.round(sum / regStudents);
    }

    public static void PrintDetailsByID(String id) {
        int index = getIndexByID(id);
        if (index == -1) {
            System.out.println("ID not found");
            return;
        }
        System.out.printf("%-20s %-10s       %-10s%-10s%-10s\n", "Name", "ID", "Assign.", "Exams", "Total");
        System.out.printf("%-20s%10s%10d%10d%10d\n", names[index], ids[index], assignments[index], exams[index], totals[index]);
    }

    public static void printDetails() {

        System.out.printf("%-20s %-10s       %-10s%-10s%-10s\n", "Name", "ID", "Assign.", "Exams", "Total");
        for (int index = 0; index < regStudents; index++) {
            System.out.printf("%-20s%10s%10d%10d%10d\n", names[index], ids[index], assignments[index], exams[index], totals[index]);
        }
    }

    public static void displayMenu() {
        System.out.println("MENU\n" +
                "1. Find maximum mark\n" +
                "2. Find minimum mark\n" +
                "3. Find average\n" +
                "4. Print details for a student\n" +
                "5. Print details for all students");
    }

    public static int secondaryMenuOption() {
        System.out.println("1. Assignments, 2. Exams, 3. Totals");
        System.out.print("Please specify (1-3): ");
        Scanner scanner = new Scanner(System.in);
        return Integer.parseInt(scanner.nextLine());
    }


    public static int getInput() {
        System.out.print("Please select your option (1-5): ");
        Scanner scanner = new Scanner(System.in);
        return Integer.parseInt(scanner.nextLine());
    }


    public static void main(String[] args) {
        readData();

        while (true) {
            displayMenu();
            int option = getInput();

            if (option == 1) {
                int secondary_option = secondaryMenuOption();
                int index = 0;
                boolean isError = false;
                if (secondary_option == 1) {
                    index = getMaxIndex('A');
                } else if (secondary_option == 2) {
                    index = getMaxIndex('E');
                } else if (secondary_option == 3) {
                    index = getMaxIndex('T');
                } else {
                    System.out.println("Error in entry");
                    isError = true;
                }

                if (!isError) {
                    System.out.printf("%-20s %-10s       %-10s%-10s%-10s\n", "Name", "ID", "Assign.", "Exams", "Total");
                    System.out.printf("%-20s%10s%10d%10d%10d\n", names[index], ids[index], assignments[index], exams[index], totals[index]);
                }

            } else if (option == 2) {
                int secondary_option = secondaryMenuOption();
                int index = 0;
                boolean isError = false;

                if (secondary_option == 1) {
                    index = getMinIndex('A');
                } else if (secondary_option == 2) {
                    index = getMinIndex('E');
                } else if (secondary_option == 3) {
                    index = getMinIndex('T');
                } else {
                    System.out.println("Error in entry");
                    isError = true;
                }

                if (!isError) {
                    System.out.printf("%-20s %-10s       %-10s%-10s%-10s\n", "Name", "ID", "Assign.", "Exams", "Total");
                    System.out.printf("%-20s%10s%10d%10d%10d\n", names[index], ids[index], assignments[index], exams[index], totals[index]);
                }
            } else if (option == 3) {
                int secondary_option = secondaryMenuOption();
                boolean isError = false;

                int average = 0;
                if (secondary_option == 1) {
                    average = getAvg('A');
                } else if (secondary_option == 2) {
                    average = getAvg('E');
                } else if (secondary_option == 3) {
                    average = getAvg('T');
                } else {
                    System.out.println("Error in entry");
                    isError = true;
                }

                if (!isError)
                    System.out.println("Average : " + average);


            } else if (option == 4) {
                System.out.print("Enter the student ID: ");

                Scanner scanner = new Scanner(System.in);
                String id = scanner.nextLine();

                PrintDetailsByID(id);
            } else if (option == 5) {
                printDetails();
            } else {
                System.out.println("Error in entry");
            }

            Scanner scanner = new Scanner(System.in);
            System.out.print("Do you want to continue (Y/N)? ");
            int yes_no = scanner.nextLine().toLowerCase().charAt(0);

            if (yes_no != 'y') {
                break;
            }
        }

        System.out.println("Thank you for testing our Project!! Good bye!!");
    }
}
