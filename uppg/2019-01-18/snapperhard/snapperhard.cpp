#include <cstdio>

using namespace std;

int main()
{
    int t, c = 1;
    scanf("%d", &t);
    while (t--)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        k %= (1 << n);
        if (k == (1 << n) - 1)
            printf("Case #%d: ON\n", c++);
        else
            printf("Case #%d: OFF\n", c++);
    }
    return 0;
}