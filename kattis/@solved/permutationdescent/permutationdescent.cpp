#include <bits/stdc++.h>
#define MOD 1001113
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

ll memo[110][110];

ll dp(int n, int v) {
    if (v == 0 || v == n - 1) return 1; // strictly inc/dec permutation
    if (memo[n][v] != -1) return memo[n][v];
    
    /**
     * We observe two things:
     * 1. Each pair of successive numbers in a permutation is either an ascent or a descent.
     *    (There are maximum n - 1 descents because there are a maximum of n - 1 pairs.)
     * 2. For an n-permutation, we can add a new number into n + 1 slots:
     *    v v v v v
     *     X X X X  <- For example, there are 5 slots where we can insert 5 into this 4-permutation.
     * 3. N is greater than any of these values. For example, if you place 5 at the start of a
     *    4-permutation it will automatically create a descent.
     * 
     * Let's try to mark the ascents and descents in a random permutation:
     * 5 6 2 4 7 1 3
     * X D D X D D X -> 2 descents, representing dp(7, 2)
     * Make this an 8-permutation. There are 8 slots where we can place 8:
     * _ 5 _ 6 _ 2 _ 4 _ 7 _ 1 _ 3 _
     *       D   D       D   D
     * 1   1   2   1   1   2   1   3 
     * 
     * Case 1. A descent is added by placing the new value either at the start of the list
     *         or before any number that is not the second in a descent pair.
     * Case 2. A descent is replaced (i.e. the pair changes but the total count does not)
     *         when we insert the new number between two descents. This accounts * v, since v
     *         is the number of descents. (Why? D D => D 8 D => 8 D is the new descent, D 8 is not) 
     * Case 3. No descent is added when we insert the new number at the end. This accounts * 1.
     * 
     * Therefore: (v + 1) * dp(n - 1, v) (no descent is added)
     *            + (n - v) * dp(n - 1, v - 1) (a descent is added).
     */

    ll ans = 0;
    ans += (v + 1) * dp(n - 1, v);
    ans %= MOD;
    ans += (n - v) * dp(n - 1, v - 1);
    ans %= MOD;
    memo[n][v] = ans;
    return ans;
}

int main() {
    memset(memo, ll(-1), sizeof(memo));
    int T;
    cin >> T;
    while (T--) {
        int k, n, v;
        cin >> k >> n >> v;
        cout << k << " " << dp(n, v) << endl;
    }
    return 0;
}