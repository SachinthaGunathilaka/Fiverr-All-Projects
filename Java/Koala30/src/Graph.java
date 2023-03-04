import java.util.*;

public class Graph<E> {

    public static class Edge<E> {

        private final int weight;
        private final E dest;


        public Edge(E dest) {
            this.dest = dest;
            weight = 0;
        }

        public Edge(E dest, int weight) {
            this.dest = dest;
            this.weight = weight;
        }

        public int getWeight() {
            return weight;
        }

        public E getDest() {
            return dest;
        }

    }

    private Map<E, List<Edge<E>>> map;

    public Graph() {
        map = new HashMap<>();
    }

    public void addVertex(E vertex) {
        map.putIfAbsent(vertex, new ArrayList<>());
    }

    public Set<E> getVertecies() {
        return map.keySet();
    }

    public void addEdgeWeighted(E source, E dest, int weight) {

        map.get(source).add(new Edge<E>(dest, weight));
        map.get(dest).add(new Edge<>(source, weight));

    }

    public List<Edge<E>> getEdges(E data) {
        return map.get(data);
    }

    public void reprioritize(Queue<E> pq, E entry) {
        pq.remove(entry);
        pq.add(entry);
    }

    public void primsMST(E source) {

        Map<E, E> parents = new HashMap<E, E>();
        Map<E, Integer> dists = new HashMap<>();
        Queue<E> pq = new PriorityQueue<E>(
                Comparator.comparing(dists::get)
        );

        /* Your solution here! */
        for (E key : map.keySet()) {
            dists.put(key, Integer.MAX_VALUE);
            parents.put(key, null);
        }

        dists.put(source, 0);

        for (E key : map.keySet()) {
            pq.offer(key);
        }

        while (!pq.isEmpty()) {
            E u = pq.poll();

            for (Edge<E> edge : map.get(u)) {
                E v = edge.getDest();

                if (pq.contains(v) && edge.weight < dists.get(v)) {
                    parents.put(v, u);
                    dists.put(v, edge.weight);
                    reprioritize(pq, v);
                }

            }

        }


        System.out.println("Prims Edges (Source=" + source + "):");
        for (Map.Entry<E, E> entry : parents.entrySet()) {
            System.out.printf("%s, %s\n", entry.getKey(), entry.getValue());
        }
    }

    public void dijkstraShortestPath(E source, E dest) {

        Map<E, E> parents = new HashMap<>();
        Map<E, Integer> dists = new HashMap<>();
        Queue<E> pq = new PriorityQueue<>(
                Comparator.comparing(dists::get)
        );

        /* Your solution here! */


        for (E key : map.keySet()) {
            dists.put(key, Integer.MAX_VALUE);
            parents.put(key, null);

        }
        dists.put(source, 0);


        for (E key : map.keySet()) {
            pq.offer(key);
        }


        while (!pq.isEmpty()) {
            E u = pq.poll();
            for (Edge<E> edge : map.get(u)) {
                E v = edge.getDest();

                int path_weight = dists.get(u) + edge.weight;
                if (pq.contains(v) && (path_weight < dists.get(v))) {
                    parents.put(v, u);
                    dists.put(v, path_weight);
                    reprioritize(pq, v);

                }

            }

        }


        printSP(source, dest, parents, dists);

    }

    private void printSP(E s, E d, Map<E, E> parents, Map<E, Integer> keys) {

        System.out.println("Dijkstras Edges (Source=" + s + ", Dest=" + d + "):");
        Stack<E> Q = new Stack<E>();
        E current = d;

        while (!Q.contains(s)) {
            Q.push(current);
            current = parents.get(current);
        }

        System.out.print("[");

        while (Q.size() != 1) {
            System.out.print(Q.pop() + ", ");
        }
        System.out.print(Q.pop() + "]: ");

        System.out.println(keys.get(d));

    }

}
