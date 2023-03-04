public class AccountController extends Controller {
    public User[] getUsers(FormData[] query){
        return null;
    }
    public boolean activateAccount(User user){
        return true;
    }
    public boolean deactivateAccount (User user){
        return true;
    }
    public boolean confirmAccount (User user){
        return true;
    }
    public Notification[] getNotifications(User user){
        return null;
    }
    public boolean hasNotification(User user) {
        return true;

    }
    public boolean changeRole(User user, Role role){
        return true;
    }
}
