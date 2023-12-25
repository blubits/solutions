#include <algorithm>
#include <cstdio>
#include <vector>

#define MAX 10000000
#define MIN -1

using namespace std;

int main() {
    int t = 50, k = 5000;

    // graph
    vector<vector<int>> graph(t);
    for (int i = 0; i < t; i++) {
        graph[i].resize(t);
    }

    // k-shortest path/k-longest path:
    vector<vector<int>> sp(t);
    vector<vector<int>> lp(t);

    for (int j = 0; j < t; j++) {
        sp[j].resize(k + 1);
        lp[j].resize(k + 1);
    }

    while (scanf("%d", &t) == 1 && t != 0) {
        for (int i = 0; i < t; i++) {
            for (int j = 0; j < t; j++) {
                scanf("%d", &graph[i][j]);
            }
        }

        int k;
        scanf("%d", &k);

        // for (int i = 0; i < t; i++) {
        //     for (int j = 0; j < t; j++) {
        //         cout << graph[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        // # of edges
        for (int e = 0; e <= k; e++) {
            // dest node
            for (int j = 0; j < t; j++) {
                // base case
                sp[j][e] = MAX;
                lp[j][e] = MIN;
                if (e == 0) {
                    sp[j][e] = 0;
                    lp[j][e] = 0;
                } else if (e == 1) {
                    sp[j][e] = graph[0][j];
                    lp[j][e] = graph[0][j];
                } else {
                    for (int a = 0; a < t; a++) {
                        sp[j][e] = min(sp[j][e], graph[a][j] + sp[a][e - 1]);
                        lp[j][e] = max(lp[j][e], graph[a][j] + lp[a][e - 1]);
                    }
                }
            }
        }

        int maxwin = MIN, minwin = MAX;
        for (int j = 0; j < t; j++) {
            maxwin = max(maxwin, lp[j][k]);
            minwin = min(minwin, sp[j][k]);
        }

        printf("%d %d\n", maxwin, minwin);
    }
    return 0;
}
