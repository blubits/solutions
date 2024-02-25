#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

int n, k;

int hop[110][110];
int ans[110][110]; // maximum collected if you end at (i, j)

int answer(int i, int j) {
    if (ans[i][j] != -1) return ans[i][j];
    int i1 = max(0, i - k), i2 = min(i + k, n - 1);
    int j1 = max(0, j - k), j2 = min(j + k, n - 1);
    int sol = 0;
    for (int a = i1; a <= i2; a++) {
        if (hop[a][j] > hop[i][j]) sol = max(sol, answer(a, j));
    }
    for (int b = j1; b <= j2; b++) {
        if (hop[i][b] > hop[i][j]) sol = max(sol, answer(i, b));
    }
    sol += hop[i][j];
    ans[i][j] = sol;
    return sol;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        memset(ans, -1, sizeof(ans));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &hop[i][j]);
            }
        }
        printf("%d\n", answer(0, 0));
        if (T) printf("\n");
    }
    return 0;
}