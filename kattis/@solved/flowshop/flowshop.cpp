#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int p[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &p[i][j]);
        }
    }
    int t[n][m + 1];
    for (int swt = 0; swt < n; swt++) {
        for (int stg = 0; stg <= m; stg++) {
            if (swt == 0 && stg == 0) {
                t[swt][stg] = 0;
            } else if (swt == 0) {
                t[swt][stg] = t[swt][stg - 1] + p[swt][stg - 1];
            } else if (stg == 0) {
                t[swt][stg] = t[swt - 1][stg + 1];
            } else {
                t[swt][stg] =
                    p[swt][stg - 1] + max(t[swt - 1][stg], t[swt][stg - 1]);
            }
        }
    }
    for (int swt = 0; swt < n; swt++) {
        if (swt != 0) printf(" ");
        printf("%d", t[swt][m]);
    }
    printf("\n");
    return 0;
}
