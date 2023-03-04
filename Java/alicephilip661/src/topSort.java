import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class topSort {
    private final int vertices;
    private ArrayList<ArrayList<Integer>> graph;
    private String name;

    /*
        Constructor
    */
    topSort(int vertices, String name) {
        this.vertices = vertices;
        this.name = name;

        // Graph is represented by an adjacency list
        graph = new ArrayList<>();
        for (int i = 0; i < vertices; ++i) {
            graph.add(new ArrayList<>());
        }
    }

    /*
        Method to add an edge to the graph
    */
    void addEdge(int vertex1, int vertex2) {
        graph.get(vertex1).add(vertex2);
    }

    /*
        Function to display TopologicalOrder of the given graph
    */
    void displayTopologicalOrder(ArrayList<Integer> values){
        System.out.print(name + ": ");
        for (int i = 0; i < values.size(); i++) {
            if(i == values.size()-1){
                System.out.print(values.get(i));
            }
            else{
                System.out.print(values.get(i) + " ");
            }
        }
    }

    /*
        Function to determine the topological sort order of the graph
    */
    public void topologicalSort() {
        // Initialize the data structures
        ArrayList<Integer> result = new ArrayList<>();
        int[] incoming_edges = new int[vertices];
        Queue<Integer> vertex_with_no_incoming_edges = new LinkedList<>();

        // Calculate number of incoming edges for each vertices
        for (int i = 0; i < vertices; i++) {
            ArrayList<Integer> temp = graph.get(i);
            for (int node : temp){
                incoming_edges[node]++;
            }
        }

        // Check for vertices with no incoming edges
        for (int node = 0; node < vertices; node++) {
            if (incoming_edges[node] == 0)
                vertex_with_no_incoming_edges.add(node);
        }

        // Iterate through until find the result
        int visited_nodes = 0;
        while (!vertex_with_no_incoming_edges.isEmpty()) {

            // Select vertex with no incoming edges
            int node = vertex_with_no_incoming_edges.poll();
            result.add(node);
            ArrayList<Integer> temp = graph.get(node);

            // Remove all the edges starting from that vertex from the graph
            for (int u : temp) {
                incoming_edges[u]--;

                if(incoming_edges[u] == 0){
                    vertex_with_no_incoming_edges.add(u);
                }
            }
            visited_nodes++;
        }

        // If the graph is a cyclic graph
        if (visited_nodes != vertices) {
            // Display topological order of the graph
            displayTopologicalOrder(result);

            if(result.size() == 0){
                System.out.println("No in-degree 0 vertex; not an acyclic graph.");
            }
            else{
                System.out.println(" -> no more in-degree 0 vertex; not an acyclic graph.");
            }
        } else {
            // Display topological order of the graph
            displayTopologicalOrder(result);
            System.out.println();
        }
    }

    // Driver code
    public static void main(String[] args) {
        try {
            int state = 0;
            File myObj = new File(args[0]);
            topSort graph = null;
            Scanner myReader = new Scanner(myObj);

            // Read file and generate graph
            while (myReader.hasNextLine()) {
                String line = myReader.nextLine();

                if (line.startsWith("**")) {
                    Pattern pattern = Pattern.compile("\\{(.*?)\\}");
                    Matcher matcher = pattern.matcher(line);

                    if (matcher.find()) {
                        int vertices = matcher.group(1).trim().split(" ").length;
                        String name = line.substring(3, line.indexOf(':'));
                        // Generate graph
                        graph = new topSort(vertices, name);
                    }

                    state = 1;
                    continue;
                }

                if (state == 1) {
                    state = 2;
                    continue;
                }

                if (line.startsWith("--")) {

                    // Determine the topological sort
                    graph.topologicalSort();
                    state = 0;
                    continue;
                }

                if (state == 2) {
                    Pattern pattern = Pattern.compile("\\((.*?)\\)");
                    Matcher matcher = pattern.matcher(line);

                    if (matcher.find()) {
                        String[] edges_str = matcher.group(1).trim().split(",");
                        graph.addEdge(Integer.parseInt(edges_str[0].trim()), Integer.parseInt(edges_str[1].trim()));
                    }
                }


            }
            myReader.close();
        } catch (FileNotFoundException e) {
            System.out.println(Arrays.toString(e.getStackTrace()));
            System.out.println("An error occurred.");
        }
    }
}