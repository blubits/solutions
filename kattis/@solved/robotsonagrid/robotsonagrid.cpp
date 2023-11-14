#include <bits/stdc++.h>
#define MOD 2147483647
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

int n;

char graph[1001][1001];
bool visited[1001][1001];
ll num_paths[1001][1001];

bool has_path(int i, int j) {
    if (i == n - 1 && j == n - 1) return true;
    if (i < 0 || i >= n || j < 0 || j >= n) return false;
    if (visited[i][j]) return false;
    if (graph[i][j] == '#') return false;
    visited[i][j] = true;
    return has_path(i - 1, j) | has_path(i, j - 1) | has_path(i + 1, j) | has_path(i, j + 1);
}

int main() {
    scanf("%d ", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%c ", &graph[i][j]);
        }
    }
    if (!has_path(0, 0)) {
        printf("INCONCEIVABLE\n");
    } else {
        memset(num_paths, 0, sizeof(num_paths));
        num_paths[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j] == '#') continue;
                if (i != n - 1 && graph[i + 1][j] != '#') num_paths[i + 1][j] += (num_paths[i][j] % MOD);
                if (j != n - 1 && graph[i][j + 1] != '#') num_paths[i][j + 1] += (num_paths[i][j] % MOD);
                num_paths[i + 1][j] %= MOD;
                num_paths[i][j + 1] %= MOD;
            }
        }
        if (num_paths[n - 1][n - 1]) printf("%d\n", num_paths[n - 1][n - 1]);
        else printf("THE GAME IS A LIE\n");
    }
    return 0;
}