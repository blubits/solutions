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
    vi numbers(n);
    vector<bool> painted(n, false);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    sort(numbers.begin(), numbers.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!painted[i]) {
            painted[i] = true;
            ans++;
            for (int j = i + 1; j < n; j++) {
                if (numbers[j] % numbers[i] == 0) {
                    painted[j] = true;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}