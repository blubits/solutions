#include <cstdio>

using namespace std;

int main() {
    int b, n;
    while (1) {
        scanf("%d %d", &b, &n);
        if (b == 0 && n == 0) break;
        int reserves[b];
        for (int i = 0; i < b; i++) {
            scanf("%d", &reserves[i]);
        }
        while (n--) {
            int debtor, creditor, cost;
            scanf("%d %d %d", &debtor, &creditor, &cost);
            reserves[debtor - 1] -= cost;
            reserves[creditor - 1] += cost;
        }
        bool bailable = true;
        for (auto i : reserves) {
            if (i < 0) {
                bailable = false;
                break;
            }
        }
        if (bailable)
            printf("S\n");
        else
            printf("N\n");
    }
    return 0;
}
