#include <iostream>

typedef long long int ll;

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll t = b;
        b = a % b;
        a = t;
    }
    return a;
}

ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }

int main() {
    ll a, b;
    std::cin >> a >> b;
    std::cout << lcm(a, b) << std::endl;
    return 0;
}
