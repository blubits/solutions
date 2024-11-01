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
    unordered_set<int> A, B;
    int n, m;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        A.insert(a);
    }
    cin >> m;
    while (m--) {
        int b;
        cin >> b;
        B.insert(b);
    }
    for (auto a: A) {
        for (auto b: B) {
            if (A.count(a + b) == 0 && B.count(a + b) == 0) {
                cout << a << " " << b << endl;
                return 0;
            }
        }
    }
    return 0;
}