#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

int m, n, s0;
int a[10], b[10];
vector<bool> visited;

int sol() {
    queue<ii> vertices;
    vertices.push({s0, 0});
    visited.resize(m, false);
    visited[s0] = true;
    while (!vertices.empty()) {
        auto [v, wt] = vertices.front(); vertices.pop();
        for (int i = 0; i < n; i++) {
            int w = int(((ll(v) * ll(a[i])) + ll(b[i])) % ll(m));
            if (!visited[w]) {
                if (w == 0) {
                    return wt + 1;
                }
                visited[w] = true;
                vertices.push({w, wt + 1});
            }
        }
    }
    return -1;
}

int main() {
    cin >> m >> n >> s0;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    cout << sol() << endl;
    return 0;
}