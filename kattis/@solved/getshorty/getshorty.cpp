#include <bits/stdc++.h>
#define LSOne(S) ((S) & (-S))
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;
const int NINF = 0xcfcfcfcf;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-9;

vector<vector<pair<int, double>>> graph;
vector<double> dist;

int main() {
    int n, m;
    while (cin >> n >> m && !(n == 0 && m == 0)) {
        graph.clear();
        graph.resize(n);
        dist.clear();
        dist.resize(n, 1e9);
        for (int i = 0; i < m; i++) {
            int u, v;
            double d;
            cin >> u >> v >> d;
            if (d == 0) {
                d = 1e9;
            } else {
                d = -log(d);
            }
            graph[u].push_back({v, d});
            graph[v].push_back({u, d});
        }
        dist[0] = 0;
        set<pair<double, int>> q;
        for (int i = 0; i < n; i++) q.emplace(dist[i], i);
        while (!q.empty()) {
            auto [d, u] = *q.begin();
            q.erase(q.begin());
            for (auto &[v, w]: graph[u]) {
                if (dist[u] + w >= dist[v]) continue;
                q.erase(q.find({dist[v], v}));
                dist[v] = dist[u] + w;
                q.emplace(dist[v], v);
            }
        }
        cout << fixed << setprecision(4) << exp(-dist[n - 1]) << endl;
    }
    return 0;
}