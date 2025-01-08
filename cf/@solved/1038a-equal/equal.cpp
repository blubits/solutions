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

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> freq(k);
    char c;
    for (int i = 0; i < n; i++) {
        cin >> c;
        freq[int(c - 'A')]++;
    }
    cout << *min_element(freq.begin(), freq.end()) * k << endl;
    return 0;
}