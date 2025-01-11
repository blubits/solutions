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
    string p1, p2;
    cin >> p1 >> p2;
    cout << p1 << " " << p2 << endl;
    int n;
    cin >> n;
    while (n--) {
        string murdered, replaced;
        cin >> murdered >> replaced;
        if (p1 == murdered) p1 = replaced;
        if (p2 == murdered) p2 = replaced;
        cout << p1 << " " << p2 << endl;
    }
    return 0;
}