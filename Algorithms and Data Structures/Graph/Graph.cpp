#include <iostream>
#include <vector>
#include <stack>


class Graph {
private:
    int numVertices;
    std::vector<std::vector<int>> adjMatrix;
public:
    Graph(int numbVertices):numVertices(numbVertices), adjMatrix(numbVertices, std::vector<int>(numbVertices, 0)){}

    void addEdge(int u, int v) {
        if ((u >= 0 && u < numVertices) && (v >= 0 && v < numVertices)) {
            adjMatrix[u][v] = 1;
            adjMatrix[v][u] = 1;
        }
    }

    void print() {
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                std::cout << adjMatrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void DFS(int startVertex) {
        std::stack<int> st;
        std::vector<bool> visited(numVertices,false);

        st.push(startVertex);
        visited[startVertex] = true;

        while (!st.empty()) {
            int vertex = st.top();
            st.pop();

            
                std::cout << vertex << " ";

            for (int i = 0; i < numVertices; ++i) {
                if (adjMatrix[vertex][i] == 1 && !visited[i]) {
                    st.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    void recursiv_DFS(int startVertex, std::vector<bool>& visited) {
        visited[startVertex] = true;
        
        std::cout << visited[startVertex];

        for (int i = 0; i < numVertices; ++i) {
            if (adjMatrix[startVertex][i] == 1 && !visited[i]) {
                recursiv_DFS(i, visited);
            }
        }
    }
       
   
        
    
};



void addEdge(std::vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
}

void topologicalSortDFS(int v, std::vector<bool>& visited, std::stack<int>& Stack, std::vector<int> adj[]) {
    visited[v] = true; 

    for (int neighbor : adj[v]) {
        if (!visited[neighbor]) {
            topologicalSortDFS(neighbor, visited, Stack, adj);
        }
    }

    Stack.push(v); 
}

void topologicalSort(int vertices, std::vector<int> adj[]) {
    std::stack<int> Stack;
    std::vector<bool> visited(vertices, false);

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            topologicalSortDFS(i, visited, Stack, adj);
        }
    }
    while (!Stack.empty()) {
        std::cout << Stack.top() << " ";
        Stack.pop();
    }
    std::cout << std::endl;
}

int main() {
   const int vertices = 6;
    std::vector<int> adj[vertices];

    addEdge(adj, 5, 2);
    addEdge(adj, 5, 0);
    addEdge(adj, 4, 0);
    addEdge(adj, 4, 1);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);

    topologicalSort(vertices, adj);

    return 0;
}




