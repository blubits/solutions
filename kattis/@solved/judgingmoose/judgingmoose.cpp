#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
    int l, r;
    scanf("%d %d", &l, &r);
    if (l == 0 && r == 0)
        printf("Not a moose\n");
    else if (l == r)
        printf("Even %d\n", l * 2);
    else
        printf("Odd %d\n", max(l, r) * 2);
    return 0;
}
