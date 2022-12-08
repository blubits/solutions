#include <bits/stdc++.h>
using namespace std;

int n1, n2, m1, m2;
vector<vector<int>> graph;
vector<int> uni1, uni2, kek, u1, u2;
vector<bool> sht;

void rec(int u) {
    for (int i : graph[u])
        if (!sht[i]) rec(i);
    uni1.push_back(u);
}

int main() {
    int u, v;
    scan("%d %d %d %d\n", &n1, &n2, &m1, &m2);
    graph.resize(n1);
    sht.resize(n1);
    kek.resize(n1);
    for (int i = 0; i != m1; ++i) {
        scanf("%d %d", &u, &v);
        graph[u - 1].push_back(v - 1);
    }
    rec(0);
    kek[0] = 1;
    for (int u : uni1)
        for (int v : graph[u]) kek[v] += kek[u];

    return 0;
}
