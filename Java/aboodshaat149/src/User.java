import java.util.Random;

public class User {
    private String name;
    private String email;
    private String password;

    public User(String name, String email, String password) {
        this.name = name;
        this.email = email;
        this.password = password;
    }

    public User(String name, String email) {
        this.name = name;
        this.email = email;

        String numbers = "0123456789";
        String capital = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        String simple = "abcdefghijklmnopqrstuvwxyz";
        String symbols = "!@#$&";

        String all = numbers + capital + simple + symbols;
        Random random = new Random();

        this.password = "";
        this.password += simple.charAt(random.nextInt(simple.length()));
        this.password += capital.charAt(random.nextInt(capital.length()));
        this.password += symbols.charAt(random.nextInt(symbols.length()));
        this.password += numbers.charAt(random.nextInt(numbers.length()));

        for(int i = 4; i< 12 ; i++) {
            this.password += all.charAt(random.nextInt(all.length()));
        }
    }

    public String getName() {
        return name;
    }

    public String getEmail() {
        return email;
    }

    public String getPassword() {
        return password;
    }

    @Override
    public String
    toString() {
        return "User{" +
                "name='" + name + '\'' +
                ", email='" + email + '\'' +
                ", password='" + password + '\'' +
                '}';
    }
}
