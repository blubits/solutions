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
    cin >> n;
    vector<long long> remaining(n), capacity(n);
    for (int i = 0; i < n; i++) {
        cin >> remaining[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> capacity[i];
    }
    sort(remaining.begin(), remaining.end());
    sort(capacity.begin(), capacity.end());
    ll sum_remaining = 0;
    for (int i = 0; i < n; i++) {
        sum_remaining += remaining[i];
    }
    ll top_two_capacity = capacity[n - 1] + capacity[n - 2];
    if (sum_remaining <= top_two_capacity) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}