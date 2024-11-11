/*

Implement program Count all possible Paths 
between two Vertices.
Statement Count the total number of ways or paths 
that exist between two vertices in a directed graph. 
These paths don’t contain a cycle, the simple enough 
reason is that a cycle contains an infinite number of 
paths and hence they create a problem.

Input: Count paths between A and E
Output: Total paths between A and E are 4
Input: Count paths between A and C
Output: Total paths between A and C are 2

*/

#include <iostream>
#include <vector>
using namespace std;

class DirectedGraph {
    int V;  // Number of vertices
    vector<vector<int>> adjList;  // Adjacency list to store the graph

public:

    DirectedGraph(int V) {
        this->V = V;
        adjList.resize(V);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    void countPathsUtil(int u, int destination, int &pathCount) {
        if (u == destination) {
            pathCount++; 
            return;
        }

        for (int v : adjList[u]) {
            countPathsUtil(v, destination, pathCount);
        }
    }

    int countPaths(int source, int destination) {
        int pathCount = 0;
        countPathsUtil(source, destination, pathCount);
        return pathCount;
    }
};

int main() {
    int V = 5;  
    char arr[]={'A','B','C','D','E'};
    DirectedGraph graph(V);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 4);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 4);
    graph.addEdge(3, 2);

    int source = 0, destination = 4;
    cout << "Total paths from " << arr[source] << " to " << arr[destination] << " are: " 
         << graph.countPaths(source, destination) << endl;
    source = 0, destination = 2;
    cout << "Total paths from " << arr[source] << " to " << arr[destination] << " are: " 
         << graph.countPaths(source, destination) << endl;

    return 0;
}