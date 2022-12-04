#include <bits/stdc++.h>
using namespace std;

int img[30][30];
int kernel[30][30];

int main() {
    int h, w, n, m;
    scanf("%d %d %d %d\n", &h, &w, &n, &m);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf("%d ", &img[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d ", &kernel[i][j]);
        }
    }
    for (int i = 0; i < h - n + 1; i++) {
        for (int j = 0; j < w - m + 1; j++) {
            int ans = 0;
            for (int a = 0; a < n; a++) {
                for (int b = 0; b < m; b++) {
                    ans += kernel[n - a - 1][m - b - 1] * img[i + a][j + b];
                }
            }
            printf("%d ", ans);
        }
        printf("\n");
    }
}
