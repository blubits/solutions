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

vector<int> A(5);

bool calculate(int i, int ans) {
    if (i == A.size() - 1) {
        if (ans == 23) return true;
        else return false;
    }
    return calculate(i + 1, ans + A[i + 1]) 
        || calculate(i + 1, ans - A[i + 1]) 
        || calculate(i + 1, ans * A[i + 1]);
}

int main() {
    while (cin >> A[0] >> A[1] >> A[2] >> A[3] >> A[4] &&
           !(A[0] + A[1] + A[2] + A[3] + A[4] == 0)) {
        bool possible = false;
        sort(A.begin(), A.end());
        do {
            possible |= calculate(0, A[0]);
        } while (!possible && next_permutation(A.begin(), A.end()));
        if (possible) cout << "Possible";
        else cout << "Impossible";
        cout << endl;
    }
    return 0;
}