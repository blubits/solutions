#include <iostream>
#include <stack>
#include <vector>

bool has_cycle_helper(const std::vector<std::vector<int>> &graph,
                      std::vector<int> &color, int u) {
    // std::cout << "> " << u + 1 << " " << color[u] << std::endl;
    if (color[u] == 0) {
        color[u] = 1;
    } else if (color[u] == 1) {
        return 1;
    } else {
        return 0;
    }
    for (auto n : graph[u]) {
        int a = has_cycle_helper(graph, color, n);
        if (a == 1) return a;
    }
    color[u] = 2;
    // std::cout << "< " << u + 1 << " " << color[u] << std::endl;
    return 0;
}

int has_cycle(const std::vector<std::vector<int>> &graph) {
    std::vector<int> color(graph.size());
    for (int i = 0; i < graph.size(); i++) {
        if (color[i] == 0 && has_cycle_helper(graph, color, i)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> graph(n);
    while (m--) {
        int u, v;
        std::cin >> u >> v;
        graph[u - 1].push_back(v - 1);
    }
    std::cout << has_cycle(graph) << std::endl;
    return 0;
}
