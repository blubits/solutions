#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & (-S))

typedef long long ll;
typedef pair<ll, int> ii;
typedef tuple<ll, int, ll> iii;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<ii> vii;

const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const int NINF = 0xcfcfcfcf;
const double EPS = 1e-9;

int n, m;
vi p;
vector<vii> adj_list;

ll djikstra(int fr, int to, ll fuel) {
    // distance from fr to node, given fuel level
    vector<vll> dist(n, vll(fuel + 1, INF)); 
    // Djikstra's PQ (cost, node, fuel)
    set<iii> pq; 
    pq.insert({0, fr, 0});
    dist[fr][0] = 0;
    while (!pq.empty()) {
        auto [cost, u, f] = *pq.begin();
        pq.erase(pq.begin());
        if (u == to) return cost; // found the destination
        if (cost > dist[u][f]) continue; // already found a better path

        // try to refuel at current node
        if (f < fuel && cost + p[u] < dist[u][f + 1]) {
            dist[u][f + 1] = cost + p[u];
            pq.insert({dist[u][f + 1], u, f + 1});
        }

        // traverse neighbors
        for (auto [v, d] : adj_list[u]) {
            if (f >= d && cost < dist[v][f - d]) {
                dist[v][f - d] = cost;
                pq.insert({cost, v, f - d});
            }
        }
    }
    return INF; // unreachable
}

int main() {
    
    cin >> n >> m;
    p.resize(n);
    adj_list.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        adj_list[u].emplace_back(v, d);
        adj_list[v].emplace_back(u, d);
    }
    int q;
    cin >> q;
    while (q--) {
        ll c, u, v;
        cin >> c >> u >> v;
        ll ans = djikstra(u, v, c);
        if (ans == INF) {
            cout << "impossible" << endl;
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}