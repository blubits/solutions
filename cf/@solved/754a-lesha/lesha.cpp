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
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum == 0 && n == 1) {
        cout << "NO" << endl;
    } else if (sum == 0) {
        int index_first_nonzero = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] != 0) {
                index_first_nonzero = i;
                break;
            }
        }
        if (index_first_nonzero == -1) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl << 2 << endl;
            cout << 1 << " " << index_first_nonzero + 1 << endl;
            cout << index_first_nonzero + 2 << " " << n << endl;
        }
    } else {
        cout << "YES" << endl << 1 << endl;
        cout << 1 << " " << n << endl;
    }
    return 0;
}