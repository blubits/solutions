#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

vector<vi> partners;
vi neighbors_start;
vi neighbors_left;
vi has_left;
queue<int> chain;

int main() {
    int C, P, X, L;
    cin >> C >> P >> X >> L;
    X--; L--;
    partners.resize(C);
    neighbors_start.resize(C);
    neighbors_left.resize(C);
    has_left.resize(C);
    for (int i = 0; i < P; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        partners[u].push_back(v); partners[v].push_back(u);
        neighbors_start[u]++; neighbors_start[v]++;
        neighbors_left[u]++; neighbors_left[v]++;
        has_left[u] = false;
        has_left[v] = false;
    }
    for (int i = 0; i < C; i++) {
        cout << i << ": ";
        for (auto n: partners[i]) cout << n << " ";
        cout << endl;
    }
    // L leaves
    has_left[L] = true;
    for (auto n: partners[L]) {
        neighbors_left[n]--;
        chain.push(n);
    }
    while (!chain.empty()) {
        int u = chain.front(); chain.pop();
        if (has_left[u]) continue;
        if (neighbors_left[u] <= neighbors_start[u] / 2) {
            has_left[u] = true;
            for (auto n: partners[u]) {
                neighbors_left[n]--;
                chain.push(n);
            }
        }
    }
    // has X left?
    if (has_left[X]) cout << "leave";
    else cout << "stay";
    cout << endl;
    return 0;
}