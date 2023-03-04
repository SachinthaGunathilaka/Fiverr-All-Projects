import java.util.ArrayList;
import java.util.Objects;

public class Articles {
    private ArrayList<Article> articles;

    public Articles(){
        articles = new ArrayList<Article>();
    }

    public ArrayList<Article> getArticles(){
        return articles;
    }

    public void addArticle(Article article){
        articles.add(article);
    }

    public Article searchArticle(String articleId){
        for (Article article:articles) {
            if(Objects.equals(article.getArticle_id(), articleId)){
                return article;
            }
        }

        return null;
    }

    public void displayArticles(){
        for (Article article:articles) {
            article.displayArticle();
        }
    }
}
