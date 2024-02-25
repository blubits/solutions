#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    vector<int> len(1000000);
    for (int i = 0; i <= 999999; i++) {
        if (i == 0)
            len[i] = 0;
        else
            len[i] = -1;
    }
    for (int i = 1; i <= 999999; i++) {
        long long int n = i;
        int c = 1;
        while (n != 1) {
            if (n % 2 == 0)
                n = n / 2;
            else
                n = (3 * n) + 1;
            if (n < 1000000 && len[n] != -1) {
                c += len[n];
                break;
            } else {
                c++;
            }
        }
        len[i] = c;
    }
    int a, b;
    while (scanf("%d %d", &a, &b) == 2) {
        int m = -1;
        for (int i = min(a, b); i <= max(a, b); i++) {
            if (len[i] > m) m = len[i];
        }
        printf("%d %d %d\n", a, b, m);
    }
    return 0;
}
