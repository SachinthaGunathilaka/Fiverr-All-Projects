import java.util.ArrayList;

public class AllUsers {
    private static final ArrayList<User> users = new ArrayList<>();

    public static void addMember(int member_id, String name) {
        for (User user : users) {
            if (user.getMember_id() == member_id) {
                System.out.println("User id already exists!");
                return;
            }
        }
        User user = new User(member_id, name);
        users.add(user);
    }

    public static void requestItem(int member_id, int item_number) {
        for (User user : users) {
            if (user.getMember_id() == member_id) {
                user.requestItem(item_number);
                return;
            }
        }

        System.out.println("Member id does not found!");
    }

    public static void readFromFile(int member_id, int item_number) {
        for (User user : users) {
            if (user.getMember_id() == member_id) {
                user.readFromFile(item_number);
                break;
            }
        }
    }

    public static void displayMembers() {
        for (User user : users) {
            user.display();
        }
    }

    public static void returnItem(int member_id, int item_number){
        for (User user : users) {
            if(user.getMember_id() == member_id){
                user.returnItem(item_number);
                break;
            }
        }
    }
}
