#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

int main() {
    int n, m;
    scanf("%d %d ", &n, &m);
    char tree[n][m];
    int rings[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%c ", &tree[i][j]);
            if (tree[i][j] == 'T')
                rings[i][j] = 1000;
            else
                rings[i][j] = 0;
        }
    }
    int dots = 2, k = 0;
    bool unfilled_present = false;
    // set border
    while (true) {
        unfilled_present = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (tree[i][j] == 'T') {
                    int min_out = min(min(i != 0 ? rings[i - 1][j] : 0,
                                          j != 0 ? rings[i][j - 1] : 0),
                                      min(i != n - 1 ? rings[i + 1][j] : 0,
                                          j != m - 1 ? rings[i][j + 1] : 0));
                    if (min_out == k) {
                        unfilled_present = true;
                        rings[i][j] = k + 1;
                    }
                }
            }
        }
        k++;
        if (!unfilled_present) break;
    }
    if (k > 10) dots = 3;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dots == 2) {
                if (rings[i][j] == 0)
                    printf("..");
                else
                    printf(".%d", rings[i][j]);
            } else {
                if (rings[i][j] == 0)
                    printf("...");
                else if (rings[i][j] < 10)
                    printf("..%d", rings[i][j]);
                else
                    printf(".%d", rings[i][j]);
            }
        }
        printf("\n");
    }
}
