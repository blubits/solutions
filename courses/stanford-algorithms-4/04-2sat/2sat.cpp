#include <bitset>
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

#define SIZE 3000000

bool twosatisfiable(std::vector<std::vector<int>> &graph,
                    std::vector<std::vector<int>> &graph_r, int N) {
    // Phase 1: Perform SCC on the reversed graph
    // Contents of exploration_stack:
    // (a, 0) -> Exploring an edge
    // (a, 1) -> Finishing times
    std::cout << N << std::endl;
    std::stack<std::pair<int, int>> exploration_stack;
    std::stack<int> finishing_times_stack;
    std::bitset<SIZE> visited;
    for (int i = 0; i < (2 * N); i++) {
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
    visited.reset();
    std::vector<int> scc_no(2 * N);
    int scc_currno = 1;
    while (!finishing_times_stack.empty()) {
        int i = finishing_times_stack.top();
        finishing_times_stack.pop();
        if (!visited.test(i)) {
            exploration_stack.push(std::make_pair(i, 0));
            while (!exploration_stack.empty()) {
                auto curr = exploration_stack.top();
                int curr_node = curr.first;
                exploration_stack.pop();
                visited.set(curr_node);
                scc_no[curr_node] = scc_currno;
                for (auto neighbor : graph[curr_node]) {
                    if (!visited.test(neighbor)) {
                        exploration_stack.push(std::make_pair(neighbor, 0));
                    }
                }
            }
            scc_currno++;
        }
    }
    std::cout << scc_currno << std::endl;
    for (int i = 0; i < N; i++) {
        if (scc_no[2 * i] == scc_no[(2 * i) + 1]) return false;
    }
    return true;
}

int main() {
    std::vector<std::vector<int>> graph;
    std::vector<std::vector<int>> graph_r;
    std::ifstream infile[7];
    for (int i = 0; i < 6; i++) {
        infile[i].open("2sat" + std::to_string(i + 1) + ".txt");
        graph.clear();
        graph_r.clear();
        int N;
        infile[i] >> N;
        graph.resize(2 * N);
        graph_r.resize(2 * N);
        int u, nu, v, nv;
        while (infile[i] >> u >> v) {
            // transform clauses into vertices
            if (u > 0) {
                u = (2 * u) - 2;
                nu = u + 1;
            } else {
                u = (-2 * u) - 1;
                nu = u - 1;
            }
            if (v > 0) {
                v = (2 * v) - 2;
                nv = v + 1;
            } else {
                v = (-2 * v) - 1;
                nv = v - 1;
            }
            graph[nu].push_back(v);
            graph_r[v].push_back(nu);
            graph[nv].push_back(u);
            graph_r[u].push_back(nv);
        }
        if (twosatisfiable(graph, graph_r, N)) {
            std::cout << "1";
        } else {
            std::cout << "0";
        }
        std::cout << std::endl;
    }
    return 0;
}