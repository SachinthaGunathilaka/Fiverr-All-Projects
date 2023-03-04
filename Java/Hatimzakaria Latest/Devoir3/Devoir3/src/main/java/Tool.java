public class Tool extends Activity {
    private String version;
    private String repo;


    public Tool(String title, String description, String version, String repo) {
        super(title, description);
        this.version = version;
        this.repo = repo;
    }

    public String getVersion() {
        return version;
    }

    public String getRepo() {
        return repo;
    }

    @Override
    public String toString() {
        return "Tool{" +
                "id='" + id + '\'' +
                ", title='" + title + '\'' +
                ", description='" + description + '\'' +
                ", version='" + version + '\'' +
                ", repo='" + repo + '\'' +
                '}';
    }
}
