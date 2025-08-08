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

char sh[100][100];

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> sh[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (sh[i][j] == 'S') {
                int ans_spy = INF;
                for (int ii = 0; ii < N; ii++) {
                    for (int jj = 0; jj < N; jj++) {
                        if (sh[ii][jj] == 'H') {
                            ans_spy = min(ans_spy, abs(i - ii) + abs(j - jj));
                        }
                    }
                }
                ans = max(ans, ans_spy);
            }
        }
    }
    cout << ans << endl;
    return 0;
}