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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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
    //pq.emplace({0, 0});
    q[0].emplace(0);
    
    //while (!pq.empty()) {
    for (int d = 0; d <= T; d += q[d].empty()) {
        //auto [d, u] = pq.top(); pq.pop();
        if (q[d].empty()) continue;
        auto u = q[d].front(); q[d].pop();
        printf("d %d w/ vertex %d\n", d, u);
        if (dist[u] >= T + 1 || u == T) break;
        if (d > dist[u]) continue;
        for (auto &[s, w, i]: possible_moves) {
            int v = u + s;
            if (u <= T && s < 0) continue;
            if (v > max_possible_vertex) continue;
            if (dist[u] + w >= dist[v]) continue;
            if (dist[u] + w > T + 1) continue;
            dist[v] = dist[u] + w;
            parent[v] = u;
            edge[v] = i;
            //pq.emplace(dist[v], u + s);
            q[dist[u] + w].emplace(u + s);
            printf("d %d u %d: s %d w %d i %d enq {dist %d, vertex %d}\n", d, u, s, w, i, dist[v], u + s);
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
    printf("%d\n", val.size());
    while (!val.empty()) {
        printf("%d", val.top());
        val.pop();
        if (!val.empty()) printf(" ");
    }
    printf("\n");
    return 0;
}