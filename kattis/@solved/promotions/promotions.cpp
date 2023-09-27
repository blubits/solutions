#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;

int main() {
    int a, b, e, p;
    cin >> a >> b >> e >> p;
    graph.extend(e);
    for (int i = 0; i < p; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
}