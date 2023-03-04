import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Stream;

public class GraphBuilder {
    @SuppressWarnings("unused")
    private static final long serialVersionUID = 27548990124L;

    public static DirectedGraph buildDirectedGraph(String filename) {
        DirectedGraph dg = new DirectedGraph();
        buildGraph(dg, filename);
        return dg;
    }

    public static UndirectedGraph buildUndirectedGraph(String filename) {
        UndirectedGraph ug = new UndirectedGraph();
        buildGraph(ug, filename);
        return ug;
    }

    protected static void buildGraph(Graph graph, String filename) {
        try (Stream<String> lines = Files.lines(Paths.get(filename))) {
            lines.map(line -> line.split(" "))
                .filter(edge -> edge.length >= 2)
                .forEach(edge -> graph.addEdge(edge[0], edge[1]));
        } catch (IOException e) {
            System.out.println("Error when trying to read " + filename + ": " + e);
        }
    }

//    public static void main(String[] args) {
//        DirectedGraph dg = buildDirectedGraph("student_graph_test.txt");
//        System.out.println(GraphUtils.nodesWithinDistance(dg, "0", 2));
//
//        DirectedGraph dg1 = buildDirectedGraph("test.txt");
//        System.out.println(GraphUtils.nodesWithinDistance(dg1, "10", 5));
//
//        List<String> values = new ArrayList<>();
//        values.add("0");
//        values.add("1");
//        values.add("2");
//        values.add("3");
//        values.add("0");
//
////        System.out.println(GraphUtils.isHamiltonianCycle(dg, values));
//
//
//        List<String> values2 = new ArrayList<>();
//        values2.add("6");
//        values2.add("7");
//        values2.add("8");
//        values2.add("3");
//        values2.add("4");
//        System.out.println(GraphUtils.isHamiltonianCycle(dg1, values2));
//    }
}
