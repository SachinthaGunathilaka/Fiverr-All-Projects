#include <climits>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

// Function to find the shortest path
double shortestPath(const double *graph, int src, int num_of_vertex, int destination, vector<int> *path) {
    // To hold the shortest distances
    double shortest_distances[num_of_vertex];

    // To check whether the visited vertices
    bool visited[num_of_vertex];

    // Initialize all the vertex to not visited and set distance as infinity
    for (int i = 0; i < num_of_vertex; i++) {
        shortest_distances[i] = INT_MAX;
        visited[i] = false;
    }

    shortest_distances[src] = 0;

    // Find the shortest path for all vertices
    for (int count = 0; count < num_of_vertex - 1; count++) {

        // get vertex with minimum distance from un visited vertices)
        double minimum_distance = INT_MAX;
        int u;
        for (int v = 0; v < num_of_vertex; v++)
            if (!visited[v] && shortest_distances[v] <= minimum_distance)
                minimum_distance = shortest_distances[v], u = v;

        // terminate the function after finding the shortest path for the given vertex.
        if (u == destination) {
            return shortest_distances[destination];
        }

        // Set the vertex as visited
        visited[u] = true;

        // Update shortest distances
        for (int v = 0; v < num_of_vertex; v++)
            // If the new distance is smaller than the previous distance
            if (!visited[v] && shortest_distances[u] != INT_MAX && graph[u * num_of_vertex + v] != 0
                && shortest_distances[u] + graph[u * num_of_vertex + v] < shortest_distances[v]) {
                shortest_distances[v] = shortest_distances[u] + graph[u * num_of_vertex + v];

                // Update the path
                if (destination == v && path->at(path->size() - 1) != u) {
                    path->push_back(u);
                }
            }
    }
    return shortest_distances[destination];

}

int main(int argc, char ** argv) {

    // If the given arguments are not valid
    if(argc != 4){
        cout << "Invalid arguments" << endl;
        return 0;
    }

    // Open given file
    ifstream infile(argv[1]);
    string line;
    int vertex_index = 0;
    vector<int> path;

    // If the given file is not found
    if(!getline(infile, line)){
        cout << "File Not Found" << endl;
        return 0;
    }

    // Read number of vertices
    istringstream iss(line);
    int num_of_vertex;
    iss >> num_of_vertex;


    // create array to edge weights
    double * graph = new double[num_of_vertex * num_of_vertex];

    // Map to hold the vertices name and the index
    map<string, int> vertex_map;

    // read the file line by line
    while (getline(infile, line)) {
        stringstream ss(line);
        string start, end;
        double weight;
        ss >> start; // get starting vertex

        // Add vertex to vertices map if it is not exits.
        if (vertex_map.find(start) == vertex_map.end()){
            vertex_map.insert(pair<string, int>(start, vertex_index++));
        }

        // Add each edge weight to graph array
        while (ss >> end && ss >> weight) {
            if (vertex_map.find(end) == vertex_map.end()){
                vertex_map.insert(pair<string, int>(end, vertex_index++));
            }

            int index = num_of_vertex * vertex_map.find(start)->second + vertex_map.find(end)->second;
            graph[index] = weight;

        }

    }



    // Initially add source to path vector
    int source = vertex_map.find(argv[2])->second;
    path.push_back(source);
    int destination = vertex_map.find(argv[3])->second;

    // get the shortest distance from source to given destination
    double shortest_distance = shortestPath(graph, source, num_of_vertex, destination, &path);
    path.push_back(destination);

    // Display the shortest distance
    cout << shortest_distance << endl;

    // Display the shortest path
    for (int i : path) {
        for (auto &it: vertex_map) {
            if (it.second == i) {
                cout << it.first << " ";
                break;
            }
        }
    }

    return 0;
}
