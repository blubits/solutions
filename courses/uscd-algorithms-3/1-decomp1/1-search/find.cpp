#include <iostream>
#include <stack>
#include <vector>

int reach(std::vector<std::vector<int>> &graph, int u, int v) {
    // 0: not visited
    // 1: previsit
    // 2: postvisit
    std::vector<int> color(graph.size(), 0);
    std::stack<int> dfs;
    dfs.push(u);
    while (!dfs.empty()) {
        int curr = dfs.top();
        color[curr] = 2;
        dfs.pop();
        for (auto n : graph[curr]) {
            if (color[n] == 0) {
                color[n] = 1;
                dfs.push(n);
            }
        }
    }
    if (color[v] == 0)
        return 0;
    else
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
    int ua, va;
    std::cin >> ua >> va;
    std::cout << reach(graph, ua - 1, va - 1) << std::endl;
    return 0;
}
