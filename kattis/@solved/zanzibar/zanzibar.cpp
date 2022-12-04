#include <cstdio>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int k, t = 1, i = 0;
        while (scanf("%d", &k) && k != 0) {
            if (k > t) {
                i += k - t;
            }
            t = k * 2;
        }
        printf("%d\n", i);
    }
}
