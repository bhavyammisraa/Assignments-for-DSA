#include <iostream>
#include <algorithm>
using namespace std;

class Edge {
public:
    int src, dest, weight;
};

class Graph {
    int V, E;
    Edge edges[100];

public:
    Graph(int V, int E) {
        this->V = V;
        this->E = E;
    }

    void addEdge(int index, int src, int dest, int weight) {
        edges[index].src = src;
        edges[index].dest = dest;
        edges[index].weight = weight;
    }

    int findParent(int parent[], int i) {
        if (parent[i] == i) return i;
        return findParent(parent, parent[i]);
    }

    void unionSets(int parent[], int rank[], int x, int y) {
        int xroot = findParent(parent, x);
        int yroot = findParent(parent, y);
        if (rank[xroot] < rank[yroot])
            parent[xroot] = yroot;
        else if (rank[xroot] > rank[yroot])
            parent[yroot] = xroot;
        else {
            parent[yroot] = xroot;
            rank[xroot]++;
        }
    }

    void KruskalMST() {
        Edge result[100];
        int e = 0, i = 0;
        sort(edges, edges + E, [](Edge a, Edge b) { return a.weight < b.weight; });
        int parent[100], rank[100];
        for (int v = 0; v < V; v++) {
            parent[v] = v;
            rank[v] = 0;
        }
        while (e < V - 1 && i < E) {
            Edge next_edge = edges[i++];
            int x = findParent(parent, next_edge.src);
            int y = findParent(parent, next_edge.dest);
            if (x != y) {
                result[e++] = next_edge;
                unionSets(parent, rank, x, y);
            }
        }
        cout << "Edges in MST:\n";
        int minCost = 0;
        for (i = 0; i < e; i++) {
            cout << result[i].src << " - " << result[i].dest << " : " << result[i].weight << endl;
            minCost += result[i].weight;
        }
        cout << "Minimum Cost: " << minCost << endl;
    }
};

int main() {
    int V = 4, E = 5;
    Graph g(V, E);
    g.addEdge(0, 0, 1, 10);
    g.addEdge(1, 0, 2, 6);
    g.addEdge(2, 0, 3, 5);
    g.addEdge(3, 1, 3, 15);
    g.addEdge(4, 2, 3, 4);
    g.KruskalMST();
}
