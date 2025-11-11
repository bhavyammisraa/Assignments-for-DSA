#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v, bool directed = false) {
        adj[u][v] = 1;
        if (!directed) adj[v][u] = 1;
    }

    void displayMatrix() {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) cout << adj[i][j] << " ";
            cout << endl;
        }
    }

    void adjacentVertices(int v) {
        cout << "Adjacent vertices of " << v << ": ";
        for (int i = 0; i < V; i++) if (adj[v][i]) cout << i << " ";
        cout << endl;
    }

    int inDegree(int v) {
        int deg = 0;
        for (int i = 0; i < V; i++) if (adj[i][v]) deg++;
        return deg;
    }

    int outDegree(int v) {
        int deg = 0;
        for (int i = 0; i < V; i++) if (adj[v][i]) deg++;
        return deg;
    }

    int edgeCount(bool directed = false) {
        int count = 0;
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (adj[i][j]) count++;
        return directed ? count : count / 2;
    }
};

int main() {
    int V = 5;
    Graph g(V);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.displayMatrix();
    cout << "In-degree of 3: " << g.inDegree(3) << endl;
    cout << "Out-degree of 1: " << g.outDegree(1) << endl;
    g.adjacentVertices(1);
    cout << "Total edges: " << g.edgeCount() << endl;
}
