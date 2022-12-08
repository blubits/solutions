#include <cstdio>

using namespace std;

int main() {
    int t, c = 1;
    scanf("%d", &t);
    while (t--) {
        int k;
        scanf("%d", &k);
        int net = 0, p[k], q[k], pq[k];
        for (int i = 0; i < k; i++) {
            scanf("%d", &p[i]);
            net += p[i];
        }
        for (int i = 0; i < k; i++) {
            scanf("%d", &q[i]);
            net -= q[i];
            pq[i] = p[i] - q[i];
        }
        printf("Case %d: ", c++);
        if (net < 0)
            printf("Not possible");
        else {
            for (int i = 0; i < k; i++) {
                if (pq[i] < 0) continue;
                int s = pq[i];
                bool broke = false;
                for (int j = i + 1; j != i; j = (j + 1) % k) {
                    s += pq[j];
                    if (s < 0) {
                        broke = true;
                        break;
                    }
                }
                if (!broke) {
                    printf("Possible from station %d", i + 1);
                    break;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
