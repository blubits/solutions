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

int csort(char c) {
    switch (c) {
        case 'K': return 0;
        case 'E': return 1;
        case 'Y': return 2;
        default: return -1;
    }
}

vector<int> posns[2];

// KKEEYY

int main() {
    string S;
    int nswaps;
    cin >> S >> nswaps;
    for (int i = 0; i < S.size(); i++) {
        posns[csort(S[i])].push_back(i);
    }
    return 0;
}