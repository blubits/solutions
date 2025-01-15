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
    string s; int k;
    cin >> s >> k;
    set<char> chars;
    for (auto c : s) chars.insert(c);
    int uniq = chars.size();
    if (s.size() < k) cout << "impossible" << endl;
    else cout << max(0, k - uniq) << endl;
    return 0;
}