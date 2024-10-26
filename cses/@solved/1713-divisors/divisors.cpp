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

set<int> primes;

void generate_all_primes(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.insert(i);
            for (int j = 2 * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int count_divisors(int n) {
    int ans = 1;
    for (auto p : primes) {
        if (p * p > n) break;
        int order_of_p = 0;
        while (n % p == 0) {
            n /= p;
            order_of_p++;
        }
        ans *= order_of_p + 1;
    }
    // If n is not 1 by the end of the loop, n is prime.
    // Thus n has an order of 1 and there are 2 ways
    // to select it.
    if (n != 1) ans *= 2;
    return ans;
}

int main() {
    int N;
    cin >> N;
    generate_all_primes(1000005);
    while (N--) {
        int x;
        cin >> x;
        cout << count_divisors(x) << endl;
    }
    return 0;
}