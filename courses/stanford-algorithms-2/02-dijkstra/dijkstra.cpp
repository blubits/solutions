#include <algorithm>
#include <bitset>
#include <fstream>
#include <functional>
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>

#define SIZE 200
#define INFINITY 1000000000

std::vector<int> shortest_paths(
    std::vector<std::vector<std::pair<int, int>>> &graph, int starting_vertex) {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        q;
    std::vector<int> dist(SIZE, INFINITY);

    // initialize dist and queue
    dist[starting_vertex] = 0;
    q.push(std::make_pair(starting_vertex, 0));

    while (!q.empty()) {
        auto m = q.top();
        q.pop();
        int u = m.first, l = m.second;
        if (l <= dist[u]) {
            for (auto neighbor : graph[u]) {
                int v = neighbor.first, l = neighbor.second;
                int crit = dist[u] + l;
                if (dist[v] > crit) {
                    dist[v] = crit;
                    q.push(std::make_pair(v, crit));
                }
            }
        }
    }

    return dist;
}

int main() {
    std::vector<std::vector<std::pair<int, int>>> graph(SIZE + 10);
    std::ifstream infile;
    infile.open("dijkstraData.txt");
    std::cout << "Reading the graph in..." << std::endl;
    int u;
    while (infile >> u) {
        std::string rest;
        std::getline(infile, rest);
        std::istringstream instring(rest);
        int v, wt;
        char comma;
        while (instring >> v >> comma >> wt) {
            graph[u - 1].push_back(std::make_pair(v - 1, wt));
        }
    }
    std::cout << "Beginning shortest path computation..." << std::endl;
    auto ans = shortest_paths(graph, 0);
    std::vector<int> vertices = {7, 37, 59, 82, 99, 115, 133, 165, 188, 197};
    for (auto v : vertices) {
        std::cout << ans[v - 1] << ",";
    }
    std::cout << std::endl;
    return 0;
}
