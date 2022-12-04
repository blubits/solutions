#include <algorithm>
#include <cmath>
#include <cstdio>
#include <map>
#include <vector>

using namespace std;

int main() {
    // tape needed to make A(int) paper into A(int - 1) paper
    map<int, double> tape;
    double l = exp2(-1.25), w = exp2(-0.75);
    for (int i = 2; i <= 30; i++) {
        tape[i] = max(l, w);
        if (l > w)
            l /= 2;
        else
            w /= 2;
    }
    double ans = 0;
    int sheets[31] = {0}, k;
    scanf("%d", &k);
    for (int i = 2; i <= k; i++) scanf("%d", &sheets[i]);
    // for (int i = 0; i < 31; i++) printf("%d ", sheets[i]);
    // printf("\n");
    long long int needed = 2;
    for (int i = 2; i <= k; i++) {
        if (needed > sheets[i]) {
            // need more sheets
            needed -= sheets[i];
        } else {
            // fold sheets downward
            for (int j = i; j >= 1; j--) {
                int folded;
                if (j == i) {
                    folded = needed;
                    sheets[j] -= folded;
                } else {
                    folded = sheets[j];
                    sheets[j] %= 2;
                }
                ans += tape[j] * (folded / 2);
                sheets[j - 1] += folded / 2;
                // printf("[%d] ", needed);
                // for (int i = 0; i < 31; i++) printf("%d ", sheets[i]);
                // printf("\n");
            }
            printf("%.10lf\n", ans);
            return 0;
        }
        needed *= 2;
    }
    printf("impossible\n");
    return 0;
}
