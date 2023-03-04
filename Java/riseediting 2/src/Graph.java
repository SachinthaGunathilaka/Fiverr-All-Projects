import java.util.HashMap;
import java.util.Map;

// Graph class
public class Graph {

    // attributes
    private Map<String, Integer> cities;
    private int[][] graph;
    private int current_size;
    public int max_size;

    // constructor
    public Graph() {
        this.current_size = 0;
        this.max_size = 100;
        this.cities = new HashMap<>();
        this.graph = new int[max_size][max_size];
        for (int i = 0; i < max_size; i++) {
            for (int j = 0; j < max_size; j++) {
                graph[i][j] = Integer.MAX_VALUE;
            }
        }
    }

    // get size method
    public int getSize() {
        return current_size;
    }

    // insert vertex method
    public int insertVertex(String city) {
        // check whether the vertex already exists
        if (cities.containsKey(city)) {
            return cities.get(city);
        }

        // insert vertex
        cities.put(city, current_size);
        return current_size++;
    }


    // delete vertex method
    public boolean deleteVertex(String city) {
        // check whether the vertex exists
        if (cities.containsKey(city)) {
            // remove vertex
            cities.remove(city);
            return true;
        }
        return false;
    }

    // delete edge method
    public void deleteEdge(String start, String end) {
        // get index of the start and end vertex
        int start_index = insertVertex(start);
        int end_index = insertVertex(end);

        // add weight to correct position of the graph array
        graph[start_index][end_index] = Integer.MAX_VALUE;
    }

    // insert edge method
    public void insertEdge(String start, String end, int weight) {
        // get index of the start and end vertex
        int start_index = insertVertex(start);
        int end_index = insertVertex(end);

        // add weight to correct position of the graph array
        graph[start_index][end_index] = weight;
    }

    // method to get weight of an edge
    public int getWeight(String start, String end) {

        // get index of the start and end vertex
        int start_index = insertVertex(start);
        int end_index = insertVertex(end);

        // return weight
        return graph[start_index][end_index];
    }


}