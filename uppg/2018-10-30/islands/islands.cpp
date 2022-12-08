#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
    int t, c;
    int x[12];
    scanf("%d", &t);
    while (t--) {
        int ins = 0;
        scanf("%d", &c);
        for (int i = 0; i < 12; i++) scanf("%d", &x[i]);
        for (int i = 1; i < 11; i++) {
            int mn = x[i];
            for (int j = i; j < 11; j++) {
                mn = min(mn, x[j]);
                if (x[i - 1] < mn) {
                    if (x[j + 1] < mn) {
                        // printf("island: [%d, %d]\n", i, j);
                        ins++;
                    }
                } else {
                    break;
                }
            }
        }
        printf("%d %d\n", c, ins);
    }
}
