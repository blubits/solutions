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
    for (int i = 0; i < n; i++) {
        switch (i % 4) {
            case 0:
            case 1:
            cout << "a";
            continue;
            case 2:
            case 3:
            cout << "b";
            continue;
        }
    }
    cout << endl;
    return 0;
}