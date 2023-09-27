#include <bits/stdc++.h>
#define INF 1e9
#define LLINF 4e18
using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int N, M;
map<string, int> beverages;
map<int, string> beverages_rev;
vi indegree;
vvi graph;

void toposort() {
    priority_queue<int, vi, greater<int>> pq;
    for (int u = 0; u < N; ++u) {
        if (indegree[u] == 0) pq.push(u);
    }
    while (!pq.empty()) {
        int u = pq.top(); pq.pop();
        cout << beverages_rev[u] << " ";
        for (auto &v : graph[u]) {
            --indegree[v];
            if (indegree[v] > 0) continue;
            pq.push(v);
        }
    }
}

int main() {
    int i = 0;
    while (cin >> N) {
        graph.clear();
        beverages.clear();
        for (int i = 0; i < N; i++) {
            string beverage;
            cin >> beverage;
            beverages[beverage] = i;
            beverages_rev[i] = beverage;
        }
        graph.resize(N);
        indegree.resize(N);
        cin >> M;
        for (int i = 0; i < M; i++) {
            string b1,  b2;
            cin >> b1 >> b2;
            graph[beverages[b1]].push_back(beverages[b2]);
            indegree[beverages[b2]]++;
        }
        printf("Case #%d: Dilbert should drink beverages in this order: ", ++i);
        toposort();
        cout << "." << endl;
    }
    return 0;
}