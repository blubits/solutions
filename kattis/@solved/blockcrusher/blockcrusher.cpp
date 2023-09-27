#include <bits/stdc++.h>
#define INF 1e9
#define LLINF 4e18
using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int h, w;
int path[100][100];
map<ii, int> dist;
map<ii, ii> pred;

int ptoi(int i, int j) {
    return w * i + j;
}

ii itop(int k) {
    return {k / w, k % w};
}

void fracture_line() {
    set<pair<int, ii>> pq;
    dist[{-1, -1}] = 0;
    pq.emplace(make_pair(0, make_pair(-1, -1)));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            dist[{i, j}] = INF;
            pq.emplace(make_pair(INF, make_pair(i, j)));
        }
    }
    // for (auto &i: dist) {
    //     printf("origin to %d, %d: %d\n", i.first.first, i.first.second, i.second);
    // }
    while (!pq.empty()) {
        auto [d, u] = *pq.begin();
        pq.erase(pq.begin());
        if (u.first == -1 && u.second == -1) {
            for (int j = 0; j < w; j++) {
                ii v = {0, j};
                int wt = path[0][j];
                //printf("attempting to relax O->%d,%d from %d to %d (v%d)\n", v.first, v.second, dist[v], dist[u] + wt, wt);
                if (dist[u] + wt >= dist[v]) continue;
                pq.erase(pq.find({dist[v], v}));
                //printf("relaxing O->%d,%d from %d to %d (v%d)\n", v.first, v.second, dist[v], dist[u] + wt, wt);
                dist[v] = dist[u] + wt;
                pred[v] = u;
                pq.emplace(make_pair(dist[v], v));
            }
        } else {
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    ii v = {u.first + di, u.second + dj};
                    if (!(0 <= v.first && v.first < h) || !(0 <= v.second && v.second < w)) continue;
                    int wt = path[v.first][v.second];
                    if (dist[u] + wt >= dist[v]) continue;
                    pq.erase(pq.find({dist[v], v}));
                    dist[v] = dist[u] + wt;
                    pred[v] = u;
                    pq.emplace(make_pair(dist[v], v));
                }
            }
        }
    }
    
    int lowest = INF, li, lj;
    for (auto &i: dist) {
        //printf("ORIGIN->%d,%d: %d (pred %d, %d)\n", i.first.first, i.first.second, i.second, pred[i.first].first, pred[i.first].second);
        if (i.first.first == h - 1) {
            if (lowest > i.second) {
                lowest = i.second;
                li = i.first.first;
                lj = i.first.second;
            }
        }
    }
    while (li != -1 && lj != -1) {
        path[li][lj] = 11;
        int nli, nlj;
        nli = pred[{li, lj}].first;
        nlj = pred[{li, lj}].second;
        li = nli;
        lj = nlj;
    }
}

int main() {
    while (cin >> h >> w && !(h == 0 && w == 0)) {
        dist.clear();
        pred.clear();
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                scanf(" %c", &path[i][j]);
                path[i][j] = path[i][j] - '0';
            }
        }
        // for (int i = 0; i < h; i++) {
        //     for (int j = 0; j < w; j++) {
        //         printf("%d ", path[i][j]);
        //     }
        //     printf("\n");
        // } 
        // printf("\n");
        fracture_line();
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                printf("%c", path[i][j] != 11 ? char('0' + path[i][j]) : ' ');
            }
            printf("\n");
        } 
        printf("\n");
    }
    return 0;
}