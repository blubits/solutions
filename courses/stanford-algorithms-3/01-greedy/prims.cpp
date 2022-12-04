#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <functional>

#define INF 1000000000

long long int min_mst_cost(std::vector<std::vector<std::pair<int, long long int>>> &graph) {
    long long int min_cost = 0;
    int v = graph.size();
    std::priority_queue<std::pair<int, long long int>, std::vector<std::pair<int, long long int>>, std::greater<std::pair<int, long long int>>> pq;

    // Visit v
    std::vector<bool> visited(v);
    visited[0] = true;

    // Push all nodes (V - {0}) to pq
    for (auto next: graph[0]) {
        pq.push(std::make_pair(next.second, next.first));
    }
    for (int i = 1; i < 500; i++) {
        pq.push(std::make_pair(INF, i));
    }

    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        int w = p.first, v = p.second;
        if (visited[v]) continue;
        else {
            std::cout << v << " " << w << std::endl;
            visited[v] = true;
            min_cost += w;
            for (auto next: graph[v]) {
                pq.push(std::make_pair(next.second, next.first));
            }
        }
    }

    return min_cost;

}

int main() {
    std::ifstream infile;
    infile.open("edges.txt");

    int v, e;
    std::vector<std::vector<std::pair<int, long long int>>> graph;
    while (infile >> v >> e) {
        graph.resize(v);
        long long int fr, to, wt;
        for (int i = 0; i < e; i++) {
            infile >> fr >> to >> wt;
            fr--;
            to--;
            graph[fr].push_back(std::make_pair(to, wt));
            graph[to].push_back(std::make_pair(fr, wt));
        }
    }
    std::cout << min_mst_cost(graph) << std::endl;
}