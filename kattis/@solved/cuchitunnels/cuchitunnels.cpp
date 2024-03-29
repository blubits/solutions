#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

int N;
int total = 0;
int target[1010];
int actual[1010];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> target[i];
    }
    // attempt to construct the tree
    // attach each non-root node to the least-numbered node
    // that has not made its degree target
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (actual[j] < target[j]) {
                actual[i]++;
                actual[j]++;
                break;
            }
        }
    }
    bool possible = true;
    for (int i = 0; i < N; i++) {
        if (target[i] != actual[i]) {
            possible = false;
            break;
        }
    }
    if (possible) cout << "YES";
    else cout << "NO";
    cout << endl;
}