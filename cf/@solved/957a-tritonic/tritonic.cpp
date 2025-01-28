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
    int t;
    cin >> t;
    string canvas;
    cin >> canvas;
    // check for two successive 
    for (int i = 0; i < t - 1; i++) {
        if (canvas[i] == canvas[i + 1]) {
            if (canvas[i] != '?') {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    for (int i = 0; i < t - 1; i++) {
        if (canvas[i] == canvas[i + 1]) {
            if (canvas[i] == '?') {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    // check for '?' on borders
    if (canvas[0] == '?' || canvas[t - 1] == '?') {
        cout << "YES" << endl;
        return 0;
    }
    // check for '?' between two of the same color
    for (int i = 1; i < t - 1; i++) {
        if (canvas[i] == '?' && canvas[i - 1] == canvas[i + 1]) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}