#include <iostream>

typedef long long int ll;

ll lastfib(int N) {
    ll fn = 0, fnp1 = 1, fnp2 = fn + fnp1;
    int n = 0;
    while (n != N) {
        fn = fnp1;
        fnp1 = fnp2;
        fnp2 = (fn + fnp1) % 10;
        n++;
    }
    return fn;
}

int main() {
    int N;
    std::cin >> N;
    std::cout << lastfib(N) << std::endl;
    return 0;
}
