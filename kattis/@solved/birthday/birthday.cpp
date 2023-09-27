#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

const int WHITE = 0, GRAY = 1, BLACK = 2;

void find_ap_and_bridge(
    vector<vector<int>> &graph, vector<int> &visited,
    vector<int> &dfs_num, vector<int> &dfs_low, vector<int> &dfs_parent,
    vector<pair<int, int>> &bridges,
    int &root_children, int &dfs_root, int &dfs_number_counter, int u
) {
    visited[u] = GRAY;
    dfs_num[u] = dfs_number_counter++;
    dfs_low[u] = dfs_num[u];
    for (int v: graph[u]) {
        if (visited[v] == WHITE) {
            dfs_parent[v] = u;
            if (u == dfs_root) root_children++;
            find_ap_and_bridge(
                graph, visited, dfs_num, dfs_low, dfs_parent,
                bridges, root_children, dfs_root, dfs_number_counter, v
            );

            if (dfs_num[u] < dfs_low[v]) {
                // articulation point AND bridge
                //cout << u << " " << v << endl;
                bridges.push_back(make_pair(u, v));
            }

            if (dfs_num[u] == dfs_low[v]) {
                // articulation point
                // ignore
            }

            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else /* any other edge */ {
            if (v != dfs_parent[u]) /* not a bidirectional edge */ {
                dfs_low[u] = min(dfs_low[u], dfs_num[v]);
            }
        }
    }
    visited[u] = BLACK;
}

bool has_bridge(vector<vector<int>> &graph, int v) {
    vector<int> visited; 
    vector<int> dfs_num, dfs_low, dfs_parent;
    int dfs_number_counter, dfs_root, root_children;
    vector<pair<int, int>> bridges;
    visited.assign(v, WHITE);
    dfs_num.assign(v, -1); 
    dfs_low.assign(v, 0);
    dfs_parent.assign(v, -1); 
    dfs_number_counter = 0;
    dfs_root = 0;
    root_children = 0;
    find_ap_and_bridge(
        graph, visited, dfs_num, dfs_low, dfs_parent, bridges,
        root_children, dfs_root, dfs_number_counter, dfs_root
    );
    // for (auto& [fr, to]: bridges) {
    //     printf("Edge (%d, %d)\n", fr, to);
    // }
    if (bridges.empty()) return false;
    else return true;
}

void dfs(vector<vector<int>> &graph, vector<int> &visited, int v) {
    visited[v] = GRAY;
    for (int n: graph[v]) {
        if (!visited[n]) /* visited[n] == WHITE */ {
            dfs(graph, visited, n);
        }
    }
    visited[v] = BLACK;
}

int count_ccs(vector<vector<int>> &graph, int v) {
    vector<int> visited;
    visited.resize(v);
    int ccs = 0;
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            ccs++;
            dfs(graph, visited, i);
        }
    }
    return ccs;
}

int main() {
    int p, c;
    while (cin >> p >> c && (p + c != 0)) {
        vector<vector<int>> graph;
        graph.resize(p);
        while (c--) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        int cc = count_ccs(graph, p);
        if (cc != 1 || has_bridge(graph, p)) cout << "Yes";
        else cout << "No";
        cout << endl;
    }
    return 0;
}