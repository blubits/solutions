#include <cstdio>
#include <vector>

using namespace std;

int main() {
    vector<bool> is_prime(1000001, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i <= 1000000; i++) {
        if (!is_prime[i]) continue;
        for (int c = 2 * i; c <= 1000000; c += i) {
            is_prime[c] = false;
        }
    }
    int k;
    while (scanf("%d", &k) && k != 0) {
        int a = 3, b = k - 3;
        while (!(is_prime[a] && is_prime[b])) {
            a += 2;
            b -= 2;
        }
        printf("%d = %d + %d\n", k, a, b);
    }
    return 0;
}
