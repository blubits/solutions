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

bool starts_with(string s, string t) {
    for (int i = 0; i < t.size(); i++) {
        if (s[i] != t[i]) return false;
    }
    return true;
}

bool ends_with(string s, string t) {
    for (int i = 0; i < t.size(); i++) {
        if (s[s.size() - 1 - i] != t[t.size() - 1 - i]) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    string seating;
    cin >> seating;
    bool is_maximal =
        (seating.find("000") == string::npos) &&
        (seating.find("11") == string::npos) && !starts_with(seating, "00") &&
        !ends_with(seating, "00");
    if (seating.size() == 1) is_maximal = (seating[0] == '1');
    if (is_maximal) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}