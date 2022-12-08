#include <cmath>
#include <iostream>

typedef long long int ll;

ll lastfib_mod(ll N, ll mod) {
    ll cycle[20000];
    cycle[0] = 0;
    ll fn = 0, fnp1 = 1, fnp2 = fn + fnp1;
    ll n = 0;
    while (true) {
        fn = fnp1;
        fnp1 = fnp2;
        fnp2 = (fn + fnp1) % mod;
        cycle[++n] = fn;
        if (fnp1 == 0 && fnp2 == 1) break;
    }
    n++;
    return cycle[N % n];
}

int main() {
    ll a, b;
    std::cin >> a;
    std::cout << (lastfib_mod(a, 10) * lastfib_mod(a + 1, 10)) % 10
              << std::endl;
    return 0;
}
