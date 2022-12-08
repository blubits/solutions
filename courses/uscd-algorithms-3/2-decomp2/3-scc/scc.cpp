#include <iostream>
#include <queue>
#include <stack>
#include <vector>

void return_postorder_helper(const std::vector<std::vector<int>> &graph,
                             std::vector<bool> &visited, std::stack<int> &s,
                             int u) {
    visited[u] = true;
    for (auto n : graph[u]) {
        if (!visited[n]) {
            return_postorder_helper(graph, visited, s, n);
        }
    }
    s.push(u);
}

std::stack<int> return_postorder(const std::vector<std::vector<int>> &graph) {
    std::stack<int> ans;
    std::vector<bool> visited(graph.size());
    for (int i = 0; i < graph.size(); i++) {
        if (!visited[i]) return_postorder_helper(graph, visited, ans, i);
    }
    return ans;
}

void count_sccs_helper(const std::vector<std::vector<int>> &graph,
                       std::vector<int> &scc_no, int curr_no, int u) {
    // std::cout << ">> exploring " << u + 1 << std::endl;
    scc_no[u] = curr_no;
    for (auto n : graph[u]) {
        if (scc_no[n] == -1) {
            count_sccs_helper(graph, scc_no, curr_no, n);
        }
    }
}

int count_sccs(const std::vector<std::vector<int>> &graph,
               const std::vector<std::vector<int>> &graph_r) {
    auto nodes_rev_postorder = return_postorder(graph_r);
    std::vector<int> scc_no(graph.size(), -1);
    int curr_no = 0;
    while (!nodes_rev_postorder.empty()) {
        int curr_node = nodes_rev_postorder.top();
        nodes_rev_postorder.pop();
        if (scc_no[curr_node] == -1) {
            // std::cout << "exploring " << curr_node + 1 << std::endl;
            count_sccs_helper(graph, scc_no, curr_no++, curr_node);
        }
        // std::cout << curr_node + 1 << " " << curr_no << std::endl;
    }
    return curr_no;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> graph(n), graph_r(n);
    while (m--) {
        int u, v;
        std::cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph_r[v - 1].push_back(u - 1);
    }
    std::cout << count_sccs(graph, graph_r) << std::endl;
    return 0;
}
