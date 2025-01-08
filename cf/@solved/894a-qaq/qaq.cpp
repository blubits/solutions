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
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'Q')
            for (int j = i + 1; j < s.size(); j++) {
                if (s[j] == 'A')
                    for (int k = j + 1; k < s.size(); k++) {
                        if (s[k] == 'Q') ans++;
                    }
            }
    }
    cout << ans << endl;
    return 0;
}