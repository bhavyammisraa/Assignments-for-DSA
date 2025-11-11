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

    int minKey(int key[], bool mstSet[]) {
        int min = INT_MAX, min_index;
        for (int v = 0; v < V; v++)
            if (!mstSet[v] && key[v] < min)
                min = key[v], min_index = v;
        return min_index;
    }

    void primMST() {
        int parent[20];
        int key[20];
        bool mstSet[20];
        for (int i = 0; i < V; i++)
            key[i] = INT_MAX, mstSet[i] = false;
        key[0] = 0;
        parent[0] = -1;
        for (int count = 0; count < V - 1; count++) {
            int u = minKey(key, mstSet);
            mstSet[u] = true;
            for (int v = 0; v < V; v++)
                if (adj[u][v] && !mstSet[v] && adj[u][v] < key[v])
                    parent[v] = u, key[v] = adj[u][v];
        }
        cout << "Edges in MST:\n";
        int minCost = 0;
        for (int i = 1; i < V; i++) {
            cout << parent[i] << " - " << i << " : " << adj[i][parent[i]] << endl;
            minCost += adj[i][parent[i]];
        }
        cout << "Minimum Cost: " << minCost << endl;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);
    g.primMST();
}
