#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

#define INF 2000000000

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

using namespace std;

vector<vii> graph;
vi dist;

void dijkstras(int s, int n) {
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, s);
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto &[v, w] : graph[u]) {
            if (dist[u] + w >= dist[v]) continue;
            dist[v] = dist[u] + w;
            pq.emplace(dist[v], v);
        }
    }
}

// void dijkstras(int s, int n) {
//     dist[s] = 0;
//     set<pair<int, int>> pq;
//     for (int u = 0; u < n; u++) {
//         pq.emplace(dist[u], u);
//     }
//     while (!pq.empty()) {
//         auto [d, u] = *pq.begin();
//         pq.erase(pq.begin());
//         for (auto &[v, w] : graph[u]) {
//             if (dist[u] + w >= dist[v]) continue;
//             pq.erase(pq.find({dist[v], v}));
//             dist[v] = dist[u] + w;
//             pq.emplace(dist[v], v);
//         }
//     }
// }

int main() {
    int n, m, q, s;
    while (cin >> n >> m >> q >> s && !(n + m + q + s == 0)) {
        graph.clear();
        dist.clear();
        graph.resize(n);
        dist.assign(n, INF);
        while (m--) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back(make_pair(v, w));
        }
        dijkstras(s, n);
        while (q--) {
            int i;
            cin >> i;
            if (dist[i] == INF) cout << "Impossible";
            else cout << dist[i];
            cout << endl;
        }
        cout << endl;
    }
}