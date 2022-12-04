#include <cstdio>

using namespace std;

int main() {
    int p, c = 1;
    while (scanf("%d", &p) && p >= 0) {
        printf("Case %d:\n", c++);
        int created[12], required[12], available[12];
        for (int i = 0; i < 12; i++) scanf("%d", &created[i]);
        for (int i = 0; i < 12; i++) scanf("%d", &required[i]);
        for (int i = 0; i < 12; i++) {
            if (i == 0)
                available[i] = p;
            else
                available[i] = created[i - 1] + available[i - 1];
            // delist all problems needed for that month
            if (available[i] >= required[i]) {
                printf("No problem! :D\n");
                available[i] -= required[i];
            } else {
                printf("No problem. :(\n");
            }
        }
    }
    return 0;
}
