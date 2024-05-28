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

map<char, ii> directions = {
    {'N', {0, 1}}, {'E', {1, 0}}, {'S', {0, -1}}, {'W', {-1, 0}}};
int dp[1010][1010];
vii fposn, bposn;

int dist(ii a, ii b) {
    return (a.first - b.first) * (a.first - b.first) +
           (a.second - b.second) * (a.second - b.second);
}

int main() {
    freopen("radio.in", "r", stdin);
	freopen("radio.out", "w", stdout);
    int N, M;
    int fx, fy, bx, by;
    string fs, bs;
    cin >> N >> M;
    cin >> fx >> fy >> bx >> by >> fs >> bs;
    fposn.push_back({fx, fy});
    bposn.push_back({bx, by});
    for (auto fd : fs) {
        fx += directions[fd].first;
        fy += directions[fd].second;
        fposn.push_back({fx, fy});
    }
    for (auto bd : bs) {
        bx += directions[bd].first;
        by += directions[bd].second;
        bposn.push_back({bx, by});
    }
    memset(dp, INF, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            int d = dist(fposn[i], bposn[j]);
            if (i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j] + d);
            if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j - 1] + d);
            if (i > 0 && j > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + d);
        }
    }
    cout << dp[N][M] << endl;
    return 0;
}