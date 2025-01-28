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
    map<char, int> ctr;
    ctr[s[0]] = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] < s[i - 1]) {
            cout << "NO" << endl;
            return 0;
        }
        ctr[s[i]]++;
    }
    if (ctr['a'] >= 1 && ctr['b'] >= 1 && (ctr['c'] == ctr['a'] || ctr['c'] == ctr['b'])) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << endl;
    return 0;
}