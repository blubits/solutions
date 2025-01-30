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
    string fr, to, message;
    cin >> fr >> to >> message;
    map<char, char> mp;
    for (int i = 0; i < fr.size(); i++) {
        mp[fr[i]] = to[i];
    }
    for (auto c : message) {
        bool is_upper = isupper(c);
        c = tolower(c);
        if (mp.find(c) != mp.end()) {
            cout << char(is_upper ? toupper(mp[c]) : mp[c]);
        } else {
            cout << c;
        }
    }
    cout << endl;
    return 0;
}