#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

vector<tuple<int, int, int>> possible_moves;
int min_cheer = 0;

int dist[400010], parent[400010], edge[400010];

vector<queue<int>> q;

int main() {
    int N, T;
    scanf("%d %d", &N, &T);
    possible_moves.push_back({1, 1, 1});
    for (int i = 0; i < N; i++) {
        int s, d;
        scanf("%d %d", &s, &d);
        possible_moves.push_back({s, d, i + 2});
        min_cheer = min(min_cheer, s);
    }
    int max_possible_vertex = T - min_cheer;
    // for (auto &[s, d, i]: possible_moves) {
    //     printf("%d %d %d\n", s, d, i);
    // }

    // djikstras prototype 1
    //priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<tuple<int, int>>> pq;
    q.resize(T + 10);
    dist[0] = 0;
    parent[0] = -1;
    edge[0] = -1;
    for (int i = 1; i <= max_possible_vertex; i++) {
        dist[i] = INF;
        parent[i] = -1;
        edge[i] = -1;
    }
    q[0].emplace(0);
    
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        cout << d << " " << u << endl;
        if (d > dist[u]) continue;
        for (auto &[s, w, i]: possible_moves) {
            if (u <= T && s < 0) continue;
            if (u + s > max_possible_vertex) continue;
            if (dist[u] + w >= dist[u + s]) continue;
            dist[u + s] = dist[u] + w;
            parent[u + s] = u;
            edge[u + s] = i;
            pq.emplace(dist[u + s], u + s);
            printf("d %d u %d: s %d w %d i %d enq {dist %d, vertex %d}\n", d, u, s, w, i, dist[u + s], u + s);
        }
    }

    // for (int i = 0; i <= max_possible_vertex; i++) {
    //     cout << i << "\t";
    //     if (dist[i] == INF) cout << "I\t";
    //     else cout << dist[i] << "\t";
    //     if (parent[i] == -1) cout << ".\t";
    //     else cout << parent[i] << "\t";
    //     if (edge[i] == -1) cout << ".\t";
    //     else cout << edge[i] << "\t";
    //     cout << endl;
    // }
    // cout << endl;

    stack<int> val;
    int curr_vertex = T;
    while (curr_vertex != -1) {
        if (edge[curr_vertex] != -1) val.push(edge[curr_vertex]);
        curr_vertex = parent[curr_vertex];
    }
    cout << val.size() << endl;
    while (!val.empty()) {
        cout << val.top();
        val.pop();
        if (!val.empty()) cout << " ";
    }

    return 0;
}