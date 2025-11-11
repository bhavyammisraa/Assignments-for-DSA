#include <iostream>
#include <climits>
using namespace std;

class Graph {
    int V;
    int adj[20][20];

public:
    Graph(int V) {
        this->V = V;
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                adj[i][j] = 0;
    }

    void addEdge(int u, int v, int w) {
        adj[u][v] = w;
        adj[v][u] = w;
    }

    int minDistance(int dist[], bool visited[]) {
        int min = INT_MAX, min_index;
        for (int v = 0; v < V; v++)
            if (!visited[v] && dist[v] <= min)
                min = dist[v], min_index = v;
        return min_index;
    }

    void dijkstra(int src) {
        int dist[20];
        bool visited[20];
        for (int i = 0; i < V; i++)
            dist[i] = INT_MAX, visited[i] = false;
        dist[src] = 0;
        for (int count = 0; count < V - 1; count++) {
            int u = minDistance(dist, visited);
            visited[u] = true;
            for (int v = 0; v < V; v++)
                if (!visited[v] && adj[u][v] && dist[u] != INT_MAX && dist[u] + adj[u][v] < dist[v])
                    dist[v] = dist[u] + adj[u][v];
        }
        cout << "Vertex\tDistance from Source " << src << endl;
        for (int i = 0; i < V; i++)
            cout << i << "\t" << dist[i] << endl;
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 8);
    g.addEdge(2, 4, 10);
    g.addEdge(3, 4, 2);
    g.addEdge(3, 5, 6);
    g.addEdge(4, 5, 3);
    g.dijkstra(0);
}
