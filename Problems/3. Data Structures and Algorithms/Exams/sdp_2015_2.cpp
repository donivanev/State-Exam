#include <iostream>
#include <vector>
using namespace std;

/*
    • Да се дефинира подходяща структура от данни, позволяваща представянето в паметта на програмата на ориентиран граф от типа
    G = <V, E>, където V е множеството на целите положителни числа, не по големи от 1000 (представено чрез int), а E = V × V.
    • За така дефинираната структура от данни да се дефинира функция (или статичен метод) [булев тип] isConnected ([подходящ тип] g)
    чиято стойност е истина точно за тези графи g, които са свързани. За един граф G = <V, Е> казваме, че е свързан, ако за всяка
    двойка u ∈ V, v ∈ V има път от u до v или от v до u. На примера са показани два графа, първият от които е свързан, а вторият – не.
*/

const int MAX_VERTICES = 1000;

struct GraphNode {
    int verticesNumber;
    bool adjMatrix[MAX_VERTICES][MAX_VERTICES];  // Adjacency matrix

    GraphNode(int vertices) : verticesNumber(vertices) {
        for (int i = 0; i < verticesNumber; ++i) {
            for (int j = 0; j < verticesNumber; ++j) {
                adjMatrix[i][j] = false; // Initialize the adjacency matrix with false (no edges)
            }
        }
    }

    void addEdge(int u, int v) {
        if (u < verticesNumber && v < verticesNumber) {
            adjMatrix[u][v] = true;
        }
    }

    bool isConnected() const;
};

void dfs(const GraphNode& g, vector<bool>& visited, int v) {
    visited[v] = true;

    for (int i = 0; i < g.verticesNumber; ++i) {
        if (g.adjMatrix[v][i] && !visited[i]) {
            dfs(g, visited, i);
        }
    }
}

bool GraphNode::isConnected() const {
    vector<bool> visited(verticesNumber, false);
    
    dfs(*this, visited, 0); // Start DFS from the first vertex (0)

    // Check if all vertices were visited
    for (bool v : visited) {
        if (!v) {
            return false;  // Not all vertices were visited
        }
    }
    return true;  // All vertices were visited
}

int main() {

    GraphNode g(4);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);  // Adding this edge makes the graph connected

    g.isConnected() ? cout << "The graph is connected." << endl : cout << "The graph is not connected." << endl;

    return 0;
}