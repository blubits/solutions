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

bool distinct(int i, int j) {
    bitset<10> used;
    string si = to_string(i), sj = to_string(j);
    if (i < 10000 || j < 10000) used.set(0);
    for (char c: si) {
        used.set(c - '0');
    }
    for (char c: sj) {
        used.set(c - '0');
    }
    return used.all();
}

int main() {
    int N, T = 0;
    while (cin >> N && N != 0) {
        if (T++ != 0) cout << endl;
        bool found = false;
        for (int j = 1234; j < 98765/N; j++) {
            int i = j * N;
            if (distinct(i, j)) {
                found = true;
                printf("%05d / %05d = %d\n", i, j, N);
            }
        }
        if (!found) {
            cout << "There are no solutions for " << N << "." << endl;
        }
    }
    return 0;
}