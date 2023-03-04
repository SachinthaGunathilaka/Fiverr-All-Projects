import java.util.ArrayList;
import java.util.Objects;

public class Accounts {
    private ArrayList<Account> accounts;

    public Accounts(){
        accounts = new ArrayList<Account>();
    }

    public void addAccount(Account account){
        accounts.add(account);
    }

    public boolean searchAccount(String id){
        for (Account account:accounts) {
            if(Objects.equals(account.getId(), id)){
                return true;
            }
        }
        return false;
    }
}
