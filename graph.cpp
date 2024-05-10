#include "graph.h"
#include <iostream>
#include <queue>
#include <stack>

Graph::Graph(int numVertices) {
    this->numVertices = numVertices;
    adjacencyList.resize(numVertices);
}

void Graph::addEdge(int u, int v) {
    adjacencyList[u].push_back(v);
}

void Graph::printGraph() {
    std::cout << "Graph:\n";
    for (int i = 0; i < numVertices; ++i) {
        std::cout << i << ": ";
        for (int v : adjacencyList[i]) {
            std::cout << v << " ";
        }
       std::cout << "\n";
    }
}

std::vector<int> Graph::BFS(int startVertex) {
    std::vector<bool> visited(numVertices, false);
    std::vector<int> result;
    std::queue<int> q; 

    q.push(startVertex);
    visited[startVertex] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        result.push_back(current);

        for (int v : adjacencyList[current]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
            }
        }
    }

    return result;
}

std::vector<int> Graph::DFS(int startVertex) {
    std::vector<bool> visited(numVertices, false);
    std::vector<int> result;

    std::stack<int> s;
    s.push(startVertex);

    while (!s.empty()) {
        int current = s.top();
        s.pop();
        
        if (!visited[current]) {
            result.push_back(current);
            visited[current] = true;

            for (int v : adjacencyList[current]) {
                if (!visited[v]) {
                    s.push(v);
                }
            }
        }
    }

    return result;
}

