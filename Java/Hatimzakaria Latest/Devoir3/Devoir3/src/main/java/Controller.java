import java.util.ArrayList;

public class Controller {
    ArrayList<Tool> tools;
    ArrayList<Article> articles;
    ArrayList<Project> projects;


    public Controller() {
        tools = new ArrayList<>();
        articles = new ArrayList<>();
        projects = new ArrayList<>();
    }

    public String get(String type, String query){
        return null;
    }
    public boolean post(Form form){
        return true;
    }
    public boolean delete(String type, String id){
        return true;
    }
    protected boolean validate(Form form){
        return true;
    }
    protected FormData[] parseQuery(String query){
        return null;
    }

}
