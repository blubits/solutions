#include <bits/stdc++.h>
#define LSOne(S) ((S) & -(S))
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

int c = 0;
int N;
string name[20];
int x[20], y[20];
double dist[20][20];

double memo[70000];

double dp(int mask) {
    //cout << bitset<10>(mask) << endl;
    if (mask == 0) return 0;
    double &ans = memo[mask];
    if (ans != -1) return ans;
    ans = INF;
    int temp = mask;
    while (temp) {
        // pick i
        int two_pow_i = LSOne(temp);
        int i = __builtin_ctz(two_pow_i);
        int mask_no_i = temp - two_pow_i;
        // pick j
        while (mask_no_i) {
            int two_pow_j = LSOne(mask_no_i);
            int j = __builtin_ctz(two_pow_j);
            ans = min(
                ans,
                dp(mask ^ (two_pow_i | two_pow_j)) + dist[i][j]
            );
            mask_no_i -= two_pow_j;
        }
        temp -= two_pow_i;
    }
    return ans;
}

int main() {
    while (cin >> N && N) {
        for (int i = 0; i < 2 * N; i++) {
            cin >> name[i] >> x[i] >> y[i];
        }
        for (int i = 0; i < 2 * N; i++) {
            for (int j = 0; j < 2 * N; j++) {
                dist[i][j] = hypot(double(x[j] - x[i]), double(y[j] - y[i]));
            }
        }
        fill_n(memo, 70000, -1);
        cout << "Case " << ++c << ": " << fixed << setprecision(2) << dp((1 << (2 * N)) - 1) << endl;
    }
    return 0;
}