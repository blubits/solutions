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

int K = 0, E = 1, Y = 2;

vector<vi> posns(3, vi());
vector<vi> pcnt(30, vi(3, 0));

// KKEEYY
ll dp[436][31][31][31];

int main() {
    memset(dp, 0, sizeof(dp));
    string S;
    int nswaps;
    cin >> S >> nswaps;

    pcnt[0][(S[0] == 'K' ? 0 : (S[0] == 'E' ? 1 : 2))] = 1;
    for (int i = 0; i < S.size(); i++) {
        if (i != 0) {
            pcnt[i][0] = pcnt[i - 1][0] + (S[i] == 'K' ? 1 : 0);
            pcnt[i][1] = pcnt[i - 1][1] + (S[i] == 'E' ? 1 : 0);
            pcnt[i][2] = pcnt[i - 1][2] + (S[i] == 'Y' ? 1 : 0);
        } 
        switch (S[i]) {
            case 'K':
                posns[0].push_back(i); break;
            case 'E':
                posns[1].push_back(i); break;
            case 'Y':
                posns[2].push_back(i); break;
            default:
            break;
        }
    }
    ll ans = 0;
    dp[0][0][0][0] = 1;
    for (int k = 0; k <= posns[0].size(); k++) {
        for (int e = 0; e <= posns[1].size(); e++) {
            for (int y = 0; y <= posns[2].size(); y++) {
                for (int sw = 0; sw <= 435; sw++) {
                    if (k != posns[0].size()) {
                        int pos_k = posns[0][k];
                        int nswaps_k = max(0, pcnt[pos_k][1] - e) + max(0, pcnt[pos_k][2] - y);
                        if (sw + nswaps_k <= 435) {
                            dp[sw + nswaps_k][k + 1][e][y] += dp[sw][k][e][y];
                        }
                    }
                    if (e != posns[1].size()) {
                        int pos_e = posns[1][e];
                        int nswaps_e = max(0, pcnt[pos_e][0] - k) + max(0, pcnt[pos_e][2] - y);
                        if (sw + nswaps_e <= 435) {
                            dp[sw + nswaps_e][k][e + 1][y] += dp[sw][k][e][y];
                        }
                    }
                    if (y != posns[2].size()) {
                        int pos_y = posns[2][y];
                        int nswaps_y = max(0, pcnt[pos_y][0] - k) + max(0, pcnt[pos_y][1] - e);
                        if (sw + nswaps_y <= 435) {
                            dp[sw + nswaps_y][k][e][y + 1] += dp[sw][k][e][y];
                        }
                    }
                    if ((k + e + y) == S.size() && sw <= nswaps) {
                        ans += dp[sw][k][e][y];
                    }
                }
            }
        }
    }
    cout << ans << endl;
}