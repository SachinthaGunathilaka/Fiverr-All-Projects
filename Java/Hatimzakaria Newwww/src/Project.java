public class Project {
    private String projectId;
    private String projectName;
    private String description;
    private String owner;
    private String category;


    public Project(String projectId, String projectName, String description, String owner, String category) {
        this.projectId = projectId;
        this.projectName = projectName;
        this.description = description;
        this.owner = owner;
        this.category = category;
    }

    public String getProjectId() {
        return projectId;
    }

    public String getProjectName() {
        return projectName;
    }

    public String getDescription() {
        return description;
    }

    public String getOwner() {
        return owner;
    }

    public String getCategory() {
        return category;
    }

    public void setProjectId(String projectId) {
        this.projectId = projectId;
    }

    public void setProjectName(String projectName) {
        this.projectName = projectName;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public void setOwner(String owner) {
        this.owner = owner;
    }

    public void setCategory(String category) {
        this.category = category;
    }

    public void displayProject(){
        System.out.println(projectName);
        System.out.println("---------------------------");
        System.out.println(description);
    }


}
