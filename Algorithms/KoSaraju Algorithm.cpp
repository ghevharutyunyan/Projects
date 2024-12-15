#include <iostream>
#include <vector>
#include <stack>

void dfs1(int v, std::vector<std::vector<int>>& graph, std::vector<bool>& visited, std::stack<int>& topoStack) {
    visited[v] = true;
    for (int neighbor : graph[v]) {
        if (!visited[neighbor]) {
            dfs1(neighbor, graph, visited, topoStack);
        }
    }

    topoStack.push(v);
}

void dfs2(int v, std::vector<std::vector<int>>& transponseGraph, std::vector<bool>& visited, std::vector<int>& vec) {
    visited[v] = true;

    for (int neighbor : transponseGraph[v]) {
        if (!visited[neighbor]) {
            dfs2(neighbor, transponseGraph, visited, vec);
        }
    }
    vec.push_back(v);
}

std::vector<std::vector<int>> Kosaraju(std::vector<std::vector<int>>& graph, int n) {
    std::vector<bool> visited(n, false);
    std::stack<int> st;

    for (int i = 0; i < graph.size(); ++i) {
        if (!visited[i]) {
            dfs1(i, graph, visited, st);
        }
    }

    std::vector<std::vector<int>> transPonseGraph(n);

    for (int i = 0; i < n; ++i) {
        for (int neighbor : graph[i]) {
            transPonseGraph[neighbor].push_back(i);
        }
    }

    std::fill(visited.begin(), visited.end(), false);
    std::vector<std::vector<int>> SCC;

    while (!st.empty()) {
        int u = st.top();
        st.pop();

        if (!visited[u]) {
           std::vector<int> component;
           dfs2(u, transPonseGraph, visited, component);
           SCC.push_back(component);
        }
    }
    return SCC;
}

int main()
{
    std::cout << "Hello World!\n";
}

