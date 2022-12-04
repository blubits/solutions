#include <cstdio>

using namespace std;

int main() {
    int bus[] = {1729,   4104,   13832,  20683,  32832,  39312,
                 40033,  46683,  64232,  65728,  110656, 110808,
                 134379, 149389, 165464, 171288, 195841, 216027,
                 216125, 262656, 314496, 320264, 327763, 373464};
    int k;
    scanf("%d", &k);
    if (k < 1729)
        printf("none\n");
    else if (k >= 373464) {
        printf("373464\n");
    } else {
        for (int i = 0; i < 24; i++) {
            if (bus[i] > k) {
                printf("%d\n", bus[i - 1]);
                break;
            }
        }
    }
}
