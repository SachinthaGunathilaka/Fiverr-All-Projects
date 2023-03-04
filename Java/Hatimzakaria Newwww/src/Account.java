public class Account {
    private String name;
    private String birthday;
    private String Id;
    private String email;

    public Account(){

    }
    public Account(String name, String birthday, String id, String email) {
        this.name = name;
        this.birthday = birthday;
        this.Id = id;
        this.email = email;
    }

    public String getName() {
        return name;
    }

    public String getBirthday() {
        return birthday;
    }

    public String getId() {
        return Id;
    }

    public String getEmail() {
        return email;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setBirthday(String birthday) {
        this.birthday = birthday;
    }

    public void setId(String id) {
        Id = id;
    }

    public void setEmail(String email) {
        this.email = email;
    }

}
