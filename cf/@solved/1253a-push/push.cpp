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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) {
            int b;
            cin >> b;
            a[i] -= b;
        }
        a.insert(a.begin(), 0);
        a.push_back(0);
        int different = 0;
        for (int i = 0; i < n + 1; i++) {
            if (a[i] != a[i + 1]) different++;
            if (a[i] > 0) different = INF;
        }
        cout << (different <= 2 ? "YES" : "NO") << endl;
    }
    return 0;
}