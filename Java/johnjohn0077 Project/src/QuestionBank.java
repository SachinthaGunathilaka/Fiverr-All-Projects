import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.*;

// QuestionBank class
public class QuestionBank {

    // Attributes
    private Question[] questions;
    private String title;
    private int index;

    // Constructor
    public QuestionBank(String title) {
        this.title = title;
        questions = new Question[100]; // only 100 questions allowed
        index = 0;

    }

    // setters
    public void setTitle(String title) {
        this.title = title;
    }

    // getters
    public String getTitle() {
        return title;
    }

    // method to load questions from a file
    public void loadQuestions(String file) {
        try {
            FileInputStream fis = new FileInputStream(file);
            Scanner sc = new Scanner(fis);

            // read file line by line
            while (sc.hasNextLine()) {
                String question = sc.nextLine();
                String options[] = new String[4];
                options[0] = sc.nextLine();
                options[1] = sc.nextLine();
                options[2] = sc.nextLine();
                options[3] = sc.nextLine();
                char answer = sc.nextLine().charAt(0);

                // create Question object with details in the file
                Question question_obj = new Question(question, options, answer);
                // add Question to questions array
                questions[index++] = question_obj;


            }
            sc.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    // method for get number of questions
    public int getQuestionBankSize() {
        return index;
    }

    // method to view Questions (Only 3 questions will be shown per time)
    public void viewQuestions() {
        int index_ = 0;
        while (true) {
            // display 3 questions
            for (int i = index_; i < 3 + index_; i++) {
                if (i == index)
                    return;
                questions[i].displayQuestion();
            }

            // Ask from user whether he wants to see next 3 questions also
            Scanner scanner = new Scanner(System.in);
            System.out.println("Do you want to see next questions? (Y/N) : ");
            char option = scanner.nextLine().toUpperCase().charAt(0);

            // If user does not want to see next questions break
            if (option != 'Y') {
                break;
            }
            index_ += 3;
        }


    }

    // method to randomly choose questions
    public Question[] getQuestions(int num_of_questions) {
        Question[] random_questions = new Question[num_of_questions];
        Random random = new Random();

        // list contains integers from 0 to num_of_questions
        ArrayList<Integer> list = new ArrayList<Integer>();
        for (int i = 1; i < index; i++) {
            list.add(i);
        }

        // shuffle the list
        Collections.shuffle(list);

        // randomly choose question using list
        for (int i = 0; i < num_of_questions; i++) {
            random_questions[i] = questions[list.get(i)];
        }
        return random_questions;
    }

    // method to display detail about the questions
    public void showQuestionsDetails() {
        System.out.println("Title : " + title);
        System.out.println("Number of Questions  : " + index);
    }

    // method to reset the QuestionBank
    public void resetQuestionBank() {
        questions = new Question[100];
        index = 0;
        title = "";
    }
}
