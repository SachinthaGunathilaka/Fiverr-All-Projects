import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {
    private static class Graph {
        private LinkedList[] graph;
        private int current_size;
        private int max_size;

        public Graph() {
            this.current_size = 0;
            this.max_size = 10;
            this.graph = new LinkedList[max_size];
            for (int i = 0; i < max_size; i++) {
                graph[i] = new LinkedList<Integer>();
            }
        }

        public Graph(int max_size) {
            this.max_size = max_size;
            this.current_size = 0;
            this.graph = new LinkedList[max_size];
            for (int i = 0; i < max_size; i++) {
                graph[i] = new LinkedList<Integer>();
            }
        }

        public boolean isEmpty() {
            return current_size == 0;
        }

        public void createGraph(String filename) throws FileNotFoundException {

            FileInputStream fis = new FileInputStream(filename);
            Scanner scanner = new Scanner(fis);
            if(scanner.hasNextLine()){
                scanner.nextLine();
            }
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                String[] data = line.split(" ");
                int start_vertex = Integer.parseInt(data[0]);
                for (int i = 1; i < data.length; i++) {
                    graph[start_vertex - 1].add(Integer.parseInt(data[i]));
                }
                current_size++;
            }
            scanner.close();

        }

        public void isConnected() {
            if(isEmpty()){
                System.out.println("graph is empty");
                return;
            }
            boolean[] visited = new boolean[current_size];
            DFS(0, graph, visited);

            for (boolean b : visited) {
                if (!b) {
                    System.out.println("not connected");
                    return;
                }
            }
            System.out.println("connected");


        }

        public void DFS(int start, LinkedList<Integer>[] adj_list, boolean[] visited) {
            visited[start] = true;

            for (int i = 0; i < adj_list[start].size(); i++) {
                int neighbour = adj_list[start].get(i) - 1;
                if (!visited[neighbour]) {
                    DFS(neighbour, adj_list, visited);
                }
            }
        }
    }


    public static void main(String[] args) {

        try {
            Scanner scanner = new Scanner(System.in);
            System.out.print("Enter file name : ");
            String filename = scanner.nextLine();
            Graph graph = new Graph();
            graph.createGraph(filename);
            graph.isConnected();
        } catch (FileNotFoundException e) {
            System.out.println("File Not Found");
        }
    }
}
