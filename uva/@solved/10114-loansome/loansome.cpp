#include <cstdio>

using namespace std;

int main() {
    int mo, r;
    double downp, value;
    double worth, balance;
    while (1) {
        scanf("%d %lf %lf %d", &mo, &downp, &value, &r);
        if (mo < 0) break;
        worth = value + downp;
        balance = value;
        double payments = value / mo;

        // initialize
        double dep[mo + 1];
        for (int i = 0; i <= mo; i++) {
            dep[i] = -5.0;
        }

        // read in rates
        int m;
        double p;
        while (r--) {
            scanf("%d %lf", &m, &p);
            dep[m] = p;
        }
        for (int i = 0; i <= mo; i++) {
            if (dep[i] < 0) {
                dep[i] = dep[i - 1];
            }
        }

        int end;
        for (int i = 0; i <= mo; i++) {
            if (i != 0) balance -= payments;
            worth *= 1 - dep[i];
            end = i;
            if (worth > balance) {
                break;
            }
        }

        if (end != 1)
            printf("%d months\n", end);
        else
            printf("%d month\n", end);
    }
    return 0;
}
