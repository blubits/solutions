#include <cstdio>

using namespace std;

int main() {
    int e, f, c;
    scanf("%d %d %d", &e, &f, &c);
    int a = e + f;
    int dr = 0;
    while (a >= c) {
        a -= c;
        a += 1;
        dr++;
    }
    printf("%d\n", dr);
    return 0;
}
