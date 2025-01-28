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
    bool fell[n] = {false};
    int curr_k = n - 1;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        fell[k - 1] = true;
        while (fell[curr_k]) {
            cout << curr_k + 1 << " ";
            curr_k--;
        }
        cout << endl;
    }
    return 0;
}