#include <bits/stdc++.h>
#define LSOne(S) ((S) & (-S))
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;
const int NINF = 0xcfcfcfcf;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-9;

int sure_c = 0, sure_f = 0;
int total = 0;

int min_votes[2017][2017];

vii swing_states;

int main() {
    memset(min_votes, INF, sizeof(min_votes));
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int d, c, f, u;
        cin >> d >> c >> f >> u;
        total += d;
        if (c + u <= f) {
            sure_f += d;
        } else if (f + u < c) {
            sure_c += d;
        } else {
            int req = ((c + u + f) / 2 + 1) - c;
            swing_states.push_back({d, req});
        }
    }
    if (2 * sure_f >= total) {
        cout << "impossible" << endl;
        return 0;
    } else if (2 * sure_c - 1 >= total) {
        cout << 0 << endl;
        return 0;
    }
    int needed = (total / 2 + 1) - sure_c;
    min_votes[0][0] = 0;
    for (int i = 1; i <= swing_states.size(); i++) {
        auto &[d, req] = swing_states[max(0, i - 1)];
        for (int j = 0; j <= total; j++) {
            if (j - d >= 0) {
                min_votes[i][j] = min(
                    min_votes[i - 1][j],
                    min_votes[i - 1][j - d] + req
                );
            } else {
                min_votes[i][j] = min_votes[i - 1][j];
            }
        }
    }
    int ans = INF;
    for (int i = needed; i <= total; i++) {
        ans = min(ans, min_votes[swing_states.size()][i]);
    }
    if (ans == INF) cout << "impossible" << endl;
    else cout << ans << endl;
    return 0;
}