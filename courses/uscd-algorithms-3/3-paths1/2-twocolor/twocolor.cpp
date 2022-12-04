#include <iostream>
#include <queue>
#include <vector>

int bipartite(std::vector<std::vector<int>> graph) {
    int sz = graph.size();
    std::vector<int> color(sz, -1);
    std::queue<int> q;
    for (int i = 0; i < sz; i++) {
        if (color[i] == -1) {
            q.push(i);
            color[i] = 0;
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                for (auto n : graph[curr]) {
                    if (color[n] == -1) {
                        q.push(n);
                        color[n] = !color[curr];
                    } else if (color[n] == color[curr]) {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
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
    std::cout << bipartite(graph) << std::endl;
    return 0;
}
