#include <iostream>
#include <queue>
#include <vector>

int shortest_path(std::vector<std::vector<int>> graph, int u, int v) {
    int sz = graph.size();
    std::vector<int> distance(sz, -1);
    std::queue<int> q;
    q.push(u);
    distance[u] = 0;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (auto n : graph[curr]) {
            if (distance[n] == -1) {
                q.push(n);
                distance[n] = distance[curr] + 1;
            }
        }
    }
    return distance[v];
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> graph(n);
    while (m--) {
        int u, v;
        std::cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }
    int ua, va;
    std::cin >> ua >> va;
    std::cout << shortest_path(graph, ua - 1, va - 1) << std::endl;
    return 0;
}
