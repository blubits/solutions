#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

vector<ll> fib;
map<ll, ll> fibidx;

vector<vi> graph;
vector<ll> numbers;
vi indegree;
vi toposort;

vi dist;

int main() {
    fib.push_back(1);
    fib.push_back(1);
    fibidx[1] = 1;
    fibidx[0] = 1;
    for (int i = 2; i < 89; i++) {
        fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
        fibidx[fib[fib.size() - 1]] = i;
    }
    int n, m;
    cin >> n >> m;
    numbers.resize(n);
    graph.resize(n);
    indegree.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    bool double_one = false;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        if (fibidx[numbers[a]] + 1 == fibidx[numbers[b]]) {
            graph[a].push_back(b);
            indegree[b]++;
        } else if (fibidx[numbers[b]] + 1 == fibidx[numbers[a]]) {
            graph[b].push_back(a);
            indegree[a]++;
        } else if (numbers[a] == 1 && numbers[b] == 1) {
            double_one = true;
        }
    }
    queue<int> vertices;
    for (int i = 0; i < n; i++) if (indegree[i] == 0) vertices.push(i);
    while (!vertices.empty()) {
        int u = vertices.front(); vertices.pop();
        toposort.push_back(u);
        for (auto &v: graph[u]) {
            indegree[v]--;
            if (indegree[v] == 0) vertices.push(v);
        }
    }
    dist.assign(n, 0);
    for (int i = 0; i < n; i++) {
        if (numbers[i] == 1 && double_one) dist[i] = 2;
        else if (fibidx[numbers[i]] > 0) dist[i] = 1;
    }
    int max_dist = 0;
    for (auto u: toposort) {
        max_dist = max(max_dist, dist[u]);
        for (auto v: graph[u]) {
            dist[v] = max(dist[v], dist[u] + 1);
        }
    }
    cout << max_dist << endl;
}