#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & (-S))

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;
const int NINF = 0xcfcfcfcf;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-9;

int main() {
    int n, d;
    cin >> n >> d;
    vi hotels(n);
    for (int i = 0; i < n; i++) {
        cin >> hotels[i];
    }
    unordered_set<int> between;
    for (int i = 0; i < n; i++) {
        // d before
        int hotel_before = hotels[i] - d;
        if (i == 0 || abs(hotel_before - hotels[i - 1]) >= d) {
            between.insert(hotel_before);
        }
        // d after
        int hotel_after = hotels[i] + d;
        if (i == n - 1 || abs(hotel_after - hotels[i + 1]) >= d) {
            between.insert(hotel_after);
        }
    }
    cout << between.size() << endl;
    return 0;
}