#include <cstdio>

using namespace std;

int main() {
    int t, c = 1;
    scanf("%d", &t);
    while (t--) {
        int sz;
        scanf("%*s %*s %d\n", &sz);
        long long int matrix[sz][sz];
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                scanf("%lld", &matrix[i][j]);
            }
        }
        bool symmetric = true;
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                if (matrix[i][j] < 0 ||
                    matrix[i][j] != matrix[sz - i - 1][sz - j - 1]) {
                    symmetric = false;
                    break;
                }
            }
            if (!symmetric) break;
        }
        printf("Test #%d: ", c++);
        if (symmetric)
            printf("Symmetric.");
        else
            printf("Non-symmetric.");
        printf("\n");
    }
    return 0;
}
