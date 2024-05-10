#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>
#include <stack>
#include <queue>
class Graph {
private:
    int numVertices; // Количество вершин
    std::vector<std::vector<int>> adjacencyList; // Список смежности

public:
    Graph(int numVertices); // Конструктор с указанием количества вершин

    void addEdge(int u, int v); // Метод для добавления ребра между вершинами u и v

    void printGraph(); // Метод для вывода графа

    std::vector<int> BFS(int startVertex); // Метод для выполнения поиска в ширину (BFS)

    std::vector<int> DFS(int startVertex); // Метод для выполнения поиска в глубину (DFS)
};

#endif
