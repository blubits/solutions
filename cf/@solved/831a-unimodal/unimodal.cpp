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
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // Find increasing part at start of array
    int start = 0;
    while (start < n - 1 && a[start] < a[start + 1]) {
        start++;
    }
    // Find decreasing part at end of array
    int end = n - 1;
    while (end > 0 && a[end] < a[end - 1]) {
        end--;
    }
    for (int i = start + 1; i <= end; i++) {
        if (a[start] != a[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}