#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
    int seq = 1;
    while (1) {
        unsigned long long int n, m, c;
        scanf("%llu %llu %llu", &n, &m, &c);
        if (n == 0 && m == 0 && c == 0) break;
        unsigned long long int load = 0, max_load = 0, amp[n];
        bool state[n];
        for (unsigned long long int i = 0; i < n; i++) {
            scanf("%llu", &amp[i]);
            state[i] = false;
        }
        unsigned long long int k = 0;
        bool overload = false;
        for (unsigned int i = 0; i < m; i++) {
            scanf("%llu", &k);
            if (overload) continue;
            if (state[k - 1])
                load -= amp[k - 1];
            else
                load += amp[k - 1];
            max_load = max(load, max_load);
            state[k - 1] = !state[k - 1];
            if (load > c) overload = true;
        }
        printf("Sequence %d\n", seq++);
        if (overload)
            printf("Fuse was blown.\n");
        else {
            printf("Fuse was not blown.\nMaximal power consumption was %llu ",
                   max_load);
            if (max_load == 1)
                printf("amperes.\n");
            else
                printf("amperes.\n");
        }
        printf("\n");
    }
    return 0;
}
