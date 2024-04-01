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
vector<ll> fruits;
ll sum = 0;
ll basket_sum = 0;

ll rec(int i) {
    if (basket_sum >= 200) return 0;
    if (i == N) {
        return basket_sum;
    }
    unsigned long long ans = 0;
    ans += rec(i + 1);
    basket_sum += fruits[i];
    ans += rec(i + 1);
    basket_sum -= fruits[i];
    return ans;
}

int main() {
    cin >> N;
    fruits.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> fruits[i];
        sum += fruits[i] * (ll(1) << (N - 1));
    }
    cout << sum - rec(0) << endl;
    return 0;
}