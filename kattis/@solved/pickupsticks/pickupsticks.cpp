#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

vector<vi> graph;
vi indegree;
int n, m;

int main() {
    cin >> n >> m;
    graph.resize(n);
    indegree.assign(n, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        indegree[b]++;
    }
    queue<int> pq;
    for (int u = 0; u < n; u++)
        if (indegree[u] == 0) pq.push(u);
    vi ans;
    while (!pq.empty()) {
        int u = pq.front(); pq.pop();
        ans.push_back(u + 1);
        for (auto &v: graph[u]) {
            indegree[v]--;
            if (indegree[v] == 0) pq.push(v);
        }
    }
    if (ans.size() == n) {
        for (auto &a: ans) cout << a << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}