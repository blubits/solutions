#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

int x, y, t, l, w;
int visited[1010][1010];
bool is_wall[1010][1010];
int xl[110], yl[110];

int dirx[] = {0, 1, 0, -1};
int diry[] = {-1, 0, 1, 0};

queue<tuple<int, int, int>> sources;

int main() {
    while (cin >> x && x != -1) {
        cin >> y >> t >> l >> w;
        int ans = l;
        memset(visited, -1, sizeof(visited));
        memset(is_wall, 0, sizeof(is_wall));
        for (int i = 0; i < l; i++) {
            cin >> xl[i] >> yl[i];
            xl[i]--; yl[i]--;
            sources.push({xl[i], yl[i], 0});
            visited[xl[i]][yl[i]] = 0;
        }
        for (int i = 0; i < w; i++) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1--; y1--; x2--; y2--;
            if (x1 == x2) {
                for (int j = min(y1, y2); j <= max(y1, y2); j++) {
                    is_wall[x1][j] = true;
                }
            } else if (y1 == y2) {
                for (int j = min(x1, x2); j <= max(x1, x2); j++) {
                    is_wall[j][y1] = true;
                }
            } else {
                // determine if ldiag or rdiag
                if (x1 < x2 && y1 < y2 || x2 < x1 && y2 < y1) {
                    // +1 +1
                    if (x2 < x1) {
                        swap(x2, x1);
                        swap(y2, y1);
                    }
                    while (x1 != x2 && y1 != y2) {
                        is_wall[x1][y1] = true;
                        x1++;
                        y1++;
                    }
                    is_wall[x1][y1] = true;
                } else {
                    // +1 -1
                    if (x2 < x1) {
                        swap(x2, x1);
                        swap(y2, y1);
                    }
                    while (x1 != x2 && y1 != y2) {
                        is_wall[x1][y1] = true;
                        x1++;
                        y1--;
                    }
                    is_wall[x1][y1] = true;
                }
            }
        }
        while (!sources.empty()) {
            auto [xi, yi, wt] = sources.front(); sources.pop();
            if (wt == t - 1) continue;
            for (int i = 0; i < 4; i++) {
                int xn = xi + dirx[i], yn = yi + diry[i];
                if (!(0 <= xn && xn < x && 0 <= yn && yn < y)) continue;
                if ((visited[xn][yn] == -1) && !is_wall[xn][yn]) {
                    sources.push({xn, yn, wt + 1});
                    ans++;
                    visited[xn][yn] = wt + 1;
                }
            }
        }
        // for (int i = 0; i < x; i++) {
        //     for (int j = 0; j < y; j++) {
        //         if (is_wall[j][i]) cout << "#";
        //         else if (visited[j][i] == 0) cout << "L";
        //         else if (visited[j][i] == -1) cout << ".";
        //         else cout << visited[j][i] + 1;
        //     }
        //     cout << endl;
        // }
        cout << ans << endl;
    }
    return 0;
}