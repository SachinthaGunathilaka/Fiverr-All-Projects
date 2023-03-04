#include "MinPriorityQueue.h"

// A method to get index by vertex name
int getIndex(string *vertices, int V, string vertex) {
    for (int i = 0; i < V; ++i) {
        if (vertices[i] == vertex)
            return i;
    }
    return -1;
}

// Method to get the root starting end of a vertex
string getParent(string *vertices, int V, string vertex, string *parents) {
    int index = getIndex(vertices, V, vertex);
    while (parents[index] != vertex) {
        vertex = parents[index];
        index = getIndex(vertices, V, vertex);
    }

    return parents[index];
}


// Method to get join edges
void joinEdge(string *vertices, int V, string *parents, string v1, string v2) {
    string p1 = getParent(vertices, V, v1, parents);
    string p2 = getParent(vertices, V, v2, parents);

    parents[getIndex(vertices, V, p1)] = p2;
}

// Kruskal's minimum spanning tree algorithm
double kruskalMST(MinPriorityQueue *edge_queue, string *vertices, int V, Edge **result) {
    int result_index = 0;
    string parents[V];
    double cost = 0;
    int groups_count = V;
    for (int i = 0; i < V; i++)
        parents[i] = vertices[i];

    while (groups_count != 1) {
        Edge *min_edge = edge_queue->dequeue();
        if (getParent(vertices, V, min_edge->getStart(), parents) !=
            getParent(vertices, V, min_edge->getEnd(), parents)) {
            joinEdge(vertices, V, parents, min_edge->getStart(), min_edge->getEnd());

            result[result_index++] = min_edge;
            cost += min_edge->getWeight();
            groups_count--;
        }
    }

    return cost;
}


// Method to check whether the vertex is already visited
bool isVisited(string *visited, int visit_idx, string vertex) {
    for (int i = 0; i < visit_idx; ++i) {
        if (visited[i] == vertex) {
            return true;
        }
    }
    return false;
}

// Prim's algorithm
double primsMST(Edge **edges, int edge_count, string *vertices, int V, Edge **result) {
    int result_idx = 0;
    MinPriorityQueue prims_edge_queue(10);
    double cost = 0;

    string visited[V];
    int visit_idx = 0;

    visited[visit_idx++] = vertices[0];
    string current = vertices[0];

    while (visit_idx != V) {
        for (int i = 0; i < edge_count; ++i) {
            if ((edges[i]->getStart() == current) || (edges[i]->getEnd() == current)) {
                prims_edge_queue.enqueue(edges[i]);
            }
        }

        while (true) {
            Edge *min_edge = prims_edge_queue.dequeue();
            if (!isVisited(visited, visit_idx, min_edge->getStart())) {
                current = min_edge->getStart();
                visited[visit_idx++] = current;
                cost += min_edge->getWeight();
                result[result_idx++] = min_edge;

                break;
            } else if (!isVisited(visited, visit_idx, min_edge->getEnd())) {
                current = min_edge->getEnd();
                visited[visit_idx++] = current;
                cost += min_edge->getWeight();
                result[result_idx++] = min_edge;
                break;
            }
        }

    }

    return cost;


}

// main method
int main(int argc, char **argv) {

    // Check the validity of the arguments
    if (argc != 2) {
        cout << "Invalid arguments" << endl;
        return 0;
    }

    // Open file for reading
    ifstream graph_file(argv[1]);
    string line;

    int V;

    // Reading file
    graph_file >> V;
    string *vertices = new string[V];

    Edge **edges = new Edge *[V * V / 2];


    string vertex_name;
    for (int i = 0; i < V; ++i) {
        graph_file >> vertices[i];
    }


    double weight;
    int edge_count = 0;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            graph_file >> weight;
            if (j <= i)
                continue;
            if (weight == 0) {
                weight = INTMAX_MAX;
            }

            Edge *edge = new Edge(vertices[i], vertices[j], weight);
            edges[edge_count++] = edge;

        }
    }

    graph_file.close();


    // Kruskal's algorithm part
    MinPriorityQueue edge_queue(10);

    int count = 0;
    for (int i = 0; i < edge_count; ++i) {
        edge_queue.enqueue(edges[i]);
        count++;

    }

    Edge **result = new Edge *[V - 1];
    double cost = kruskalMST(&edge_queue, vertices, V, result);

    cout << "Kruskals" << endl;
    cout << cost << endl;
    for (int i = 0; i < V - 2; ++i) {
        for (int j = 0; j < V - 2 - i; ++j) {
            if ((result[j]->getStart() > result[j + 1]->getStart()) ||
                ((result[j]->getStart() == result[j + 1]->getStart()) &&
                 ((result[j]->getEnd() > result[j + 1]->getEnd())))) {
                Edge *temp = result[j];
                result[j] = result[j + 1];
                result[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < V - 1; ++i) {
        cout << *result[i];
    }

    for (int i = 0; i < 32; ++i) {
        cout << "-";
    }


    // Prim's algorithm part
    Edge **prims_result = new Edge *[V - 1];
    double prims_cost = primsMST(edges, edge_count, vertices, V, prims_result);

    cout << "\nPrims" << endl;
    cout << prims_cost << endl;
    for (int i = 0; i < V - 2; ++i) {
        for (int j = 0; j < V - 2 - i; ++j) {
            if ((prims_result[j]->getStart() > prims_result[j + 1]->getStart()) ||
                ((prims_result[j]->getStart() == prims_result[j + 1]->getStart()) &&
                 ((prims_result[j]->getEnd() > prims_result[j + 1]->getEnd())))) {
                Edge *temp = prims_result[j];
                prims_result[j] = prims_result[j + 1];
                prims_result[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < V - 1; ++i) {
        cout << *prims_result[i];
    }

    return 0;
}
