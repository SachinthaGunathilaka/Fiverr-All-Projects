import java.io.FileWriter;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // HashMap to store answers of each student (student_id : answers list)
        HashMap<String, char[]> answer_details = new HashMap<String, char[]>();
        int num_of_questions = 10; // number of questions

        // Create QuestionBank object
        QuestionBank questionBank = new QuestionBank("Computer Fundamentals");
        // load questions from questions.txt
        questionBank.loadQuestions("questions.txt");
        // get questions from question bank
        Question[] questions = questionBank.getQuestions(num_of_questions);


        int option;
        do {
            displayMenu(); // display menu
            option = getOption(); // get user selection

            // If user want to start the exam
            if (option == 1) {
                // char array for store answers of user
                char[] answers = new char[num_of_questions];

                // get user id as an input
                System.out.print("Enter your student ID: ");
                String id = scanner.nextLine();

                // Iterate through each question
                for (int i = 0; i < num_of_questions; i++) {
                    // display the question and options
                    System.out.println("\nQuestion " + (i + 1) + "/" + num_of_questions + "\n");
                    questions[i].displayQuestion();
                    System.out.print("Enter your answer: ");

                    // get user input for the answer
                    char answer = scanner.nextLine().toUpperCase().charAt(0);

                    // Get user input until user enter valid input (A, B, C, D)
                    while (answer < 65 || answer > 68) {
                        System.out.println("Only A, B, C or D are accepted");
                        System.out.print("Enter your answer: ");
                        answer = scanner.nextLine().toUpperCase().charAt(0);
                    }
                    answers[i] = answer; // add answer to answers array
                }

                // compare user answers with real answers and calculate total corrections
                int total_correct = 0;
                for (int i = 0; i < num_of_questions; i++) {
                    if (answers[i] == questions[i].getAnswer())
                        total_correct++;
                }

                // display results
                System.out.println("\nTotal correct : " + total_correct);
                System.out.println("Total incorrect : " + (num_of_questions - total_correct));

                // calculate grade using getGrade method
                double mark = total_correct * 100.00 / num_of_questions;
                char grade = getGrade(mark);
                // display grade
                System.out.println("Overall mark : " + (mark) + " % " + grade);
                // put all the answers to hashmap for future use (If the user wants to write these data to a file)
                answer_details.put(id, answers);
            }

            // If user wants to export results to a file
            if (option == 2) {
                try {
                    // Iterate through hashmap
                    for (Map.Entry<String, char[]> entry : answer_details.entrySet()) {
                        String key = entry.getKey();
                        char[] answers = entry.getValue();
                        // create file (name is userid.txt)
                        FileWriter myWriter = new FileWriter(key + ".txt");

                        // get date
                        long millis = System.currentTimeMillis();
                        java.sql.Date date = new java.sql.Date(millis);

                        // write user details to file
                        myWriter.write("Examination: " + questionBank.getTitle() + " " + date + "\n");
                        myWriter.write("Student Answers: \n");
                        myWriter.write( key + "\n");

                        // write user answers and correct answers to the file
                        for (int i = 0; i < num_of_questions; i++) {
                            if (answers[i] == questions[i].getAnswer())
                                myWriter.write((i + 1) + ") " + answers[i] + "\n");
                            else
                                myWriter.write((i + 1) + ") " + answers[i] + " (" + questions[i].getAnswer() + ")\n");

                        }

                        // write result to the file
                        int total_correct = 0;
                        for (int i = 0; i < num_of_questions; i++) {
                            if (answers[i] == questions[i].getAnswer())
                                total_correct++;
                        }

                        // calculate grade
                        double mark = total_correct * 100.00 / num_of_questions;
                        char grade = getGrade(mark);
                        // write grade to the file
                        myWriter.write("\n(" + key + ") : " + mark + "% " + grade + "\n");
                        myWriter.close();

                    }

                }
                // If there is an error while writing
                catch (Exception e) {
                    System.out.println("An error occurred.");
                    e.printStackTrace();
                }
            }
        } while (option != 3);
    }

    // method to diplay all the options available
    public static void displayMenu() {
        System.out.println("\n\n1) Start Examination\n" +
                "2) Export Results\n" +
                "3) Exit");
    }

    // method to get option from the user
    public static int getOption() {

        // get user input
        System.out.print("Enter option : ");
        Scanner scanner = new Scanner(System.in);
        int option = scanner.nextInt();

        // If the user input is not valid
        while (option < 1 || option > 3) {
            System.out.println("Invalid input");
            System.out.print("Enter option : ");
            option = scanner.nextInt();
        }
        return option;
    }

    //  a method to calculate grade according to the given mark
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
