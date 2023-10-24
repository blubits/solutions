#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

vector<int> prices;

int main() {
    int N, M;
    while (cin >> N) {
        prices.clear();
        prices.resize(N);
        for (int i = 0; i < N; i++) cin >> prices[i];
        cin >> M;
        sort(prices.begin(), prices.end());
        auto p = lower_bound(prices.begin(), prices.end(), M/2);
        while (1) {
            if (binary_search(prices.begin(), prices.end(), M - *p)) {
                if (M - *p != *p || count(prices.begin(), prices.end(), *p) >= 2)break;
            }
            p--;
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n", min(M - *p, *p), max(M - *p, *p));
    }
    return 0;
}