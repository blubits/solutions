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
    while (n--) {
        int a, b;
        cin >> a >> b;
        int target = abs(a - b);
        int fives = target / 5;
        switch (target % 5) {
            case 0: 
                cout << fives << endl; break;
            case 1:
            case 2:
                cout << fives + 1 << endl; break;
            case 3:
            case 4:
                cout << fives + 2 << endl; break;
        }
    }
    return 0;
}