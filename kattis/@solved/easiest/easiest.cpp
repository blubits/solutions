#include <cstdio>

using namespace std;

int sum_digits(unsigned long long int k) {
    int s = 0;
    while (k != 0) {
        s += k % 10;
        k /= 10;
    }
    return s;
}

int main() {
    unsigned long long int k;
    while (scanf("%llu", &k) && k != 0) {
        unsigned long long int p = 11;
        while (1) {
            if (sum_digits(k) == sum_digits(p * k)) {
                printf("%d\n", p);
                break;
            }
            p++;
        }
    }
    return 0;
}
