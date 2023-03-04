public class Article {
    private String article_id;
    private String articleName;
    private Account owner;
    private String article;

    public Article(String article_id, String articleName, Account owner, String article) {
        this.article_id = article_id;
        this.articleName = articleName;
        this.owner = owner;
        this.article = article;
    }

    public String getArticle_id() {
        return article_id;
    }

    public String getArticleName() {
        return articleName;
    }

    public Account getOwner() {
        return owner;
    }

    public String getArticle() {
        return article;
    }

    public void setArticle_id(String article_id) {
        this.article_id = article_id;
    }

    public void setArticleName(String articleName) {
        this.articleName = articleName;
    }

    public void setOwner(Account owner) {
        this.owner = owner;
    }

    public void setArticle(String article) {
        this.article = article;
    }

    public void displayArticle(){
        System.out.println(articleName);
        System.out.println("--------------------------------");
        System.out.println();
    }
}
