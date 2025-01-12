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
    int n, m;
    cin >> n >> m;
    int count[m + 1][5] = {0};
    for (int i = 0; i < n; i++) {
        string answers;
        cin >> answers;
        for (int j = 0; j < m; j++) {
            count[j][answers[j] - 'A']++;
        }
    }
    int ans = 0, price;
    for (int i = 0; i < m; i++) {
        cin >> price;
        ans += price * (*max_element(count[i], count[i] + 5));
    }
    cout << ans << endl;
    return 0;
}