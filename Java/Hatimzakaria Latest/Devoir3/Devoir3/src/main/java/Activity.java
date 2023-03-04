import java.util.UUID;

public class Activity {
    protected String id;
    protected String title;
    protected String description;
    private Member responsable;
    private String[] keywords;
    private User modifiedUser;
    private String modifiedDate;
    private Member creator;
    public User[] getSubscibers(){
        return null;
    }
    public String getShortInformation(){
        return null;
    }
    public String getCompletInformation(){
        return null;
    }

    public Activity(String title, String description) {
        this.id = UUID.randomUUID().toString();
        this.title = title;
        this.description = description;
    }

    public String getId() {
        return id;
    }


    public void setId(String id) {
        this.id = id;
    }

    public String getTitle() {
        return title;
    }

    public String getDescription() {
        return description;
    }
}
