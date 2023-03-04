public class FormService {
    private static FormService instance;
    public static FormService getInstance(){
        return null;
    }
    public Form getLoginForm(){
        return null;
    }
    public Form getUserForm(String action){
        return null;
    }
    public Form getActivityForm(String type){
        return null;
    }
    public Form getSubscriptionForm(){
        return null;
    }
    public Form getInterestForm(){
        return null;
    }
    public boolean isValid(Form form){
        return true;
    }
}
