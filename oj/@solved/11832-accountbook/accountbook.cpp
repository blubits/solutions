#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

int N, F;

int memo[45][90000];
int items[45];

int canplus[45];
int canminus[45];

int dp(int item, int value) {
    if (item == N && value == F) return 1;
    if (item == N && value != F) return 0;
    if (memo[item][value] != -1) return memo[item][value];
    int minus = dp(item + 1, value - items[item]);
    int plus = dp(item + 1, value + items[item]);
    if (minus) canminus[item] = 1;
    if (plus) canplus[item] = 1;
    return memo[item][value] = minus | plus;
}

int main() {
    while (cin >> N >> F && !(N == 0 && F == 0)) {
        F += 40000;
        for (int i = 0; i < N; i++) cin >> items[i];
        memset(memo, -1, sizeof memo);
        memset(canminus, 0, sizeof canminus);
        memset(canplus, 0, sizeof canplus);
        if (dp(0, 40000)) {
            for (int i = 0; i < N; i++) {
                if (canminus[i] && canplus[i]) cout << "?";
                else if (canminus[i]) cout << "-";
                else if (canplus[i]) cout << "+";
            }
            cout << endl;
        } else {
            cout << "*" << endl;
        }
    }
    return 0;
}