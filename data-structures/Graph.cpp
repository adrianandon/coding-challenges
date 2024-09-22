#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>

template <typename T>
class Graph {
public:
    // Add an edge from vertex u to vertex v
    void addEdge(T u, T v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph
    }

    // Print the graph
    void printGraph() {
        for (const auto& pair : adjList) {
            std::cout << pair.first << ": ";
            for (const T& v : pair.second) {
                std::cout << v << " ";
            }
            std::cout << std::endl;
        }
    }

    void BFS(T start) {
        std::unordered_set<T> visited;
        std::queue<T> q;

        visited.insert(start);
        q.push(start);

        while (!q.empty()) {
            T v = q.front();
            q.pop();
            std::cout << v << " ";

            for (const T& neighbor : adjList[v]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
    }

    void DFS(T start) {
        std::unordered_set<T> visited;
        DFSUtil(start, visited);
    }

private:
    std::unordered_map<T, std::vector<T>> adjList;

    void DFSUtil(T v, std::unordered_set<T>& visited) {
        visited.insert(v);
        std::cout << v << " ";

        for (const T& neighbor : adjList[v]) {
            if (visited.find(neighbor) == visited.end()) {
                DFSUtil(neighbor, visited);
            }
        }
    }
};;

int main() {
    
    Graph<int> g;

    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);

    g.printGraph();

    return 0;
}
