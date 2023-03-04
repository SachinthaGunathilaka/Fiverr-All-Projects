// Question class
public class Question {

    // Attributes
    private String question;
    private String [] options;
    private char answer;

    // Constructor
    public Question(String question, String[] options, char answer) {
        this.question = question;
        this.options = options;
        this.answer = answer;
    }

    // getters
    public String getQuestion() {
        return question;
    }

    public String[] getOptions() {
        return options;
    }

    public char getAnswer() {
        return answer;
    }

    // method for display question
    public void displayQuestion(){
        // display question
        System.out.println(question);
        // display options
        for (int i = 0; i < 4; i++) {
            System.out.println(options[i]);
        }
        System.out.println();

    }
}
