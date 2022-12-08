#include <algorithm>
#include <iostream>
#include <vector>

#define INF 2000000000000000

using namespace std;

int main() {
    int n, m, q;
    long long int graph[150][150] = {};
    while (cin >> n >> m >> q && !(n == 0 && m == 0 && q == 0)) {
        // cin edges
        int u, v, w;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = INF;
            }
        }
        while (m--) {
            cin >> u >> v >> w;
            graph[u][v] = w;
        }
        long long int dist[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    dist[i][j] = 0;
                else if (graph[i][j])
                    dist[i][j] = graph[i][j];
                else
                    dist[i][j] = INF;
            }
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][j] > dist[i][k] + dist[k][j] &&
                        dist[i][k] != INF && dist[k][j] != INF)
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; dist[i][j] != -INF && k < n; k++) {
                    if (dist[i][k] != INF && dist[k][j] != INF &&
                        dist[k][k] < 0) {
                        dist[i][j] = -INF;
                    }
                }
            }
        }
        while (q--) {
            int u, v;
            cin >> u >> v;
            // cout << u << " " << v << " " << dist[u][v] << " ";
            if (dist[u][v] == INF)
                cout << "Impossible";
            else if (dist[u][v] == -INF)
                cout << "-Infinity";
            else
                cout << dist[u][v];
            cout << endl;
        }
        cout << endl;
    }
}
