#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & (-S))

typedef long long ll;
typedef pair<long long, long long> ii;
typedef tuple<long long, long long, long long> iii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;
const int NINF = 0xcfcfcfcf;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-9;

// Gets the GCD of two numbers.
// OJ is still on C++11, so we can't use std::gcd.
ll gcd(ll a, ll b) {
    while (b != 0) {
        ll r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// Gets the values of x, y such that ax + by = gcd(a, b).
iii ext_gcd(ll a, ll b) {
	ll xi = 1, yi = 0, ri = a;
	ll xii = 0, yii = 1, rii = b;
	while (rii != 0) {
		ll m = ri / rii;
		tie(xi, xii) = make_tuple(xii, xi - m * xii);
		tie(yi, yii) = make_tuple(yii, yi - m * yii);
		tie(ri, rii) = make_tuple(rii, ri - m * rii);
	}
	return {ri, xi, yi};
}

// Solves the equation ax + by = d.
ii solve(ll a, ll b, ll c) {
	auto dxdyd = ext_gcd(a, b);
    ll d = get<0>(dxdyd), xd = get<1>(dxdyd), yd = get<2>(dxdyd);
	// indicates that the solution DNE
	if (c % d != 0) return {INF, INF};
	ll m = c / d;
	return {m * xd, m * yd};
}

// Shifts the solution to the equation ax + by = c by k.
ii shift_solution(ii solution, ll a, ll b, ll k) {
    ll shift_x = solution.first + (k * b / gcd(a, b));
    ll shift_y = solution.second - (k * a / gcd(a, b));
    return {shift_x, shift_y};
}

// Counts the number of positive solutions to ax + by = c.
ll count_positive_solutions(ll a, ll b, ll c) {

    // Solve the equation ax + by = c
    auto xy = solve(a, b, c);
    ll x = xy.first, y = xy.second;
    // If the solution DNE (INF), there are no positive solutions.
    if (x == INF || y == INF) return 0;

    // Otherwise, solutions do exist.
    // By algebra, for the solution to be positive, two inequalities
    // must hold:
    // - x + (kb/gcd(a, b)) >= 0
    // - y - (ka/gcd(a, b)) >= 0
    // where k is any integer.
    // Algebraic manipulation gets us the following range for k:
    // k = [-(gcd(a, b)*x/b), (gcd(a, b)*y/a)]

    ll g = gcd(a, b);
    ll kl = -(g*x)/b, ku = (g*y)/a;

    printf("kl = %llf, ku = %llf\n", -(g*x)/double(b), ku = (g*y)/double(a));
    printf("int(kl) = %lld, int(ku) = %lld\n", kl, ku);

    auto xlyl = shift_solution({x, y}, a, b, kl);
    ll xl = xlyl.first, yl = xlyl.second;
    auto xuyu = shift_solution({x, y}, a, b, ku);
    ll xu = xuyu.first, yu = xuyu.second;

    // Now the bounds are actually decimals, not integers.
    // But we're calculating them as integers.
    // For example, the interval [1.67, 1.69] gets calculated as [1, 1].
    if (kl == ku) {
        // If the integer interval has the same upper and lower limits,
        // then the actual interval is of the form [x.yy, x.zz].
        // So for example, it could be [1.00, 1.56] (one solution valid)
        // or something like [1.25, 1.56] (no solutions valid).
        if (xl >= 0 && yl >= 0) return 1;
        else return 0;
    } else {
        // Otherwise, the interval is of the form [a.bb, c.dd] => [a, c].
        // So we first assume that the interval is [a, c], and then
        // adjust if the lower and upper bounds we found get x/y values
        // less than 0.
        ll ans = (ku - kl) + 1;
        if (xl < 0 || yl < 0) ans--;
        if (xu < 0 || yu < 0) ans--;
        return ans;
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        ll a, b, c, p;
        cin >> a >> b >> c >> p;
        // Find the number of ways to solve ax + by + cz = p with positive x/y/z.
        ll ans = 0;
        for (ll z = 0; p - c*z >= 0; z++) {
            auto xy = solve(a, b, p - c*z);
            ll x = xy.first, y = xy.second;
            ll i = count_positive_solutions(a, b, p - c*z);
            ans += i;
        }
        cout << "Case " << i + 1 << ": " << ans << endl;
    }
    return 0;
}