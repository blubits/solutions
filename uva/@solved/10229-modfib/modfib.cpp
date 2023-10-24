#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

const int MAX_N = 2;
struct Matrix { ll mat[MAX_N][MAX_N]; };

ll MOD;

ll mod(ll a, ll m) { return ((a % m) + m) % m; }

Matrix mmul(Matrix A, Matrix B) {
    Matrix C;
    memset(C.mat, 0, sizeof(C.mat));
    for (int i = 0; i < MAX_N; i++) {
        for (int k = 0; k < MAX_N; k++) {
            if (A.mat[i][k] == 0) continue;
            for (int j = 0; j < MAX_N; j++) {
                C.mat[i][j] += mod(A.mat[i][k], MOD) * mod(B.mat[k][j], MOD);
                C.mat[i][j] = mod(C.mat[i][j], MOD);
            }
        }
    }
    return C;
}

Matrix mpow(Matrix M, int p) {
    Matrix ans;
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            ans.mat[i][j] = (i == j);
        }
    }
    while (p) {
        if (p & 1) {
            ans = mmul(ans, M);
        }
        M = mmul(M, M);
        p >>= 1;
    }
    return ans;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        MOD = 1 << m;
        Matrix fib;
        fib.mat[0][0] = fib.mat[0][1] = fib.mat[1][0] = 1;
        fib.mat[1][1] = 0;
        fib = mpow(fib, n);
        cout << fib.mat[0][1] << endl;
    }
    return 0;
}
