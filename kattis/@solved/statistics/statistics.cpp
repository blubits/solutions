#include <cstdio>

using namespace std;

int main() {
    int n, c = 1;
    while (scanf("%d", &n) == 1) {
        int max = -1000000000, min = 1000000000;
        while (n--) {
            int i;
            scanf("%d", &i);
            if (i > max) max = i;
            if (i < min) min = i;
        }
        printf("Case %d: %d %d %d\n", c++, min, max, max - min);
    }
}
