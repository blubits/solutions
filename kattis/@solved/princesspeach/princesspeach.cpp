#include <cstdio>

using namespace std;

int main() {
    int k, n;
    scanf("%d %d", &k, &n);
    bool o[k];
    for (int i = 0; i < k; i++) o[i] = true;
    while (n--) {
        int b;
        scanf("%d", &b);
        o[b] = false;
    }
    int enc = 0;
    for (int i = 0; i < k; i++) {
        if (o[i])
            printf("%d\n", i);
        else
            enc++;
    }
    printf("Mario got %d of the dangerous obstacles.\n", enc);
    return 0;
}
