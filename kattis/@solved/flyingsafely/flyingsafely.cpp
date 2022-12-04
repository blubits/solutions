#include <cstdio>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        printf("%d\n", n - 1);  // true since graph is always connected
        while (m--) scanf("%*d %*d");
    }
    return 0;
}
