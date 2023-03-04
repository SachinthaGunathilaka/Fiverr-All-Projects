import java.util.ArrayList;
import java.util.Objects;

public class ActivityController extends Controller {
    public ArrayList<Article> getArticles(FormData[] query) {
        return articles;
    }

    public void createArticle(String title, String description, ArticleStatus status, String url) {

        Article article = new Article(title, description, status, url);
        articles.add(article);
    }

    public void displayArticles() {
        System.out.println("\nList of articles");
        System.out.println("--------------------");
        for (Article article : articles) {
            System.out.println(article.getTitle());
        }
    }

    public void displayArticle(String title) {
        for (Article article : articles) {
            if (Objects.equals(article.getTitle(), title)) {
                System.out.println(article);
                return;
            }
        }

        System.out.println("Article not found!");
    }


    public boolean updateArticle(String title, String description, ArticleStatus status, String url) {
        for (int i = 0; i < articles.size(); i++) {
            if (Objects.equals(articles.get(i).getTitle(), title)) {
                Article article = articles.get(i);
                Article new_article = new Article(title, description, status, url);

                new_article.setId(article.id);
                articles.set(i, new_article);
                return true;
            }
        }

        System.out.println("Article not found!");
        return false;
    }

    public boolean deleteArticle(String title) {
        for (int i = 0; i < articles.size(); i++) {
            if (Objects.equals(articles.get(i).getTitle(), title)) {
                articles.remove(i);
                return true;
            }
        }

        System.out.println("Article not found!");
        return false;
    }

    public ArrayList<Project> getProjects(FormData[] query) {
        return projects;
    }

    public void displayProjects() {
        System.out.println("\nList of projects");
        System.out.println("--------------------");
        for (Project project : projects) {
            System.out.println(project.getTitle());
        }
    }

    public void displayProject(String title) {
        for (Project project : projects) {
            if (Objects.equals(project.getTitle(), title)) {
                System.out.println(project);
                return;
            }
        }

        System.out.println("Project not found!");
    }

    public void createProject(String title, String description, String startDate, String endDate) {
        Project project = new Project(title, description, startDate, endDate);
        projects.add(project);
    }

    public boolean updateProject(String title, String description, String startDate, String endDate) {
        for (int i = 0; i < projects.size(); i++) {
            if (Objects.equals(projects.get(i).getTitle(), title)) {
                Project project = projects.get(i);
                Project new_project = new Project(title, description, startDate, endDate);

                new_project.setId(project.id);
                projects.set(i, new_project);
                return true;
            }
        }

        System.out.println("Project not found!");
        return false;
    }

    public boolean deleteProject(String title) {
        for (int i = 0; i < projects.size(); i++) {
            if (Objects.equals(projects.get(i).getTitle(), title)) {
                projects.remove(i);
                return true;
            }
        }

        System.out.println("Project not found!");
        return false;
    }

    public ArrayList<Tool> getTools() {
        return tools;
    }


    public void displayTools() {
        System.out.println("\nList of tools");
        System.out.println("--------------------");
        for (Tool tool : tools) {
            System.out.println(tool.getTitle());
        }
    }

    public void createTool(String title, String description, String version, String repo) {
        Tool tool = new Tool(title, description, version, repo);
        tools.add(tool);
    }

    public void displayTool(String title) {
        for (Tool tool : tools) {
            if (Objects.equals(tool.getTitle(), title)) {
                System.out.println(tool);
                return;
            }
        }

        System.out.println("Tool not found!");
    }

    public boolean updateTool(String title, String description, String version, String repo) {
        for (int i = 0; i < tools.size(); i++) {
            if (Objects.equals(tools.get(i).getTitle(), title)) {
                Tool tool = tools.get(i);
                Tool new_tool = new Tool(title, description, version, repo);

                new_tool.setId(tool.id);
                tools.set(i, new_tool);
                return true;
            }
        }

        System.out.println("Tool not found!");
        return false;
    }

    public boolean deleteTool(String title) {
        for (int i = 0; i < tools.size(); i++) {
            if (Objects.equals(tools.get(i).getTitle(), title)) {
                tools.remove(i);
                return true;
            }
        }

        System.out.println("Tool not found!");
        return false;
    }

    public boolean subscribe(Activity activity, User user) {
        return true;
    }

    public boolean unsubscribe(Activity activity, User user) {
        return true;
    }


}
