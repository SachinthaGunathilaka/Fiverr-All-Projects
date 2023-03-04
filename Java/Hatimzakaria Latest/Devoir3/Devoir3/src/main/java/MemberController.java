import java.util.Objects;

public class MemberController extends Controller {
    public Member[] getMembers(FormData[] query) {
        return null;
    }

    public void displayMembers() {

        System.out.println("\n List of Members");
        System.out.println("-------------------------");
        UserService userService = UserService.getInstance();

        for (User user : userService.getUsers()) {
            System.out.println(user.getMember().getEmail());
        }
    }

    public boolean displayMember(String email){
        for (User user : UserService.getInstance().getUsers()) {
            if(Objects.equals(user.getMember().getEmail(), email)){
                System.out.println(user.getMember());
                return true;
            }
        }
        System.out.println("User not found!");
        return false;

    }

    public boolean createMember(Member member) {

        return true;
    }

    public Member updateMember(String id, Member member) {
        return null;
    }

    public boolean addInterest(Member member, Interest interest) {
        return true;
    }

    public boolean removeInterest(Member member, Interest interest) {
        return true;


    }

    public void showNotValidatedAccounts(){
        System.out.println("\nAccounts needs to validate");
        System.out.println("----------------------------");
        for (User user:UserService.getInstance().getUsers()) {
            if(!user.isValid()){
                System.out.println(user.getMember().getEmail());
            }
        }
    }

    public void validateAccount(String email){
        for (User user:UserService.getInstance().getUsers()) {
            if(!user.isValid() && Objects.equals(user.getMember().getEmail(), email)){
                user.validate();
                return;
            }
        }

        System.out.println("Account not found!");
    }
}
