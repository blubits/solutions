#include <iostream>
#include <stack>
#include <vector>

void toposort_helper(const std::vector<std::vector<int>> &graph,
                     std::vector<bool> &visited, std::stack<int> &ans, int u) {
    visited[u] = true;
    for (auto n : graph[u]) {
        if (!visited[n]) {
            toposort_helper(graph, visited, ans, n);
        }
    }
    ans.push(u);
}

std::stack<int> toposort(const std::vector<std::vector<int>> &graph) {
    std::vector<bool> visited(graph.size());
    std::stack<int> ans;
    for (int i = 0; i < graph.size(); i++) {
        if (!visited[i]) toposort_helper(graph, visited, ans, i);
    }
    return ans;
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
    auto ans = toposort(graph);
    while (!ans.empty()) {
        std::cout << ans.top() + 1 << " ";
        ans.pop();
    }
    std::cout << std::endl;
    return 0;
}
