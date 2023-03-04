import java.util.List;

public class Main {
    public static void main(String[] args) {

            List<Sentence> list = Analyzer.readFile(null);
        System.out.println(list.isEmpty());
        System.out.println(list.size());

            list = Analyzer.readFile("reviesw.txt");
        System.out.println(list.isEmpty());
        System.out.println(list.size());


            list = Analyzer.readFile("tiny");
        System.out.println(list.isEmpty());
        System.out.println(list.size());
    }
}
