#include <cstdio>

using namespace std;

int main() {
    unsigned long long int n, d;
    while (scanf("%llu %llu", &n, &d) && !(n == 0 && d == 0)) {
        printf("%llu %llu / %llu\n", n / d, n % d, d);
    }
    return 0;
}
