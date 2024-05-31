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

int dp[1010][1010];
vi bl, br;
int main() {
    freopen("nocross.in", "r", stdin);
	freopen("nocross.out", "w", stdout);
    int N;
    cin >> N;
    bl.resize(N);
    br.resize(N);
    for (int i = 0; i < N; i++) cin >> bl[i];
    for (int i = 0; i < N; i++) cin >> br[i];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = max({
                dp[i - 1][j],
                dp[i][j - 1],
                dp[i - 1][j - 1] + (abs(bl[i - 1] - br[j - 1]) <= 4 ? 1 : 0)
            });
        }
    }
    cout << dp[N][N] << endl;
    return 0;
}