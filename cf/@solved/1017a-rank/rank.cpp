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

int main() {
    int n;
    cin >> n;
    vii scores;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        scores.push_back({a + b + c + d, -i});
    }
    sort(scores.begin(), scores.end());
    for (int i = 0; i < n; i++) {
        if (scores[scores.size() - 1 - i].second == 0) {
            cout << i + 1 << endl;
            break;
        }
    }
    return 0;
}