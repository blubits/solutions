#include <bits/stdc++.h>
#define INF 1e9
#define LLINF 4e18
using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n, m, a, b, w;
vector<vii> graph;
vi dist;
vi pred;
vi pred_wt;
stack<int> ans;

void dijkstras() {
    set<ii> pq;
    dist[1] = 0;
    pred[1] = -1;
    pred_wt[1] = INF;
    pq.emplace(make_pair(0, 1));
    for (int i = 0; i < n; i++) {
        if (i != 1) {
            dist[i] = INF;
            pq.emplace(make_pair(INF, i));
        }
    }
    while (!pq.empty()) {
        auto [d, u] = *pq.begin();
        pq.erase(pq.begin());
        for (auto neighbor: graph[u]) {
            auto [v, w] = neighbor;
            if (dist[u] + w >= dist[v]) continue;
            pq.erase(pq.find({dist[v], v}));
            dist[v] = dist[u] + w;
            pred[v] = u;
            pred_wt[v] = w;
            pq.emplace(make_pair(dist[v], v));
        }
    }
    // block edges
    for (int i = 0; i < n; i++) {
        int u = i, v = pred[i];
        replace(graph[u].begin(), graph[u].end(), make_pair(v, pred_wt[i]), make_pair(v, int(INF)));
    }
    dist.clear();
    pred.clear();
    pred_wt.clear();
    // print edges
    for (int i = 0; i < n; i++) {
        for (auto u: graph[i]) {
            cout << i << " " << u.first << " " << u.second << endl;
        }
    }
    // rerun dijkstra
    dist.resize(n);
    pred.resize(n);
    pred_wt.resize(n);
    dist[0] = 0;
    pred[0] = -1;
    pred_wt[0] = INF;
    pq.emplace(make_pair(0, 0));
    for (int i = 1; i < n; i++) {
        dist[i] = INF;
        pq.emplace(make_pair(INF, i));
    }
    while (!pq.empty()) {
        auto [d, u] = *pq.begin();
        pq.erase(pq.begin());
        for (auto neighbor: graph[u]) {
            auto [v, w] = neighbor;
            if (dist[u] + w >= dist[v]) continue;
            pq.erase(pq.find({dist[v], v}));
            dist[v] = dist[u] + w;
            pred[v] = u;
            pred_wt[v] = w;
            pq.emplace(make_pair(dist[v], v));
        }
    }
    if (dist[1] >= INF) {
        cout << "impossible";
    } else {
        int p = 1;
        while (p != -1) {
            ans.push(p);
            p = pred[p];
        }
        cout << ans.size();
        while (!ans.empty()) {
            cout << " " << ans.top();
            ans.pop();
        }
    }
    cout << endl;
}

int main() {
    cin >> n >> m;
    graph.resize(n);
    dist.resize(n);
    pred.resize(n);
    pred_wt.resize(n);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }
    dijkstras();
    return 0;
}