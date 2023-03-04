import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class Node implements Comparator<Node> {

    // Member variables of this class
    public int node;
    public double cost;

    // Constructors of this class

    // Constructor 1
    public Node() {
    }

    // Constructor 2
    public Node(int node, double cost) {

        // This keyword refers to current instance itself
        this.node = node;
        this.cost = cost;
    }

    // Method 1
    @Override
    public int compare(Node node1, Node node2) {

        if (node1.cost < node2.cost)
            return -1;

        if (node1.cost > node2.cost)
            return 1;

        return 0;
    }
}

public class dijkstra {
    private Node dist[]; // hold the distances between src and the vertices
    private Set<Integer> settled; // hold the already settled vertices
    private PriorityQueue<Node> pq;

    // Number of vertices
    private int V;
    private String graph_name;
    List<List<Node>> adj;

    // Constructor of this class
    public dijkstra(int V, String graph_name) {
        this.V = V;
        this.graph_name = graph_name;
        this.adj = new ArrayList<List<Node>>();

        this.dist = new Node[V];
        // Initialize list for every node
        for (int i = 0; i < V; i++) {
            this.dist[i] = new Node(-1, Integer.MAX_VALUE);
            List<Node> item = new ArrayList<Node>();
            this.adj.add(item);
        }

        // Allocate space
        settled = new HashSet<Integer>();
        pq = new PriorityQueue<Node>(V, new Node());
    }

    public void addEdge(int u, int v, double distance) {
        Node newNode = new Node(v, distance);
        adj.get(u).add(newNode);
    }

    // Dijkstra's Algorithm
    public boolean solve() {
        int src = 0;

        // Add source node to the priority queue
        pq.add(new Node(src, 0));

        // Set distance to the source as 0
        dist[0].cost = 0;

        // Loop runs until the size of the settled array is not equal to V
        while (settled.size() != V) {
            if (this.settled.contains(this.V - 1)) {
                return true;
            }
            // Terminate if the priority array is empty
            if (pq.isEmpty()) {
                return false;
            }


            // Removing the minimum distance node from the priority queue
            int u = pq.remove().node;

            // If the node u is settled skip the execution
            if (settled.contains(u))
                continue;

            // Add node u to settled array
            settled.add(u);

            // Execute processNeighbours method(Argument as u)
            processNeighbours(u);
        }

        return true;
    }

    void displayResult(boolean status) {
        System.out.println("\n" + graph_name + "'s shortest path from 0 to " + (this.V-1) + ":");
        if (status) {
            Stack<Node> result = new Stack<Node>();
            int temp_node = V-1;
            while (true){
                if(temp_node == 0)
                    break;
                Node newNode = new Node(temp_node, dist[temp_node].cost);
                result.push(newNode);
                temp_node = dist[temp_node].node;
            }

            int start = 0;
            double cur_weight = 0;
            while (!result.empty()){
                Node temp = result.pop();

                System.out.printf("\t( %d, %d, %.3f) --> %.3f\n", start, temp.node, temp.cost-cur_weight, temp.cost);
                start = temp.node;
                cur_weight = temp.cost;

            }
        } else {
            System.out.println("*** There is no path.");
        }
    }

    // To process all the neighbours of the passed node
    private void processNeighbours(int u) {

        double edgeDistance = -1;
        double newDistance = -1;

        // Loop through each adjacency node
        for (int i = 0; i < adj.get(u).size(); i++) {
            Node v = adj.get(u).get(i);

            // If current node hasn't already been processed
            if (!settled.contains(v.node)) {
                // get distance between u and v
                edgeDistance = v.cost;
                // calculate distance between src and v for now
                newDistance = dist[u].cost + edgeDistance;

                // If new distance is cheaper
                if (newDistance < dist[v.node].cost){
                    dist[v.node].cost = newDistance; // set new distance to dist array
                    dist[v.node].node = u; // set new distance to dist array
                }

                // Add the current node to the priority queue with the distance
                pq.add(new Node(v.node, dist[v.node].cost));
            }
        }
    }

    public static void main(String[] args) {
        try {
            dijkstra dijkstra_graph = null;
            int state = 0;
            File myObj = new File(args[0]);
            Scanner myReader = new Scanner(myObj);

            // Read file and generate graph
            while (myReader.hasNextLine()) {
                String graph_name = "";
                int vertices = 0;
                String line = myReader.nextLine();

                if (line.startsWith("**")) {
                    Pattern pattern = Pattern.compile("\\*\\*(.*?)\\:");
                    Matcher matcher = pattern.matcher(line);

                    if (matcher.find()) {
                        graph_name = matcher.group(1).trim();
                    }

                    pattern = Pattern.compile("\\|V\\|=(.*?)\\,");
                    matcher = pattern.matcher(line);

                    if (matcher.find()) {
                        vertices = Integer.parseInt(matcher.group(1).trim());
                    }

                    dijkstra_graph = new dijkstra(vertices, graph_name);
                    state = 1;
                    continue;
                }

                if (state == 1) {
                    state = 2;
                    continue;
                }

                if (line.startsWith("--")) {

                    boolean status = dijkstra_graph.solve();
                    dijkstra_graph.displayResult(status);
                    state = 0;
                    continue;
                }

                if (state == 2) {
                    Pattern pattern = Pattern.compile("\\((.*?)\\)");
                    Matcher matcher = pattern.matcher(line);

                    if (matcher.find()) {
                        String[] edges_str = matcher.group(1).trim().split(",");
                        dijkstra_graph.addEdge(Integer.parseInt(edges_str[0].trim()), Integer.parseInt(edges_str[1].trim()), Double.parseDouble(edges_str[2].trim()));
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
