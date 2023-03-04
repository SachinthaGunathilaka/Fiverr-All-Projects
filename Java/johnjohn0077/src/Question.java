public class Question {
    private String question;
    private String [] options;
    private char answer;

    public Question(String question, String[] options, char answer) {
        this.question = question;
        this.options = options;
        this.answer = answer;
    }

    public String getQuestion() {
        return question;
    }

    public String[] getOptions() {
        return options;
    }

    public char getAnswer() {
        return answer;
    }

    public void displayQuestion(){
        System.out.println(question);
        for (int i = 0; i < 4; i++) {
            System.out.println(options[i]);
        }
        System.out.println();

    }
}
