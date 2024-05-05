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

int n, m, k;
vector<int> colors;
vector<vi> graph;

int all_colors;
ll memo[1 << 5][300010];

ll dp(int colorset, int u) {
    if (colorset == 0) return ll(1);
    if (memo[colorset][u] != -1) return memo[colorset][u];
    ll &ans = memo[colorset][u];
    ans = 1;
    for (auto v: graph[u]) {
        if (colorset & (1 << colors[v])) {
            ans += dp(colorset ^ (1 << colors[v]), v);
        }
    }
    return memo[colorset][u] = ans;
}

int main() {
    cin >> n >> m >> k;
    colors.resize(n);
    graph.resize(n);
    all_colors = (1 << k) - 1;
    memset(memo, -1, sizeof(memo));
    for (int i = 0; i < n; i++) {
        cin >> colors[i];
        colors[i]--;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    ll ans = -n;
    for (int i = 0; i < n; i++) {
        ans += dp(all_colors ^ (1 << colors[i]), i);
    }
    cout << ans << endl;
    return 0;
}