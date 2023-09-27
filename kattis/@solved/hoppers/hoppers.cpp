#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<int> visited;
vector<int> color;
int n, m;

const int WHITE = 0, GRAY = 1, BLACK = 2;
const int INF = 200000000;

void dfs(int v) {
    visited[v] = GRAY;
    for (int n: graph[v]) {
        if (!visited[n]) /* visited[n] == WHITE */ {
            dfs(n);
        }
    }
    visited[v] = BLACK;
} 

int count_ccs() {
    visited.clear();
    visited.resize(n);
    int ccs = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            ccs++;
            dfs(i);
        } 
    }
    return ccs;
}

bool bfs_is_bipartite(int a) {
    queue<int> q;
    q.push(a);
    color[a] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        visited[u] = BLACK;
        for (auto &v: graph[u]) {
            if (color[v] == INF) {
                visited[v] = GRAY;
                color[v] = 1 - color[u];
                q.push(v);
            } else if (color[u] == color[v]) {
                return false;
            }
        }
    }
    return true;
} 


bool odd_cycle() {
    visited.clear();
    visited.resize(n);
    color.resize(n);
    for (int i = 0; i < n; i++) color[i] = INF;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (!bfs_is_bipartite(i)) { return true;}
        } 
    }
    return false;
}

int main() {
    cin >> n >> m;
    graph.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }
    int ccs = count_ccs();
    if (odd_cycle()) cout << ccs - 1 << endl;
    else cout << ccs << endl;
    return 0;
}