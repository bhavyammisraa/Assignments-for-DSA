#include <iostream>
#include <queue>
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

    void addEdge(int u, int v, bool directed = false) {
        adj[u][v] = 1;
        if (!directed) adj[v][u] = 1;
    }

    void BFS(int start) {
        bool visited[20] = {false};
        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int i = 0; i < V; i++) {
                if (adj[node][i] && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);

    cout << "BFS traversal starting from vertex 0: ";
    g.BFS(0);
}
