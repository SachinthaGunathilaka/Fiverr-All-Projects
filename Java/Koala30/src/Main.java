public class Main {
    public static void main(String[] args) {
        Graph<Character> graph = new Graph<Character>();

        graph.addVertex('A');
        graph.addVertex('B');
        graph.addVertex('C');
        graph.addVertex('D');
        graph.addVertex('E');
        graph.addVertex('F');
        graph.addVertex('G');

        graph.addEdgeWeighted('A', 'B', 7);
        graph.addEdgeWeighted('A', 'D', 5);

        graph.addEdgeWeighted('B', 'D', 9);
        graph.addEdgeWeighted('B', 'C', 8);
        graph.addEdgeWeighted('B', 'E', 7);

        graph.addEdgeWeighted('C', 'E', 5);

        graph.addEdgeWeighted('D', 'E', 15);
        graph.addEdgeWeighted('D', 'F', 6);

        graph.addEdgeWeighted('E', 'F', 8);
        graph.addEdgeWeighted('E', 'G', 9);

        graph.addEdgeWeighted('F', 'G', 11);

//        graph.primsMST('D');

        graph.dijkstraShortestPath('A', 'G');


    }
}
