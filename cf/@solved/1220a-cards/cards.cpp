#include <bits/stdc++.h>
#define LSOne(S) ((S) & (-S))
using namespace std;

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
    int N;
    string s;
    cin >> N >> s;
    int z = 0, n = 0;
    for (auto c: s) {
        switch (c) {
            case 'z': z++; break;
            case 'n': n++; break;
        }
    }
    for (int i = 0; i < n; i++) cout << 1 << " ";
    for (int i = 0; i < z; i++) cout << 0 << " ";
    cout << endl;
    return 0;
}