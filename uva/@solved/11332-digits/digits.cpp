#include <cstdio>

using namespace std;

int digital_sum(int x) {
    int s = 0;
    while (x != 0) {
        s += x % 10;
        x /= 10;
    }
    return s;
}

int main() {
    int x;
    while (1) {
        scanf("%d", &x);
        if (x == 0) break;
        while (!(0 <= x && x <= 9)) {
            x = digital_sum(x);
        }
        printf("%d\n", x);
    }
    return 0;
}
