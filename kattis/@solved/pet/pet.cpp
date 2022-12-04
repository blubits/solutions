#include <cstdio>

using namespace std;

int main() {
    int a, b, c, d, winner = 0, max_sum = -1;
    for (int i = 1; i <= 5; i++) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        if ((a + b + c + d) > max_sum) {
            winner = i;
            max_sum = a + b + c + d;
        }
    }
    printf("%d %d\n", winner, max_sum);
    return 0;
}
