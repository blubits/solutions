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
    int n;
    string S;
    cin >> n >> S;
    int s2f = 0, f2s = 0;
    for (int i = 0; i < n - 1; i++) {
        if (S[i] == 'F' && S[i+1] == 'S') f2s++;
        if (S[i] == 'S' && S[i+1] == 'F') s2f++;
    }
    if (s2f > f2s) cout << "YES";
    else cout << "NO";
    cout << endl;
    return 0;
}