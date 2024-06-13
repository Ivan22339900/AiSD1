#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <random>
#include <ctime>
#include <string>

using namespace std;

void printGraph(const vector<vector<int>>& graph)
{
    cout << "Graph:" << endl;
    for (int i = 0; i < graph.size(); ++i)
    {
        cout << i << ": ";
        for (int j = 0; j < graph[i].size(); ++j)
        {
            cout << graph[i][j];
            if (j != graph[i].size() - 1)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

/*bool hasEulerianCycle(const vector<vector<int>>& graph) {
    for (int i = 0; i < graph.size(); ++i) {
        if (graph[i].size() % 2 != 0) {
            return false;
        }
    }
    return true;
}*/

bool hasEulerianCycle(const vector<vector<int>>& graph, vector<int>& cycle) {
    int n = graph.size();
    /*if (!hasEulerianCycle(graph))
    {
        return false;
    }*/

    // Znajdź wierzchołek startowy z parzystym stopniem
    int start = 0;
    for (int i = 0; i < n; ++i)
    {
        if (graph[i].size() % 2 == 0 && !graph[i].empty()) {
            start = i;
            break;
        }
    }

    // Algorytm Fleury'ego do znalezienia cyklu Eulera
    vector<vector<int>> tmpGraph = graph; // Skopiuj graf tymczasowy
    vector<int> path;
    int u = start;
    path.push_back(u);

    while (!path.empty())
    {
        if (tmpGraph[u].empty())
        {
            cycle = path;
            return true;
        }
        else
        {
            int v = tmpGraph[u].back();
            tmpGraph[u].pop_back();
            for (int i = 0; i < tmpGraph[v].size(); ++i)
            {
                if (tmpGraph[v][i] == u)
                {
                    tmpGraph[v].erase(tmpGraph[v].begin() + i);
                    break;
                }
            }
            u = v;
            path.push_back(u);
        }
    }

    return false;
}

bool findHamiltonianCycleUtil(const vector<vector<int>>& graph, vector<int>& path, vector<bool>& visited, int pos) {
    if (pos == graph.size()) {
        return find(graph[path[pos - 1]].begin(), graph[path[pos - 1]].end(), path[0]) != graph[path[pos - 1]].end();
    }

    for (int v : graph[path[pos - 1]]) {
        if (!visited[v]) {
            visited[v] = true;
            path[pos] = v;

            if (findHamiltonianCycleUtil(graph, path, visited, pos + 1)) {
                return true;
            }

            visited[v] = false;
        }
    }
    return false;
}

/*bool findHamiltonianCycle(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> path(n);
    vector<bool> visited(n, false);

    path[0] = 0;
    visited[0] = true;

    if (findHamiltonianCycleUtil(graph, path, visited, 1)) {
        return true;
    } else {
        return false;
    }
}*/

bool findHamiltonianCycle(const vector<vector<int>>& graph, vector<int>& cycle) {
    int n = graph.size();
    vector<int> path(n);
    vector<bool> visited(n, false);

    path[0] = 0;
    visited[0] = true;

    if (findHamiltonianCycleUtil(graph, path, visited, 1))
    {
        for (int i = 0; i < n; ++i)
        {
            cycle.push_back(path[i]);
        }
        return true;
    }
    else
    {
        return false;
    }
}

vector<vector<int>> generateHamiltonianGraph(int n, float saturation)
{
    vector<vector<int>> graph(n);

    // Tworzenie cyklu Hamiltona
    vector<int> cycle(n);
    for (int i = 0; i < n; ++i)
    {
        cycle[i] = i;
    }
    random_shuffle(cycle.begin(), cycle.end());

    for (int i = 0; i < n; ++i)
    {
        graph[cycle[i]].push_back(cycle[(i + 1) % n]);
        graph[cycle[(i + 1) % n]].push_back(cycle[i]);
    }

    // Dodawanie dodatkowych krawędzi dla osiągnięcia zadanej nasycenia
    int edges = n;
    int targetEdges = saturation * n * (n - 1) / 200;
    srand(time(0));
    while (edges < targetEdges) {
        int u = rand() % n;
        int v = rand() % n;
        if (u != v && find(graph[u].begin(), graph[u].end(), v) == graph[u].end()) {
            graph[u].push_back(v);
            graph[v].push_back(u);
            edges++;
        }
    }
    return graph;
}

vector<vector<int>> generateNonHamiltonianGraph(int n) {
    vector<vector<int>> graph(n);

    // Tworzenie cyklu Hamiltona
    vector<int> cycle(n);
    for (int i = 0; i < n; ++i)
    {
        cycle[i] = i;
    }
    random_shuffle(cycle.begin(), cycle.end());

    for (int i = 0; i < n; ++i)
    {
        graph[cycle[i]].push_back(cycle[(i + 1) % n]);
        graph[cycle[(i + 1) % n]].push_back(cycle[i]);
    }

    // Usunięcie jednego wierzchołka
    int isolatedVertex = rand() % n;
    for (int i = 0; i < n; ++i)
    {
        if (i != isolatedVertex)
        {
            graph[i].erase(remove(graph[i].begin(), graph[i].end(), isolatedVertex), graph[i].end());
        }
    }

    return graph;
}

int main(int argc, char* argv[]) 
{
    if (argc < 2)
    {
        cout << "Usage: ./program --hamilton or --non-hamilton" << endl;
        return 1;
    }

    string mode = argv[1];

    if (mode == "--hamilton")
    {
        int n;
        float saturation;
        cout << "nodes> ";
        cin >> n;
        cout << "saturation> ";
        cin >> saturation;

        if (n <= 10)
        {
            cout << "Number of nodes must be greater than 10." << endl;
            return 1;
        }

        vector<vector<int>> graph = generateHamiltonianGraph(n, saturation);

        string command;
        while (true) 
        {
            cout << "action> ";
            cin >> command;

            if (command == "print") {
                printGraph(graph);
            }
            else if (command == "euler")
            {
                vector<int> cycle;
                if (hasEulerianCycle(graph, cycle))
                {
                    cout << "Graph has an Eulerian cycle: ";
                    for (int v : cycle)
                    {
                        cout << v << " ";
                    }
                    cout << endl;
                } 
                else 
                {
                    cout << "Graph does not have an Eulerian cycle." << endl;
                }
            } 
            else if (command == "hamilton")
            {
                vector<int> cycle;
                if (findHamiltonianCycle(graph, cycle))
                {
                    cout << "Graph has a Hamiltonian cycle: ";
                    for (int v : cycle)
                    {
                        cout << v << " ";
                    }
                    cout << endl;
                }
                else
                {
                    cout << "Graph does not have a Hamiltonian cycle." << endl;
                }
            }
            else if (command == "quit")
            {
                break;
            } 
            else
            {
                cout << "Invalid command. Valid commands: print, euler, hamilton, quit" << endl;
            }
        }
    }
    else if (mode == "--non-hamilton")
    {
        int n;
        cout << "nodes> ";
        cin >> n;

        vector<vector<int>> graph = generateNonHamiltonianGraph(n);

        string command;
        while (true)
        {
            cout << "action> ";
            cin >> command;

            if (command == "print")
            {
                printGraph(graph);
            } 
            else if (command == "euler")
            {
                vector<int> cycle;
                if (hasEulerianCycle(graph, cycle))
                {
                    cout << "Graph has an Eulerian cycle: ";
                    for (int v : cycle)
                    {
                        cout << v << " ";
                    }
                    cout << endl;
                }
                else
                {
                    cout << "Graph does not have an Eulerian cycle." << endl;
                }
            }
            else if (command == "hamilton")
            {
                vector<int> cycle;
                if (findHamiltonianCycle(graph, cycle))
                {
                    cout << "Graph has a Hamiltonian cycle: ";
                    for (int v : cycle)
                    {
                        cout << v << " ";
                    }
                    cout << endl;
                }
                else
                {
                    cout << "Graph does not have a Hamiltonian cycle." << endl;
                }
            }
            else if (command == "quit")
            {
                break;
            }
            else
            {
                cout << "Invalid command. Valid commands: print, euler, hamilton, quit" << endl;
            }
        }
    }
    else
    {
        cout << "Invalid argument. Use --hamilton or --non-hamilton." << endl;
        return 1;
    }

    return 0;
}
