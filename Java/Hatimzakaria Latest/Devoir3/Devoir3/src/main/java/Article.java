public class Article extends Activity {
    private ArticleStatus status;
    private String url;

    public Article(String title, String description, ArticleStatus status, String url) {
        super(title, description);
        this.status = status;
        this.url = url;
    }

    public ArticleStatus getStatus() {
        return status;
    }

    public String getUrl() {
        return url;
    }

    @Override
    public String toString() {
        return "Article{" +
                "id='" + id + '\'' +
                ", title='" + title + '\'' +
                ", description='" + description + '\'' +
                ", status=" + status +
                ", url='" + url + '\'' +
                '}';
    }
}
