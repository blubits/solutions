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

const ll MAX = 6e18;

vector<int> primes;

void get_primes() {
    const ll MAX_PRIME = cbrt(MAX) + 10;
    vector<bool> is_prime(MAX_PRIME + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (ll p = 2; p <= MAX_PRIME; p++) {
        if (!is_prime[p]) continue;
        primes.push_back(p);
        for (ll m = p * p; m <= MAX_PRIME; m += p) {
            is_prime[m] = false;
        }
    }
}

vector<ll> get_factors(ll b) {
    vector<ll> prime_factors;
    set<ll> factor_set;
    vector<ll> factors_to_add;
    factor_set.insert(1);
    for (auto p: primes) {
        while (b % p == 0) {
            prime_factors.push_back(p);
            factors_to_add.clear();
            for (ll f: factor_set) {
                factors_to_add.push_back(f * p);
            }
            for (ll f: factors_to_add) {
                factor_set.insert(f);
            }
            b /= p;
        }
        if (b == 1) break;
    }
    factors_to_add.clear();
    for (auto ll: factor_set) factors_to_add.push_back(ll);
    return factors_to_add;
}


int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    ll N;
    cin >> N;
    get_primes();
    while (N--) {
        ll a, b, c;
        cin >> a >> b >> c;

        // Step 1: Since xyz = b by (2), x is a factor of b. Search through all factors of b.
        vector<ll> f_b = get_factors(b);
        bool has_solution = false;
        for (ll x: f_b) {
        
            // Step 2: We've found an x. How do we find y?
            // By (1), z = a - x - y.
            // (1) -> (2), we have xy(a - x - y) - b = 0.
            // Expanding, we have:
            // xya - x^2y - xy^2 - b = 0
            // -xy^2 - x^2y + xya - b = 0
            // -xy^2 - (x^2 - xa)y - b = 0
            // y^2 + ((x(x - a))/x)y + b/x = 0
            // y^2 + (x - a)y + b/x = 0
            // Use the quadratic formula to solve for y.

            ll alpha = 1;
            ll beta = x - a;
            ll gamma = b / x;
            ll discriminant = (beta * beta) - (4 * alpha * gamma);
            if (discriminant < 0) continue;
            // You'd want the bigger of the two possible ys.
            ll y = (-beta + sqrt(discriminant)) / 2;

            // Step 3: Get z.
            ll z = a - x - y;

            // Step 4: Check the values.
            if (x == y || y == z || x == z) continue;
            if (x + y + z != a) continue;
            if (x * y * z != b) continue;
            if (x * x + y * y + z * z != c) continue;

            // If x, y, z pass all the tests above, it's an answer.
            has_solution = true;
            vector<ll> ans = {x, y, z};
            sort(ans.begin(), ans.end());
            cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
            break;

        }
        if (!has_solution) {
            cout << "No solution.\n";
        }
    }
    return 0;
}