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

int n, x;
int weights[20];

int trips[1 << 20];
int tripwt[1 << 20];

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> weights[i];
    trips[0] = 1;
    tripwt[0] = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        // initial
        trips[mask] = n + 1;
        tripwt[mask] = 0;
        int temp = mask;
        while (temp) {
            int two_pow_i = LSOne(temp);
            int i = __builtin_ctz(temp);
            int mask_minus_i = mask ^ two_pow_i;
            int best_trip = trips[mask_minus_i], best_tripwt = tripwt[mask_minus_i];
            if (tripwt[mask_minus_i] + weights[i] <= x) {
                best_tripwt += weights[i];
            } else {
                best_trip++;
                best_tripwt = weights[i];
            }
            if (trips[mask] > best_trip || (trips[mask] == best_trip && tripwt[mask] > best_tripwt)) {
                trips[mask] = best_trip;
                tripwt[mask] = best_tripwt;
            }
            temp -= two_pow_i;
        }
    }
    cout << trips[(1 << n) - 1] << endl;
    return 0;
}