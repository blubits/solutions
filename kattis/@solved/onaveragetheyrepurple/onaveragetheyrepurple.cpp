#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

int n, m;
vector<vi> graph;
vector<bool> visited;

int ans() {
    queue<ii> vertices;
    vertices.push({0, 0});
    visited[0] = true;
    while (!vertices.empty()) {
        auto &[v, wt] = vertices.front(); vertices.pop();
        for (auto &w: graph[v]) {
            if (!visited[w]) {
                if (w == n - 1) return wt;
                visited[w] = true;
                vertices.push({w, wt + 1});
            }
        }
    }
    return -1;
}

int main() {
    cin >> n >> m;
    graph.resize(n);
    visited.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cout << ans() << endl;
    return 0;
}