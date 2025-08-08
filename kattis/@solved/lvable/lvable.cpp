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
    string s;
    cin >> s;
    if (s.find("lv") != string::npos) {
        cout << 0 << endl;
    } else if (s.find("l") != string::npos) {
        cout << 1 << endl;
    } else if (s.find("v") != string::npos) {
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
    }
    return 0;
}