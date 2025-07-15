#include <iostream>
#include <list>
#include <unordered_map>
using std::cout; using std::endl; using std::list; using std::unordered_map;

template <typename T>
class Graph {
    public:
        Graph();
        Graph(const Graph<T>&);
        Graph<T>& operator=(const Graph<T>&);
        ~Graph();

        bool empty() const { return adjacency.empty(); }
        void add_vertex(const T& vertex);
        void add_edge(const T& from, const T& to);
        bool has_vertex(const T& vertex) const;
        bool has_edge(const T& from, const T& to) const;
        void print() const;
        void clear();

    private:
        unordered_map<T, list<T>> adjacency;
        void copy(const Graph<T>&);
};

// Constructor
template <typename T>
Graph<T>::Graph() {
    cout << "Graph created." << endl;
}

// Copy constructor
template <typename T>
Graph<T>::Graph(const Graph<T>& other) {
    copy(other);
}

// Assignment operator
template <typename T>
Graph<T>& Graph<T>::operator=(const Graph<T>& other) {
    if (this != &other) {
        clear();
        copy(other);
    }

    return *this;
}

// Destructor
template <typename T>
Graph<T>::~Graph() {
    clear();
}

// Add a vertex
template <typename T>
void Graph<T>::add_vertex(const T& vertex) {
    if (!has_vertex(vertex)) {
        adjacency[vertex] = list<T>();
    }
}

// Add a directed edge from one vertex to another
template <typename T>
void Graph<T>::add_edge(const T& from, const T& to) {
    add_vertex(from);
    add_vertex(to);
    adjacency[from].push_back(to);
    // adjacency[to].push_back(from); // ← for undirected graph
}

// Check if vertex exists
template <typename T>
bool Graph<T>::has_vertex(const T& vertex) const {
    return adjacency.find(vertex) != adjacency.end();
}

// Check if edge exists
template <typename T>
bool Graph<T>::has_edge(const T& from, const T& to) const {
    auto it = adjacency.find(from);

    if (it != adjacency.end()) {
        for (const T& neighbor : it->second) {
            if (neighbor == to) return true;
        }
    }

    return false;
}

// Print adjacency list
template <typename T>
void Graph<T>::print() const {
    if (empty()) {
        cout << "Graph is empty!" << endl;
        return;
    }

    for (const auto& pair : adjacency) {
        cout << pair.first << " -> ";

        for (const auto& neighbor : pair.second) {
            cout << neighbor << " ";
        }
        
        cout << endl;
    }
}

// Clear the graph
template <typename T>
void Graph<T>::clear() {
    adjacency.clear();
}

// Copy helper
template <typename T>
void Graph<T>::copy(const Graph<T>& other) {
    adjacency = other.adjacency;
}

int main() {
    Graph<int> g;

    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(2, 4);
    g.add_vertex(5);

    g.print();

    if (g.has_edge(1, 3)) {
        cout << "Edge 1 -> 3 exists." << endl;
    }

    Graph<int> g2 = g;
    cout << "Copied graph:" << endl;
    g2.print();

    g2.clear();
    cout << "After clearing g2:" << endl;
    g2.print();

    return 0;
}