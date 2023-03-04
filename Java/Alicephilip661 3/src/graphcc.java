import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class graphcc {
    private int V;
    private String graph_name;
    List<List<Integer>> adj;

    // Constructor of this class
    public graphcc(int V, String graph_name) {
        this.V = V;
        this.graph_name = graph_name;
        this.adj = new ArrayList<List<Integer>>();

        for (int i = 0; i < V; i++) {
            List<Integer> item = new ArrayList<Integer>();
            this.adj.add(item);
        }
    }

    public void addEdge(int u, int v) {
        adj.get(u).add(v);
        adj.get(v).add(u);
    }


    void DFSRecursive(int v, boolean[] visited) {
        // Mark the current vertex as visited
        visited[v] = true;

        // Print the current vertex
        System.out.print(v + " ");

        // Recur for all the vertices adjacent to this vertex
        for (int x : adj.get(v)) {
            if (!visited[x])
                DFSRecursive(x, visited);
        }
    }

    void connectedComponentsDFS() {
        // Initialize an array to keep track of visited vertices
        boolean[] visited = new boolean[V];

        // Traverse all vertices and call DFSRecursive for unvisited vertices
        for (int v = 0; v < V; ++v) {
            if (!visited[v]) {
                System.out.print("\t\t");
                DFSRecursive(v, visited);

                // Print a new line after visiting all vertices in a connected component
                System.out.println();
            }
        }
    }

    void connectedComponentsBFS() {
        // Initialize an array to keep track of visited vertices
        boolean[] visited = new boolean[V];

        // Traverse all vertices and call BFS for unvisited vertices
        for (int v = 0; v < V; ++v) {
            if (!visited[v]) {
                Queue<Integer> q = new LinkedList<>();

                // Mark the current vertex as visited and enqueue it
                visited[v] = true;
                q.add(v);

                System.out.print("\t\t");
                // Traverse the queue and print all the vertices
                while (!q.isEmpty()) {
                    // Dequeue a vertex from the front of the queue
                    int vertex = q.poll();
                    System.out.print(vertex + " ");

                    // Add all unvisited vertices adjacent to the dequeued vertex to the queue
                    for (int neighbor : adj.get(vertex)) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.add(neighbor);
                        }
                    }
                }

                // Print a new line after visiting all vertices in a connected component
                System.out.println();
            }
        }


    }

    public static void main(String[] args) {
        try {
            graphcc graph = null;
            int state = 0;
            File myObj = new File(args[0]);
            Scanner myReader = new Scanner(myObj);

            // Read file and generate graph
            while (myReader.hasNextLine()) {
                String graph_name = "";
                int vertices = 0;
                String line = myReader.nextLine();

                if (line.startsWith("**")) {
                    Pattern pattern = Pattern.compile("\\*\\*(.*?)\\: \\|");
                    Matcher matcher = pattern.matcher(line);

                    if (matcher.find()) {
                        graph_name = matcher.group(1).trim();
                    }

                    pattern = Pattern.compile("\\|V\\|=(.*?)\\ ");
                    matcher = pattern.matcher(line);

                    if (matcher.find()) {
                        vertices = Integer.parseInt(matcher.group(1).trim());
                    }

                    graph = new graphcc(vertices, graph_name);
                    state = 1;
                    continue;
                }

                if (state == 1) {
                    state = 2;
                    continue;
                }

                if (line.startsWith("--")) {
                    System.out.println("\n** " + graph.graph_name + "'s connected components: ");
                    System.out.println("\tBreadth First Search:");
                    graph.connectedComponentsBFS();

                    System.out.println("\tDepth First Search:");
                    graph.connectedComponentsDFS();
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
