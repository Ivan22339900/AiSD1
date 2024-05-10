#include <iostream>
#include "graph.h"

int main() {
    // Создаем объект класса Graph
    Graph graph(5); // Создаем граф с 5 вершинами

    // Добавляем рёбра
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    // Выводим граф
    std::cout << "Graph:" << std::endl;
    graph.printGraph();
    std::cout << std::endl;

    // Выполняем поиск в ширину (BFS)
    std::cout << "BFS traversal starting from vertex 0:" << std::endl;
    std::vector<int> bfsResult = graph.BFS(0);
    for (int vertex : bfsResult) {
        std::cout << vertex << " ";
    }
    std::cout << std::endl << std::endl;

    // Выполняем поиск в глубину (DFS)
    std::cout << "DFS traversal starting from vertex 0:" << std::endl;
    std::vector<int> dfsResult = graph.DFS(0);
    for (int vertex : dfsResult) {
        std::cout << vertex << " ";
    }
    std::cout << std::endl;

    return 0;
}
