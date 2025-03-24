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
    cout << 1 << endl;
    int response;
    while (cin >> response) {
        if (response > 98) break;
        // Keep odd.
        int answer = response + min(3 - response % 3, 2);
        cout << answer << endl;
        if (answer == 99) break;
    }
    return 0;
}