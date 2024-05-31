#include <bits/stdc++.h>
#define LSOne(S) ((S) & (-S))
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;

const ll LLINF = 9e18;
const ll LLNINF = -9e18;
const double EPS = 1e-9;

vector<vi> graph;
vector<ll> vertices;

const int PROPERTY = 0, SALARY = 1, TAX = 2;

ll dp[100010];

ll longest(int u) {
    if (graph[u].empty()) return 0;
    if (dp[u] > LLNINF) return dp[u];
    ll ans = LLNINF;
    for (auto v: graph[u]) {
        ans = max(ans, vertices[v] + longest(v));
    }
    return dp[u] = ans;
}

int main() {
    int N, M, K, sa, sb;
    cin >> N >> M >> K >> sa >> sb;
    sa--; sb--;
    graph.resize(N);
    vertices.resize(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
    }
    for (int i = 0; i < N; i++) {
        string type;
        cin >> type;
        if (type == "PROPERTY") {
            int b, r;
            cin >> b >> r;
            vertices[i] = 0;
        } else {
            ll v;
            cin >> v;
            if (type == "TAX") v = -v;
            vertices[i] = v;
        }
    }
    fill(&dp[0], &dp[0] + 100010, LLNINF);
    cout << longest(sa) << " " << longest(sb) << endl;
    return 0;
}