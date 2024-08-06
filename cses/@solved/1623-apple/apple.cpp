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

vector<int> apples;

int main() {
    int N;
    ll sum = 0;
    cin >> N;
    apples.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> apples[i];
        sum += apples[i];
    }
    ll ans = LLINF;
    for (int mask = 0; mask < (1 << N); mask++) {
        ll subset_sum = 0;
        int temp_mask = mask;
        while (temp_mask) {
            int two_pow_i = LSOne(temp_mask);
            int i = __builtin_ctz(two_pow_i);
            subset_sum += apples[i];
            temp_mask -= two_pow_i;
        }
        ll other_subset_sum = sum - subset_sum;
        ans = min(ans, abs(subset_sum - other_subset_sum));
    }
    cout << ans << endl;
    return 0;
}