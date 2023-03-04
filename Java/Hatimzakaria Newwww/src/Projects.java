import java.util.ArrayList;
import java.util.Objects;

public class Projects {
    private ArrayList<Project> projects;

    public Projects(){
        projects = new ArrayList<Project>();
    }

    public ArrayList<Project> getProjects() {
        return projects;
    }

    public void addProject(Project project){
        projects.add(project);
    }

    public Project searchProject(String projectId){
        for (Project project:projects) {
            if(Objects.equals(project.getProjectId(), projectId)){
                return project;
            }
        }

        return null;
    }

    public void displayProjects(){
        for (Project project:projects) {
            project.displayProject();
        }
    }
}
