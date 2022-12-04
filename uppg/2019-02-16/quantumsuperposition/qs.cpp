#include <algorithm>
#include <cstdio>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef set<int> si;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

bool pdist1[2000] = {false}, pdist2[2000] = {false};
bool visited[2000][2000] = {false};

int universe = 0;

si modified_bfs(vvi graph) {
    stack<ii> bfs;

    si distances;

    int dest = graph.size() - 1;

    for (int i = 0; i < 2000; i++) {
        for (int j = 0; j < 2000; j++) {
            visited[i][j] = false;
        }
    }

    bfs.push({0, 0});
    while (!bfs.empty()) {
        int v = bfs.top().first, d = bfs.top().second;
        bfs.pop();
        if (v == dest) {
            if (universe == 0)
                pdist1[d] = true;
            else
                pdist2[d] = true;
            continue;
        }
        visited[v][d] = true;
        for (auto w : graph[v]) {
            if (!visited[w][d + 1]) bfs.push({w, d + 1});
        }
    }

    universe++;
    return distances;
}

int main() {
    vector<vector<int>> graph1, graph2;
    int v1, v2, e1, e2;
    scanf("%d %d %d %d", &v1, &v2, &e1, &e2);
    graph1.resize(v1);
    graph2.resize(v2);
    while (e1--) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph1[u - 1].push_back(v - 1);
    }
    while (e2--) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph2[u - 1].push_back(v - 1);
    }
    si dist1 = modified_bfs(graph1), dist2 = modified_bfs(graph2);
    // bool possible[2001] = {false};
    // for (auto i : dist1) {
    //     for (auto j : dist2) {
    //         if (i + j <= 2000)
    //             possible[i + j] = true;
    //         else
    //             break;
    //     }
    // }
    int t;
    scanf("%d", &t);
    while (t--) {
        int q;
        scanf("%d", &q);
        bool possible = false;
        for (int i = 0; i <= q; i++) {
            if ((pdist1[i] && pdist2[q - i]) || (pdist2[i] && pdist1[q - i])) {
                possible = true;
                break;
            }
        }
        if (possible)
            printf("Yes\n");
        else
            printf("No\n");
    }
}
