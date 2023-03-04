import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
//        ArrayList<>
        String name;
        String email;
        String password;

        System.out.print("Enter account email : ");
        email = scanner.nextLine();

        System.out.print("Enter account username : ");
        name = scanner.nextLine();

        System.out.print("Enter account password : ");
        password = scanner.nextLine();

        User user1 = new User(name, email, password);
        User user2 = new User(name, email);

        System.out.println(user1);
        System.out.println(user2);

    }
}
