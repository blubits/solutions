#include <cstdio>

using namespace std;

int main() {
    int n, p, q;
    scanf("%d %d %d", &n, &p, &q);
    int t = (p + q) / n;
    if (t % 2 == 0)
        printf("paul\n");
    else
        printf("opponent\n");
    return 0;
}
