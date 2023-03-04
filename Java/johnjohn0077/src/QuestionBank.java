import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.*;

public class QuestionBank {
    private Question[] questions;
    private String title;
    private int index;

    public QuestionBank(String title) {
        this.title = title;
        questions = new Question[100];
        index = 0;

    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getTitle() {
        return title;
    }

    public void loadQuestions(String file) {
        try {
            FileInputStream fis = new FileInputStream(file);
            Scanner sc = new Scanner(fis);
            while (sc.hasNextLine()) {
                String question = sc.nextLine();
                String options[] = new String[4];
                options[0] = sc.nextLine();
                options[1] = sc.nextLine();
                options[2] = sc.nextLine();
                options[3] = sc.nextLine();
                char answer = sc.nextLine().charAt(0);
                Question question_obj = new Question(question, options, answer);
                questions[index++] = question_obj;


            }
            sc.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public int getQuestionBankSize() {
        return index;
    }

    public void viewQuestions() {
        int index_ = 0;
        while (true) {
            for (int i = index_; i < 3 + index_; i++) {
                if (i == index)
                    return;
                questions[i].displayQuestion();
            }
            Scanner scanner = new Scanner(System.in);
            System.out.println("Do you want to see next questions? (Y/N) : ");
            char option = scanner.nextLine().toUpperCase().charAt(0);
            if (option != 'Y') {
                break;
            }
            index_ += 3;
        }


    }

    public Question[] getQuestions(int num_of_questions) {
        Question[] random_questions = new Question[num_of_questions];
        Random random = new Random();

        ArrayList<Integer> list = new ArrayList<Integer>();
        for (int i = 1; i < index; i++) {
            list.add(i);
        }
        Collections.shuffle(list);
        for (int i = 0; i < num_of_questions; i++) {
            random_questions[i] = questions[list.get(i)];
        }
        return random_questions;
    }

    public void showQuestionsDetails() {
        System.out.println("Title : " + title);
        System.out.println("Number of Questions  : " + index);
    }

    public void resetQuestionBank() {
        questions = new Question[100];
        index = 0;
        title = "";
    }
}
