#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define INF 10000000000000000

using namespace std;
typedef pair<long long int, long long int> ii;

vector<long long int> dijkstra(vector<vector<ii>> graph, int sz, int src) {
    vector<long long int> distance(sz, INF);
    priority_queue<ii, vector<ii>, greater<ii>> next;
    next.push({0, src});
    distance[src] = 0;
    while (!next.empty()) {
        auto node = next.top();
        next.pop();
        long long int u = node.second, w = node.first;
        for (auto p : graph[u]) {
            long long int v = p.first, wuv = p.second;
            if (distance[v] > distance[u] + wuv) {
                distance[v] = distance[u] + wuv;
                next.push({distance[v], v});
            }
        }
    }
    return distance;
}

int main() {
    vector<vector<ii>> graph;
    int n, m, q, s;
    while (cin >> n >> m >> q >> s && !(n == 0 && m == 0 && q == 0 && s == 0)) {
        graph.clear();
        graph.resize(n);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back({v, w});
        }
        vector<long long int> distance = dijkstra(graph, n, s);
        while (q--) {
            int v;
            cin >> v;
            if (distance[v] == INF) {
                cout << "Impossible";
            } else {
                cout << distance[v];
            }
            cout << endl;
        }
        cout << endl;
    }
}
