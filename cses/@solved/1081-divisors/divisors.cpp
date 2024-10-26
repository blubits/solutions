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

int divisors[1000001];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        const int lim = int(sqrt(a));
        for (int d = 1; d <= lim; d++) {
            if (a % d == 0) {
                divisors[d]++;
                if (d != a / d) divisors[a / d]++;
            }
        }
    }        
    for (int i = 1000000; i >= 1; i--) {
        if (divisors[i] >= 2) {
            cout << i << endl;    
            break;
        } 
    }
    return 0;
}