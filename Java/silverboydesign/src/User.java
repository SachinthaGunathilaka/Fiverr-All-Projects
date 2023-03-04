import java.util.*;

public class User {
    private String fname;
    private String lname;
    private String email;
    private int password;

    public User(String fname, String lname) {
        this.fname = fname;
        this.lname = lname;
    }

    public void generateEmail() {
        this.email = (fname.charAt(0) + lname + "@gmail.com").toLowerCase(Locale.ROOT);
    }

    public void generateEmail(int digit) {
        this.email = (fname.charAt(0) + lname + digit + "@gmail.com").toLowerCase(Locale.ROOT);
    }

    public void generatePassword() {
        Random random = new Random();

        this.password = random.nextInt(1000000 - 100000) + 100000;

    }

    public void display() {
        System.out.printf("\n%-35s %-35s %-35s", (fname + " " + lname), email, password);

    }

    public static void main(String[] args) {
        LinkedList<User> users = new LinkedList<>();
        User user1, user2, user3, user4, user5;

        Scanner scanner = new Scanner(System.in);
        String fname, lname;

        for (int i = 0; i < 2; i++) {
            System.out.print("\nUser " + (i + 1) + " - Enter your first name: ");
            fname = scanner.nextLine();

            System.out.print("User " + (i + 1) + " - Enter your last name: ");
            lname = scanner.nextLine();

            user1 = new User(fname, lname);
            user1.generateEmail();

            for (User user:users) {
             if(Objects.equals(user.email, user1.email)){
                 Random random = new Random();

                 int digit = random.nextInt(10 - 2) + 2;
                 user1.generateEmail(digit);
                 break;
             }
            }
            user1.generatePassword();

            users.add(user1);

        }

        System.out.println("\n--------------------------------------------------------------------------------");
        System.out.printf("%-35s %-35s %-35s\n", "Full name", "Gmail email", "Password");
        System.out.println("--------------------------------------------------------------------------------");


        for (User user : users) {
            user.display();
        }
        System.out.println("\n\n--------------------------------------------------------------------------------");

    }

}
