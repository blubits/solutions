#include <iostream>
#include <stack>
#include <vector>

int count_ccs(std::vector<std::vector<int>> &graph) {
    int cc = 0;
    // 0: not visited
    // 1: previsit
    // 2: postvisit
    std::vector<int> color(graph.size(), 0);
    std::vector<int> component(graph.size(), 0);
    std::stack<int> dfs;
    for (int i = 0; i < graph.size(); i++) {
        if (color[i] == 0) {
            dfs.push(i);
            while (!dfs.empty()) {
                int curr = dfs.top();
                color[curr] = 2;
                component[curr] = cc;
                dfs.pop();
                for (auto n : graph[curr]) {
                    if (color[n] == 0) {
                        color[n] = 1;
                        dfs.push(n);
                    }
                }
            }
            cc++;
        }
    }
    return cc;
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
    std::cout << count_ccs(graph) << std::endl;
    return 0;
}
