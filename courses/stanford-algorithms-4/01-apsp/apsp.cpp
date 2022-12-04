#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

#define INF 2000000000

struct ShortestPathResult {
    bool negative_cycle;
    long long int length;
};

ShortestPathResult shortest_shortest_path(
    std::vector<std::vector<std::pair<long long int, long long int>>> &graph,
    int V) {
    ShortestPathResult spr;
    spr.length = INF;
    spr.negative_cycle = false;
    // (1) Bellman-Ford
    std::vector<long long int> h(V + 10);
    h[0] = 0;
    for (int i = 1; i <= V; i++) {
        graph[0].push_back(std::make_pair(i, 0));
        h[i] = INF;
    }
    // over # of internal nodes,
    for (int i = 1; i <= V - 1; i++) {
        // over all edges,
        for (int u = 0; u <= V; u++) {
            for (auto p : graph[u]) {
                // relax the edge ("implicit" DP on the SP with
                // internal node length i)
                int v = p.first;
                long long int w_uv = p.second;
                if (h[u] != INF && h[u] + w_uv < h[v]) {
                    h[v] = h[u] + w_uv;
                }
            }
        }
    }
    // (1.5) Check for negative cycles
    for (int u = 0; u <= V; u++) {
        for (auto p : graph[u]) {
            // relax the edge ("implicit" DP on the SP with
            // internal node length i)
            int v = p.first;
            long long int w_uv = p.second;
            if (h[u] != INF && h[u] + w_uv < h[v]) {
                spr.negative_cycle = true;
                return spr;
            }
        }
    }
    // (2) Reweight edges
    for (int u = 1; u <= V; u++) {
        for (auto p : graph[u]) {
            // relax the edge ("implicit" DP on the SP with
            // internal node length i)
            int v = p.first;
            p.second += (h[u] - h[v]);
        }
    }
    // (3) Djikstra
    std::vector<std::vector<long long int>> dist(V + 10);
    std::priority_queue<std::pair<long long int, long long int>,
                        std::vector<std::pair<long long int, long long int>>,
                        std::greater<std::pair<long long int, long long int>>>
        q;
    for (int sv = 1; sv <= V; sv++) {
        dist[sv].resize(V + 10, INF);
        dist[sv][sv] = 0;
        q.push(std::make_pair(sv, 0));
        while (!q.empty()) {
            auto m = q.top();
            q.pop();
            long long int u = m.first, l = m.second;
            if (l == dist[sv][u]) {
                for (auto neighbor : graph[u]) {
                    long long int v = neighbor.first, wt = neighbor.second;
                    long long int crit = dist[sv][u] + wt;
                    if (dist[sv][v] > crit) {
                        dist[sv][v] = crit;
                        q.push(std::make_pair(v, crit));
                    }
                }
            }
        }
    }
    // (4) Restore weights, return shortest shortest path length
    for (int u = 1; u <= V; u++) {
        for (int v = 1; v <= V; v++) {
            if (dist[u][v] != INF) {
                dist[u][v] += h[v] - h[u];
                if (dist[u][v] < spr.length) {
                    spr.length = dist[u][v];
                }
            }
        }
    }
    return spr;
}

ShortestPathResult shortest_shortest_path_fw(
    std::vector<std::vector<std::pair<long long int, long long int>>> &graph,
    int V) {
    std::vector<std::vector<long long int>> dist(V + 10);
    ShortestPathResult spr;
    spr.length = INF;
    spr.negative_cycle = false;
    for (int u = 1; u <= V; u++) {
        dist[u].resize(V + 10, INF);
        dist[u][u] = 0;
        for (auto p : graph[u]) {
            // relax the edge ("implicit" DP on the SP with
            // internal node length i)
            int v = p.first;
            long long int w_uv = p.second;
            dist[u][v] = w_uv;
        }
    }
    for (int k = 1; k <= V; k++) {
        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    for (int u = 1; u <= V; u++) {
        if (dist[u][u] < 0) {
            spr.negative_cycle = true;
            return spr;
        }
    }
    for (int u = 1; u <= V; u++) {
        for (int v = 1; v <= V; v++) {
            if (dist[u][v] != INF) {
                if (dist[u][v] < spr.length) {
                    spr.length = dist[u][v];
                }
            }
        }
    }
    return spr;
}

int main() {
    std::fstream infile;
    infile.open("g3.txt");

    int V, E;
    infile >> V >> E;
    std::vector<std::vector<std::pair<long long int, long long int>>> graph(V +
                                                                            10);
    for (int i = 0; i < E; i++) {
        int u, v;
        long long int w;
        infile >> u >> v >> w;
        graph[u].push_back(std::make_pair(v, w));
    }
    auto res = shortest_shortest_path(graph, V);
    if (res.negative_cycle) {
        std::cout << "NULL" << std::endl;
    } else {
        std::cout << res.length << std::endl;
    }
    return 0;
}