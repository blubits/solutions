#include <cstdio>

using namespace std;

int sum_digits(int k) {
    int s = 0;
    while (k != 0) {
        s += k % 10;
        k /= 10;
    }
    return s;
}

int main() {
    int n;
    scanf("%d", &n);
    do {
        if (n % sum_digits(n) == 0) {
            printf("%d\n", n);
            break;
        }
    } while (n++);
    return 0;
}
