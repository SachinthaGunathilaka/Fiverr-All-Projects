public class Subject {
    private String id;
    private String name;

    public Subject(String id, String name) {
        this.id = id;
        this.name = name;
    }

    public String getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public void setId(String id) {
        this.id = id;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void displaySubject() {
        System.out.print(String.format("%-10s  %s\n", id, name));

    }
}
