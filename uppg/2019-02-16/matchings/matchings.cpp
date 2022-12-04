#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int rw, rh, uw, uh;
    scanf("%d %d", &rw, &rh);
    int robot[rh][rw];
    for (int i = 0; i < rh; i++) {
        for (int j = 0; j < rw; j++) {
            scanf("%d", &robot[i][j]);
        }
    }
    scanf("%d %d", &uw, &uh);
    int uni[uh][uw];
    for (int i = 0; i < uh; i++) {
        for (int j = 0; j < uw; j++) {
            scanf("%d", &uni[i][j]);
        }
    }
    vector<pair<int, int>> candidates;
    int max_eq = -1;
    for (int i = 0; i <= uh - rh; i++) {
        for (int j = 0; j <= uw - rw; j++) {
            // attempt search
            int eq = 0;
            for (int a = 0; a < rh; a++) {
                for (int b = 0; b < rw; b++) {
                    if (robot[a][b] == uni[i + a][j + b]) {
                        eq++;
                    }
                }
            }
            if (eq > max_eq) {
                max_eq = eq;
                candidates.clear();
                candidates.push_back({i, j});
            } else if (eq == max_eq) {
                candidates.push_back({i, j});
            }
        }
    }
    sort(candidates.begin(), candidates.end());
    for (auto p : candidates) printf("%d %d\n", p.first, p.second);
    return 0;
}
