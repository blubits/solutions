#include <bits/stdc++.h>
#define INF 1e9
#define LLINF 4e18
using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

vector<char> values;
vi ts;
vi sources;
vvi graph;
vi indegree;
int idx;

int longest_path[30];
int num_paths[30];

void toposort() {
    priority_queue<int, vi, greater<int>> pq;
    for (int u = 0; u < indegree.size(); ++u)
        if (indegree[u] == 0) {
            pq.push(u);
            sources.push_back(u);
        }
    while (!pq.empty()) {
        int u = pq.top(); pq.pop();
        ts.push_back(u);
        for (auto &v : graph[u]) {
            --indegree[v];
            if (indegree[v] > 0) continue;
            pq.push(v);
        }
    }
}

void dp() {
    memset(longest_path, -1, sizeof longest_path);
    for (auto s: sources) {
        longest_path[s] = 0;
        num_paths[s] = 1;
    }
    for (auto u: ts) {
        for (auto v: graph[u]) {
            if (longest_path[v] < longest_path[u] + 1) {
                longest_path[v] = longest_path[u] + 1;
                num_paths[v] = num_paths[u];
            } else if (longest_path[v] == longest_path[u] + 1) {
                num_paths[v] += num_paths[u];
            }
        }
    }
    int lp = -1, cp = 0;
    for (int i = 0; i < 30; i++) {
        if (lp < longest_path[i]) {
            lp = longest_path[i];
            cp = num_paths[i];
        } else if (lp == longest_path[i]) {
            cp += num_paths[i];
        }
    }
   printf("%d %d\n", lp + 1, cp);
}

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        idx = 0;
        values.clear();
        graph.clear();
        indegree.clear();
        ts.clear();
        sources.clear();
        string line;
        getline(cin, line);
        for (char c: line) {
            if ('A' <= c && c <= 'Z') {
                if (count(values.begin(), values.end(), c) == 0) values.push_back(c);
            }
        }
        graph.resize(values.size());
        indegree.resize(values.size());
        for (int i = 0; i < values.size(); i++) {
            for (int j = 0; j < values.size(); j++) {
                if (i == j) continue;
                int ival = int(values[i] - 'A' + 1), jval = int(values[j] - 'A' + 1);
                if (5 * ival <= 4 * jval) {
                    graph[i].push_back(j);
                    indegree[j]++;
                }
            }
        }
        toposort();
        dp();
        // for (int i = 0; i < ts.size(); i++) {
        //     int vtx = ts[i];
        //     printf("%c (sp %d, np %d):", values[vtx], longest_path[vtx], num_paths[vtx]);
        //     for (int j = 0; j < graph[vtx].size(); j++) {
        //         printf(" %c", values[graph[vtx][j]]);
        //     }
        //     printf("\n");
        // }
    }
    return 0;
}