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
    int x, hh, mm;
    cin >> x >> hh >> mm;
    int a = 0;
    while (true) {
        // Check if hh:mm has a 7.
        if (hh % 10 == 7 || mm % 10 == 7) {
            cout << a << endl;
            return 0;
        }
        mm -= x;
        if (mm < 0) {
            mm += 60;
            hh--;
        }
        if (hh < 0) {
            hh += 24;
        }
        a++;
    }
    return 0;
}