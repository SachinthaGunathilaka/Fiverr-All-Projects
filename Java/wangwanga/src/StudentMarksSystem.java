import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.util.Scanner;

public class StudentMarksSystem {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Students students = new Students();
        loadStudents("students.txt", students);

        Subjects subjects = new Subjects();
        loadSubjects("subjects.txt", subjects);

        Marks marks = new Marks();
        loadMarks("marks.txt", marks);

        int option;
        do {
            displayMainMenu();
            option = getInput(1, 6, "\nSelect option : ");
            int second_option;

            if (option == 1) {
                while (true) {
                    displaySecondaryMenu("Student");
                    second_option = getInput(1, 6, "\nSelect option : ");

                    if (second_option == 1) {
                        System.out.print("Enter student id : ");
                        String id = scanner.nextLine();
                        System.out.print("Enter student name : ");
                        String name = scanner.nextLine();

                        Student student = new Student(id, name);
                        students.addStudent(student);
                        System.out.println("Student added successfully!");

                    } else if (second_option == 2) {
                        System.out.print("Enter student id : ");
                        String id = scanner.nextLine();
                        System.out.print("Enter student new name : ");
                        String name = scanner.nextLine();

                        boolean isSuccess = students.editStudent(id, name);
                        if (isSuccess)
                            System.out.println("Student edited successfully!");
                        else
                            System.out.println("Student not found!");
                    } else if (second_option == 3) {
                        System.out.print("Enter student id : ");
                        String id = scanner.nextLine();

                        boolean isSuccess = students.deleteStudent(id);
                        if (isSuccess)
                            System.out.println("Student deleted successfully!");
                        else
                            System.out.println("Student not found!");
                    } else if (second_option == 4) {
                        System.out.print("Enter student id : ");
                        String id = scanner.nextLine();

                        Student student1 = students.getStudent(id);
                        if (student1 != null)
                            student1.displayStudent();
                        else
                            System.out.println("Student not found!");
                    } else if (second_option == 5) {
                        students.displayStudents();
                    } else {
                        break;
                    }
                }
            } else if (option == 2) {
                while (true) {
                    displaySecondaryMenu("Subject");
                    second_option = getInput(1, 6, "\nSelect option : ");

                    if (second_option == 1) {
                        System.out.print("Enter subject id : ");
                        String id = scanner.nextLine();
                        System.out.print("Enter subject name : ");
                        String name = scanner.nextLine();

                        Subject subject = new Subject(id, name);
                        subjects.addSubject(subject);
                        System.out.println("Subject added successfully!");

                    } else if (second_option == 2) {
                        System.out.print("Enter subject id : ");
                        String id = scanner.nextLine();
                        System.out.print("Enter subject new name : ");
                        String name = scanner.nextLine();

                        boolean isSuccess = subjects.editSubject(id, name);
                        if (isSuccess)
                            System.out.println("Subject edited successfully!");
                        else
                            System.out.println("Subject not found!");
                    } else if (second_option == 3) {
                        System.out.print("Enter subject id : ");
                        String id = scanner.nextLine();

                        boolean isSuccess = subjects.deleteSubject(id);
                        if (isSuccess)
                            System.out.println("Subject deleted successfully!");
                        else
                            System.out.println("Subject not found!");
                    } else if (second_option == 4) {
                        System.out.print("Enter subject id : ");
                        String id = scanner.nextLine();

                        Subject subject1 = subjects.getSubject(id);
                        if (subject1 != null)
                            subject1.displaySubject();
                        else
                            System.out.println("Subject not found!");
                    } else if (second_option == 5) {
                        subjects.displaySubjects();
                    } else {
                        break;
                    }
                }
            } else if (option == 3) {
                while (true) {
                    displaySecondaryMenu("Mark");
                    second_option = getInput(1, 6, "\nSelect option : ");

                    if (second_option == 1) {
                        System.out.print("Enter student id : ");
                        String std_id = scanner.nextLine();
                        System.out.print("Enter subject id : ");
                        String sub_id = scanner.nextLine();
                        System.out.print("Enter mark : ");
                        Double score = Double.parseDouble(scanner.nextLine());

                        if (!students.isExist(std_id))
                            System.out.println("Student not found");

                        else if (!subjects.isExist(sub_id))
                            System.out.println("Subject not found");

                        else {
                            Mark mark = new Mark(std_id, score);
                            boolean isSuccess = marks.addMark(sub_id, mark);
                            if (isSuccess)
                                System.out.println("Mark added successfully!");
                            else
                                System.out.println("Mark already exists");
                        }
                    } else if (second_option == 2) {
                        System.out.print("Enter student id : ");
                        String std_id = scanner.nextLine();
                        System.out.print("Enter subject id : ");
                        String sub_id = scanner.nextLine();
                        System.out.print("Enter new mark : ");
                        Double score = Double.parseDouble(scanner.nextLine());
                        boolean isSuccess = marks.editMark(sub_id, std_id, score);
                        if (isSuccess)
                            System.out.println("Mark edited successfully!");
                        else
                            System.out.println("Mark not found!");
                    } else if (second_option == 3) {
                        System.out.print("Enter student id : ");
                        String std_id = scanner.nextLine();
                        System.out.print("Enter subject id : ");
                        String sub_id = scanner.nextLine();

                        boolean isSuccess = marks.deleteMark(sub_id, std_id);
                        if (isSuccess)
                            System.out.println("Mark deleted successfully!");
                        else
                            System.out.println("Mark not found!");

                    } else if (second_option == 4) {
                        System.out.print("Enter student id : ");
                        String std_id = scanner.nextLine();
                        System.out.print("Enter subject id : ");
                        String sub_id = scanner.nextLine();

                        Mark mark1 = marks.getMark(sub_id, std_id);
                        if (mark1 != null)
                            mark1.displayMark();
                        else
                            System.out.println("Mark not found!");
                    } else if (second_option == 5) {
                        marks.displayMarksSubjectsVise();
                    } else {
                        break;
                    }
                }
            } else if (option == 4) {
                int current_index = 0;
                boolean isShow = true;
                int option3;
                do {
                    if (isShow) {
                        Student student = students.getStudentByIndex(current_index);
                        System.out.printf("\n     %-20s(%s)\n", student.getName(), student.getId());
                        System.out.println("--------------------------------------");
                        marks.displayStudentResults(student.getId(), subjects);
                    }

                    studentShowMenu();
                    option3 = getInput(1, 3, "\nSelect option : ");
                    if (option3 == 1) {
                        if (current_index == 0) {
                            System.out.println("No previous student");
                            isShow = false;
                        } else {
                            current_index--;
                            isShow = true;
                        }
                    } else if (option3 == 2) {
                        if (current_index == students.getNumOfStudents() - 1) {
                            System.out.println("No next student");
                            isShow = false;
                        } else {
                            current_index++;
                            isShow = true;
                        }
                    }
                } while (option3 != 3);
            }
            // Generating reports part
            else if (option == 5) {

                while (true) {
                    reportsMenu(); // Display the report menu

                    // Get user input
                    int report_option = getInput(1, 5, "\nSelect option : ");

                    // Generate report for a student
                    if (report_option == 1) {

                        // Get student id
                        System.out.print("Enter student id : ");
                        String std_id = scanner.nextLine();

                        // Get student object from students array
                        Student student = students.getStudent(std_id);

                        // If student exists
                        if (student != null) {

                            System.out.printf("\n     %-20s(%s)\n", student.getName(), student.getId());
                            System.out.println("--------------------------------------");
                            // display the report
                            marks.displayStudentResults(student.getId(), subjects);
                        }
                        // If the student does not exist
                        else {
                            System.out.println("\nNo student found");
                        }
                    }

                    // Generate report of all the students
                    else if(report_option == 2){
                        marks.displayAllStdReport(students, subjects);
                    }

                    // Generate report for a unit
                    else if (report_option == 3) {
                        // Get unit id
                        System.out.print("Enter unit id : ");
                        String unit_id = scanner.nextLine();

                        // Get the unit object from subjects
                        Subject subject = subjects.getSubject(unit_id);

                        // If the unit exists
                        if (subject != null) {
                            System.out.printf("\n   %-25s(%s)\n", subject.getName(), subject.getId());
                            System.out.println("--------------------------------------");
                            // display report
                            marks.displayUnitReport(unit_id);
                        }
                        // If the unit does not exists
                        else {
                            System.out.println("\nNo unit found");
                        }
                    }

                    // Generate report for all the units
                    else if(report_option == 4){
                        // display report for all the units
                        marks.displayAllUnitReport(subjects);
                    }
                    else {
                        break;
                    }
                }


            }


        }
        while (option != 6);


        writeStudents("students.txt", students);
        writeSubjects("subjects.txt", subjects);
        writeMarks("marks.txt", marks);
        System.out.println("\nData saved successfully!");


    }

    public static void displayMainMenu() {
        System.out.println("\n+----------------------------+");
        System.out.println("|    Student Marks System    |");
        System.out.println("+----------------------------+");

        System.out.println(
                "\n1) Handling Students\n" +
                        "2) Handling Subjects\n" +
                        "3) Handling Marks\n" +
                        "4) Display Students One By One\n" +
                        "5) Generate Reports\n" +
                        "6) Exit");
    }


    public static void displaySecondaryMenu(String object) {
        System.out.println("\n+----------------------------+");
        System.out.printf("|     Handling %-11s   |\n", object + "s");
        System.out.println("+----------------------------+");
        System.out.println(
                "\n1) Add " + object + "\n" +
                        "2) Edit " + object + "\n" +
                        "3) Delete " + object + "\n" +
                        "4) Search " + object + " By ID\n" +
                        "5) Show All " + object + "s\n" +
                        "6) Go to Main Menu");
    }

    public static void studentShowMenu() {
        System.out.println("\n+------------------------------------+");
        System.out.println("|     Display Students One By One    |");
        System.out.println("+------------------------------------+");

        System.out.println("\n1) Show Previous Student\n" +
                "2) Show Next Student\n" +
                "3) Go to Main Menu");
    }

    public static void reportsMenu() {
        System.out.println("\n+------------------------------------+");
        System.out.println("|          Generate Reports          |");
        System.out.println("+------------------------------------+");

        System.out.println("\n1) Report For Student\n" +
                "2) Report For All Students\n" +
                "3) Report For Unit\n" +
                "4) Report For All Units\n" +
                "5) Go to Main Menu");
    }

    public static int getInput(int low, int high, String message) {
        Scanner scanner = new Scanner(System.in);
        System.out.print(message);
        int input = Integer.parseInt(scanner.nextLine());

        while (input < low || input > high) {
            System.out.println("Invalid Input");
            System.out.print(message);
            input = Integer.parseInt(scanner.nextLine());
        }
        return input;


    }

    public static void loadStudents(String filename, Students students) {
        try {
            File myObj = new File(filename);
            Scanner myReader = new Scanner(myObj);
            while (myReader.hasNextLine()) {
                String data[] = myReader.nextLine().split(",");
                Student student = new Student(data[0], data[1]);
                students.addStudent(student);
            }
            myReader.close();
        } catch (FileNotFoundException e) {
            System.out.println(filename + " file not found");
        }
    }

    public static void loadSubjects(String filename, Subjects subjects) {
        try {
            File myObj = new File(filename);
            Scanner myReader = new Scanner(myObj);
            while (myReader.hasNextLine()) {
                String data[] = myReader.nextLine().split(",");
                Subject subject = new Subject(data[0], data[1]);
                subjects.addSubject(subject);
            }
            myReader.close();
        } catch (FileNotFoundException e) {
            System.out.println(filename + " file not found");
        }
    }

    public static void loadMarks(String filename, Marks marks) {
        try {
            File myObj = new File(filename);
            Scanner myReader = new Scanner(myObj);
            while (myReader.hasNextLine()) {
                String data[] = myReader.nextLine().split(",");
                Mark mark = new Mark(data[0], Double.parseDouble(data[2]));
                marks.addMark(data[1], mark);
            }
            myReader.close();
        } catch (FileNotFoundException e) {
            System.out.println(filename + " file not found");
        }
    }

    public static void writeStudents(String filename, Students students) {
        try {
            FileWriter fw = new FileWriter(filename);
            for (Student student : students.getStudents()) {
                fw.write(student.getId() + "," + student.getName() + "\n");
            }
            fw.close();
        } catch (Exception e) {
            System.out.println("Error writing file");
        }
    }

    public static void writeSubjects(String filename, Subjects subjects) {
        try {
            FileWriter fw = new FileWriter(filename);
            for (Subject subject : subjects.getSubjects()) {
                fw.write(subject.getId() + "," + subject.getName() + "\n");
            }
            fw.close();
        } catch (Exception e) {
            System.out.println("Error writing file");
        }
    }

    public static void writeMarks(String filename, Marks marks) {
        try {
            FileWriter fw = new FileWriter(filename);
            for (String key : marks.getMarks().keySet()) {
                for (Mark mark : marks.getMarks().get(key)) {
                    fw.write(mark.getStd_id() + "," + key + "," + mark.getMark() + "\n");
                }
            }

            fw.close();
        } catch (Exception e) {
            System.out.println("Error writing file");
        }
    }


}


