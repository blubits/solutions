#include <bitset>
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

#define SIZE 875714

std::priority_queue<int> find_scc_sizes(
    std::vector<std::vector<int>> &graph,
    std::vector<std::vector<int>> &graph_r) {
    // Phase 1: Perform SCC on the reversed graph
    // Contents of exploration_stack:
    // (a, 0) -> Exploring an edge
    // (a, 1) -> Finishing times
    std::cout << "Beginning phase 1..." << std::endl;
    std::stack<std::pair<int, int>> exploration_stack;
    std::stack<int> finishing_times_stack;
    std::bitset<SIZE> visited;
    for (int i = 0; i < SIZE; i++) {
        if (!visited.test(i)) {
            exploration_stack.push(std::make_pair(i, 0));
            while (!exploration_stack.empty()) {
                auto curr = exploration_stack.top();
                int curr_node = curr.first, task = curr.second;
                exploration_stack.pop();
                if (task == 0) {
                    visited.set(curr_node);
                    exploration_stack.push(std::make_pair(curr_node, 1));
                    for (auto neighbor : graph_r[curr_node]) {
                        if (!visited.test(neighbor)) {
                            exploration_stack.push(std::make_pair(neighbor, 0));
                        }
                    }
                } else {
                    finishing_times_stack.push(curr_node);
                }
            }
        }
    }
    // Phase 2: Perform DFS on the normal graph
    std::cout << "Beginning phase 2..." << std::endl;
    std::priority_queue<int> scc_sizes;
    visited.reset();
    while (!finishing_times_stack.empty()) {
        int i = finishing_times_stack.top();
        finishing_times_stack.pop();
        if (!visited.test(i)) {
            int scc_size = 0;
            exploration_stack.push(std::make_pair(i, 0));
            while (!exploration_stack.empty()) {
                auto curr = exploration_stack.top();
                int curr_node = curr.first, task = curr.second;
                exploration_stack.pop();
                if (!visited.test(curr_node)) {
                    scc_size++;
                }
                visited.set(curr_node);
                for (auto neighbor : graph[curr_node]) {
                    if (!visited.test(neighbor)) {
                        exploration_stack.push(std::make_pair(neighbor, 0));
                    }
                }
            }
            scc_sizes.push(scc_size);
        }
    }
    return scc_sizes;
}

int main() {
    std::vector<std::vector<int>> graph(SIZE + 1000);
    std::vector<std::vector<int>> graph_r(SIZE + 1000);
    std::ifstream infile;
    infile.open("SCC.txt");
    int u, v;
    std::cout << "Reading the graph in..." << std::endl;
    while (infile >> u >> v) {
        u--;
        v--;
        graph[u].push_back(v);
        graph_r[v].push_back(u);
    }
    std::cout << "Beginning SCC computation..." << std::endl;
    auto ans = find_scc_sizes(graph, graph_r);
    for (int i = 0; i < 5; i++) {
        if (ans.empty()) {
            std::cout << "0";
        } else {
            std::cout << ans.top();
            ans.pop();
        }
        if (i != 4)
            std::cout << ",";
        else
            std::cout << std::endl;
    }
    std::cout << std::endl;
    return 0;
}
