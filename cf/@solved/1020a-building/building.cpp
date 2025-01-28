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
    int n, h, a, b, k;
    cin >> n >> h >> a >> b >> k;
    for (int i = 0; i < k; i++) {
        int ta, fa, tb, fb;
        cin >> ta >> fa >> tb >> fb;
        if (ta == tb) {
            cout << abs(fa - fb) << endl;
        } else {
            // Step 1: Go to a floor where I can switch buildings.
            int step1, floor;
            if (a <= fa && fa <= b) {
                step1 = 0;
                floor = fa;
            }
            else {
                step1 = min(abs(a - fa), abs(b - fa));
                floor = abs(a - fa) > abs(b - fa) ? b : a;
            }
            // Step 2: Switch buildings.
            int step2 = abs(ta - tb);
            // Step 3: Go to the correct floor in building B.
            int step3 = abs(floor - fb);
            cout << step1 + step2 + step3 << endl;
        }
    }
    return 0;
}