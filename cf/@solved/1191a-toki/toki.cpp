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

int category(int x) {
    int mod = x % 4;
    switch (mod) {
        case 0: return 3;
        case 1: return 0;
        case 2: return 2;
        case 3: return 1;
    }
}

int main() {
    int N;
    cin >> N;
    vii ans;
    for (int i = 0; i <= 2; i++)
        ans.push_back({category(N + i), i});
    auto [cat, inc] = *min_element(ans.begin(), ans.end());
    cout << inc << " " << char('A' + cat) << endl;
    return 0;
}