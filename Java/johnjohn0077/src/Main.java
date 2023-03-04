import java.io.File;
import java.io.FileWriter;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        HashMap<String, char[]> answer_details = new HashMap<String, char[]>();
        int num_of_questions = 10;

        QuestionBank questionBank = new QuestionBank("Computer Fundamentals");
        questionBank.loadQuestions("questions.txt");
        Question[] questions = questionBank.getQuestions(num_of_questions);


        int option;
        do {
            displayMenu();
            option = getOption();
            if (option == 1) {
                char[] answers = new char[num_of_questions];
                System.out.print("Enter your student ID: ");
                String id = scanner.nextLine();


                for (int i = 0; i < num_of_questions; i++) {
                    System.out.println("\nQuestion " + (i + 1) + "/" + num_of_questions + "\n");
                    questions[i].displayQuestion();
                    System.out.print("Enter your answer: ");
                    char answer = scanner.nextLine().toUpperCase().charAt(0);
                    while (answer < 65 || answer > 68) {
                        System.out.println("Only A, B, C or D are accepted");
                        System.out.print("Enter your answer: ");
                        answer = scanner.nextLine().toUpperCase().charAt(0);

                    }
                    answers[i] = answer;
                }

                int total_correct = 0;
                for (int i = 0; i < num_of_questions; i++) {
                    if (answers[i] == questions[i].getAnswer())
                        total_correct++;
                }

                System.out.println("\nTotal correct : " + total_correct);
                System.out.println("Total incorrect : " + (num_of_questions - total_correct));

                double mark = total_correct * 100.00 / num_of_questions;
                char grade = getGrade(mark);
                System.out.println("Overall mark : " + (mark) + " % " + grade);
                answer_details.put(id, answers);
            }

            if (option == 2) {
                try {
                    for (Map.Entry<String, char[]> entry : answer_details.entrySet()) {
                        String key = entry.getKey();
                        char[] answers = entry.getValue();
                        FileWriter myWriter = new FileWriter(key + ".txt");

                        long millis = System.currentTimeMillis();
                        java.sql.Date date = new java.sql.Date(millis);

                        myWriter.write("Examination: " + questionBank.getTitle() + " " + date + "\n");
                        myWriter.write("Student Answers: \n");
                        myWriter.write( key + "\n");

                        for (int i = 0; i < num_of_questions; i++) {
                            if (answers[i] == questions[i].getAnswer())
                                myWriter.write((i + 1) + ") " + answers[i] + "\n");
                            else
                                myWriter.write((i + 1) + ") " + answers[i] + " (" + questions[i].getAnswer() + ")\n");

                        }

                        int total_correct = 0;
                        for (int i = 0; i < num_of_questions; i++) {
                            if (answers[i] == questions[i].getAnswer())
                                total_correct++;
                        }

                        double mark = total_correct * 100.00 / num_of_questions;
                        char grade = getGrade(mark);
                        myWriter.write("\n(" + key + ") : " + mark + "% " + grade + "\n");
                        myWriter.close();

                    }

                } catch (Exception e) {
                    System.out.println("An error occurred.");
                    e.printStackTrace();
                }
            }
        } while (option != 3);
    }

    public static void displayMenu() {
        System.out.println("\n\n1) Start Examination\n" +
                "2) Export Results\n" +
                "3) Exit");
    }

    public static int getOption() {
        System.out.print("Enter option : ");
        Scanner scanner = new Scanner(System.in);
        int option = scanner.nextInt();
        while (option < 1 || option > 3) {
            System.out.println("Invalid input");
            System.out.print("Enter option : ");
            option = scanner.nextInt();
        }
        return option;
    }

    public static char getGrade(double mark) {
        if (mark >= 90)
            return 'A';
        if (mark >= 80)
            return 'B';
        if (mark >= 70)
            return 'C';
        if (mark >= 60)
            return 'D';
        return 'E';
    }
}
