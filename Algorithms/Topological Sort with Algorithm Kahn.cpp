#include <iostream>
#include <vector>
#include <queue>

void Top_Sort(std::vector<std::vector<int>>& graph, int n) {
    std::vector<int> inDegree(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int v : graph[i]) {
            inDegree[v]++;
        }
    }

    std::queue<int> q;

    for (int i = 0; i < inDegree.size(); ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    int count = 0;
    while (!q.empty()) {
        int vertex = q.front();
        q.pop();

        for (int u : graph[vertex]) {
            inDegree[u]--;
            if (inDegree[u] == 0) {
                q.push(u);
            }
        }
        count++;
    }

    if (count != n) {
        std::cout << "Graph has a cycle!\n";
    }
    else {
        std::cout << "Topological Sort successful.\n";
    }
}

int main() {
    
    std::vector<std::vector<int>> graph = {
        {1, 2},        
        {3},           
        {3},           
        {},            
        {5},           
        {}             
    };

    int n = graph.size(); 

    Top_Sort(graph, n);

    return 0;
}


