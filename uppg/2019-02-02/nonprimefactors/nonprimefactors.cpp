#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    vector<int> p(2000001);
    vector<int> npf(2000001);

    for (int i = 1; i <= 2000000; i++) {
        p[i] = i;
        npf[i] = 1;
    }

    int pr = 2;
    while (pr != 2000001) {
        if (p[pr] != 0) {
            for (int b = pr; b <= 2000000; b *= pr) {
                for (int k = 1 * b; k <= 2000000; k += b) {
                    if (k == pr) continue;
                    npf[k]++;
                    if (b == pr) p[k] = 0;
                    if (k == 100) {
                        cout << b << " " << npf[k] << endl;
                    }
                }
            }
        }
        pr++;
    }

    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", npf[n]);
    }

    return 0;
}
