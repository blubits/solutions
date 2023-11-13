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
vi numbers;

int main() {
    fib.push_back(1);
    fib.push_back(1);
    fibidx[1] = 1;
    fibidx[0] = 1;
    for (int i = 2; i < 90; i++) {
        fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
        fibidx[fib[fib.size() - 1]] = i;
    }
    int n, m;
    cin >> n >> m;
    numbers.resize(n);
    graph.resize(90);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    bool double_one = false;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        if (fibidx[numbers[a]] + 1 == fibidx[numbers[b]]) {
            graph[fibidx[numbers[a]]].push_back(fibidx[numbers[b]]);
        } else if (fibidx[numbers[b]] + 1 == fibidx[numbers[a]]) {
            graph[fibidx[numbers[b]]].push_back(fibidx[numbers[a]]);
        } else if (numbers[a] == 1 && numbers[b] == 1) {
            double_one = true;
        }
    }

    vi dist(90, 0);
    for (int i = 0; i < n; i++) {
        if (fibidx[numbers[i]] > 0) dist[fibidx[numbers[i]]] = 1;
    }
    if (double_one) dist[1] = 2;
    // for (int i = 1; i < 90; i++) {
    //     cout << i << " " << fib[i] << " " << dist[i]  << endl;
    // }
    int max_dist = 0;
    for (int u = 1; u < 90; u++) {
        max_dist = max(max_dist, dist[u]);
        for (auto &v: graph[u]) {
            dist[v] = max(dist[v], dist[u] + 1);
        }
    }
    cout << max_dist << endl;
}