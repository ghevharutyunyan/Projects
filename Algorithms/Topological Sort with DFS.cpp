#include <iostream>
#include <vector>
#include <stack>

void dfs(int u, std::vector<std::vector<int>>& graph, std::vector<bool> visited, std::stack<int>& topoStack) {
    visited[u] = true;

    for (int neighbor : graph[u]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, topoStack);
        }
    }

    topoStack.push(u);
}

std::vector<int> topSort(int n, std::vector<std::vector<int>>& graph) {
    std::vector<bool> visited(n, false);
    std::stack<int> st;
    
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, graph, visited, st);
        }
    }

    std::vector<int> topOrder;

    while (!st.empty()) {
        topOrder.push_back(st.top());
        st.pop();
    }
    return topOrder;
}

int main()
{
    std::cout << "Hello World!\n";
}

