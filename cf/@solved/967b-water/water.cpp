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
    int n;
    ll A, B;
    cin >> n >> A >> B;
    ll first_hole, sum_holes = 0;
    vector<ll> holes(n - 1);
    cin >> first_hole;
    for (int i = 0; i < n - 1; i++) {
        cin >> holes[i];
        sum_holes += holes[i];
    }
    sum_holes += first_hole;
    sort(holes.begin(), holes.end());
    // (s1)(A)/sum(holes) >= B => s1A >= B*sum(holes)
    int ans = 0;
    while (first_hole * A < B * sum_holes) {
        ans++;
        sum_holes -= holes.back();
        holes.pop_back();
    }
    cout << ans << endl;
    return 0;
}