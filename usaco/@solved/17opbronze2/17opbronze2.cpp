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

int A = 0, C = 1, G = 2, T = 3;

int classify(char c) {
    switch (c) {
        case 'A': return A;
        case 'C': return C;
        case 'G': return G;
        case 'T': return T;
        default: return -1;
    }
}

vector<string> spotty, non_spotty;
vector<bool> present(4);
int main() {
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    int n, m, ans = 0;
    cin >> n >> m;
    spotty.resize(n); non_spotty.resize(n);
    for (int i = 0; i < n; i++) cin >> spotty[i];
    for (int i = 0; i < n; i++) cin >> non_spotty[i];
    for (int i = 0; i < m; i++) {
        present.clear();
        present.resize(4);
        for (int j = 0; j < n; j++) {
            present[classify(spotty[j][i])] = 1;
        }
        bool can_explain_spottiness = true;
        for (int j = 0; j < n; j++) {
            if (present[classify(non_spotty[j][i])]) {
                can_explain_spottiness = false;
                break;
            }
        }
        if (can_explain_spottiness) ans++;
    }
    cout << ans << endl;
    return 0;
}