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
    map<char, int> freq;
    for (char c : s) freq[c]++;
    // count number of ways you can make 'Bulbasaur' based on frequency
    int ans = INF;
    ans = min(ans, freq['B']);
    ans = min(ans, freq['u'] / 2);
    ans = min(ans, freq['l']);
    ans = min(ans, freq['b']);
    ans = min(ans, freq['a'] / 2);
    ans = min(ans, freq['s']);
    ans = min(ans, freq['r']);
    cout << ans << endl;
    return 0;
}