#include <iostream>
#include <vector>
#include <queue>
#include <limits>

const int INF = std::numeric_limits<int>::max();

void dijkstra(int start, const std::vector<std::vector<std::pair<int, int>>>& graph) {
    int n = graph.size();
    std::vector<int> dist(n,INF);

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;

    dist[start] = 0;
    pq.emplace(0, start);

    while (!pq.empty()) {
        std::pair<int, int> u = pq.top();
        pq.pop();

        if (u.second > dist[u.first]) {
            continue;
        }

        for (std::pair<int,int> v : graph[u.second]) {
            if (dist[v.first] > dist[u.first] + v.second) {
                dist[v.first] = dist[u.first] + v.second;
                pq.emplace(dist[v.first], v.first);
            }
        }
    }

}

#include <iostream>
#include <vector>

const int INF = std::numeric_limits<int>::max();

void dijkstra(int start, const std::vector<std::vector<std::pair<int, int>>>& graph);

int main() {
    
    int n;
    std::cout << "Enter number of vertices: ";
    std::cin >> n;

    std::vector<std::vector<std::pair<int, int>>> graph(n);

    std::cout << "Enter edges in the format 'u v w' where 'u' and 'v' are vertices and 'w' is the weight of the edge:\n";
    int u, v, w;
    while (true) {
        std::cin >> u;
        if (u == -1) break; 
        std::cin >> v >> w;
        graph[u].emplace_back(v, w);
    }

    int start;
    std::cout << "Enter starting vertex: ";
    std::cin >> start;

    dijkstra(start, graph);

    return 0;
}


