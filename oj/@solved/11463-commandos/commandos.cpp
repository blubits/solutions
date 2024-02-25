#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

int graph[150][150];

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N, R;
        cin >> N >> R;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                graph[i][j] = (i == j) ? 0 : INF;
            }
        }
        for (int i = 0; i < R; i++) {
            int u, v;
            cin >> u >> v;
            graph[u][v] = graph[v][u] = 1;
        }
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
        int s, d, mintime = 0;
        cin >> s >> d;
        for (int i = 0; i < N; i++) {
            if (graph[s][i] != INF && graph[i][d] != INF) {
                mintime = max(mintime, graph[s][i] + graph[i][d]);
            }
        }
        printf("Case %d: %d\n", t+1, mintime);
    }
    return 0;
}