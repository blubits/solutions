#include <bits/stdc++.h>
#define LSOne(S) ((S) & (-S))
using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;
const int NINF = 0xcfcfcfcf;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-9;

ll dist(ii a, ii b) {
    int x = b.first - a.first;
    int y = b.second - a.second;
    return x*x + y*y;
}

// md[i][j][k]:
// min distance to go to all cows up to ith H and jth G
// given that i'm currently at
// k = 0: ith H
// k = 1: jth G
ll min_dist[1010][1010][2];

vii hcows, gcows;

int main() {
    freopen("checklist.in", "r", stdin);
	freopen("checklist.out", "w", stdout);
    int H, G;
    cin >> H >> G;
    for (int i = 0; i < H; i++) {
        int x, y;
        cin >> x >> y;
        hcows.push_back({x, y});
    }
    for (int i = 0; i < G; i++) {
        int x, y;
        cin >> x >> y;
        gcows.push_back({x, y});
    }
    fill(&min_dist[0][0][0], &min_dist[0][0][0] + (1010 * 1010 * 2), 1e18);
    min_dist[1][0][0] = 0;   // tour start
    for (int i = 0; i <= H; i++) {
        for (int j = 0; j <= G; j++) {
            if (i > 1) {
                // h->h
                min_dist[i][j][0] = min(
                    min_dist[i][j][0],
                    min_dist[i - 1][j][0] + dist(hcows[i - 2], hcows[i - 1])
                );
            }
            if (j > 1) {
                // g->g
                min_dist[i][j][1] = min(
                    min_dist[i][j][1],
                    min_dist[i][j - 1][1] + dist(gcows[j - 2], gcows[j - 1])
                );
            }
            if (i > 0 && j > 0) {
                // g->h
                min_dist[i][j][0] = min(
                    min_dist[i][j][0],
                    min_dist[i - 1][j][1] + dist(gcows[j - 1], hcows[i - 1])
                );
                // h->g
                min_dist[i][j][1] = min(
                    min_dist[i][j][1],
                    min_dist[i][j - 1][0] + dist(hcows[i - 1], gcows[j - 1])
                );
            }
        }
    }
    cout << min_dist[H][G][0] << endl;
    return 0;
}