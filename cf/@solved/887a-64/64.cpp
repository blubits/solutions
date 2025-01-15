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
    string s;
    cin >> s;
    // find the first 1
    int pos = -1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        cout << "no" << endl;
        return 0;
    }
    // count zeroes after 1
    int cnt = 0;
    for (int i = pos + 1; i < s.size(); i++) {
        if (s[i] == '0') cnt++;
    }
    if (cnt >= 6) cout << "yes" << endl;
    else cout << "no" << endl;
    return 0;
}