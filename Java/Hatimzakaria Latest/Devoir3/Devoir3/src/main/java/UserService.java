import java.io.*;
import java.util.ArrayList;
import java.util.Objects;

public class UserService {
    private ArrayList<User> users;

    public void loadUsers(String filename) throws IOException {
        String line;
        try {
            BufferedReader br = new BufferedReader(new FileReader(filename));
            while ((line = br.readLine()) != null) {
                String[] data = line.split(",");
                Member member = new Member(data[1], data[2], data[4], data[3], data[5], data[0]);
                User user = new User(member);

                if (Objects.equals(data[6].strip(), "1"))
                    user.validate();
                UserService.getInstance().addUser(user);

            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void storeUsers(String filename) {
        try {
            FileWriter myWriter = new FileWriter(filename);

            for (User user : users) {
                int isValid = 0;
                if (user.isValid())
                    isValid = 1;
                myWriter.write(user.getMember().writeString() + "," + isValid + "\n");
            }
            myWriter.close();
            System.out.println("Successfully wrote to the file.");
        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }

    public UserService() {
        users = new ArrayList<User>();
    }

    private static UserService instance = new UserService();

    public static UserService getInstance() {
        return instance;
    }

    public ArrayList<User> getUsers() {
        return users;
    }

    public boolean addUser(User user) {
        if (isUser((user.getMember().getEmail()))) {
            System.out.println("User already exists!");
            return false;
        } else {
            users.add(user);
        }

        return true;
    }

    public boolean isUser(String email) {
        for (User user : users) {
            if (Objects.equals(user.getMember().getEmail(), email)) {
                return true;
            }
        }

        return false;
    }

    public boolean isLoggedin(String email) {
        for (User user : users) {
            if (Objects.equals(user.getMember().getEmail(), email)) {
                return user.isValid();
            }
        }

        return false;
    }

    public User login(String email, String pwd) {
        for (User user : users) {
            if (Objects.equals(user.getMember().getEmail(), email)) {
                if (Objects.equals(user.getMember().getPassword(), pwd)) {
                    user.setActive(true);
                    return user;
                } else {
                    System.out.println("Invalid Password!");
                    return null;
                }
            }
        }
        System.out.println("User not found!");
        return null;
    }

    public boolean logout(User current_user) {
        for (User user : users) {
            if (Objects.equals(user.getMember().getEmail(), current_user.getMember().getEmail())) {
                user.setActive(false);
                return true;
            }
        }

        System.out.println("User not found!");
        return false;


    }


    public User getUser(String email) {
        for (User user : users) {
            if (Objects.equals(user.getMember().getEmail(), email)) {
                return user;
            }
        }

        System.out.println("User not found!");
        return null;
    }

    public boolean isAdmin(String email) {
        for (User user : users) {
            if (Objects.equals(user.getMember().getEmail(), email)) {
                return Objects.equals(user.getMember().getRole(), "Admin");
            }
        }


        return false;
    }

    public boolean isSupervisor(String email) {
        for (User user : users) {
            if (Objects.equals(user.getMember().getEmail(), email)) {
                return Objects.equals(user.getMember().getRole(), "Supervisor");
            }
        }


        return false;
    }
}
