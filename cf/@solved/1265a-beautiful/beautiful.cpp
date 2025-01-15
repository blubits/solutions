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
    while (n--) {
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '?') continue;
            char prev = i == 0 ? '0' : s[i - 1];
            char next = i == s.size() - 1 ? '1' : s[i + 1];
            for (char c = 'a'; c <= 'c'; c++) {
                if (c == prev || c == next) continue;
                s[i] = c;
                break;
            }
        }
        bool beautiful = true;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == s[i + 1]) {
                beautiful = false;
                break;
            }
        }
        if (beautiful) cout << s << endl;
        else cout << -1 << endl;
    }
    return 0;
}