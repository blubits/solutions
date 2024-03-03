#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

vector<vi> graph;
vi lab, indegree1, indegree0;

int main() {
    int T;
    cin >> T;
    while (T--) {
        graph.clear();
        lab.clear();
        indegree1.clear();
        indegree0.clear();
        int n, m;
        cin >> n >> m;
        lab.resize(n);
        indegree1.resize(n);
        indegree0.resize(n);
        graph.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> lab[i];
            lab[i]--;
        }
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            graph[u].push_back(v);
            indegree1[v]++;
            indegree0[v]++;
        }
        int min0 = 0, min1 = 0;
        vector<queue<int>> q;
        q.resize(2);

        // try with lab 0
        for (int i = 0; i < n; i++) if (indegree0[i] == 0) q[lab[i]].push(i);
        int curr = 0;
        while (!(q[0].empty() && q[1].empty())) {
            while (!q[curr].empty()) {
                int u = q[curr].front(); q[curr].pop();
                for (auto &v: graph[u]) {
                    indegree0[v]--;
                    if (indegree0[v] == 0) {
                        q[lab[v]].push(v);
                    }
                }
            }
            curr = (curr == 0) ? 1 : 0;
            min0++;
        }

        // try with lab 1
        for (int i = 0; i < n; i++) if (indegree1[i] == 0) q[lab[i]].push(i);
        curr = 1;
        while (!(q[0].empty() && q[1].empty())) {
            while (!q[curr].empty()) {
                int u = q[curr].front(); q[curr].pop();
                for (auto &v: graph[u]) {
                    indegree1[v]--;
                    if (indegree1[v] == 0) q[lab[v]].push(v);
                }
            }
            curr = (curr == 0) ? 1 : 0;
            min1++;
        }

        cout << min(min0, min1) - 1 << endl;
    }
    return 0;
}