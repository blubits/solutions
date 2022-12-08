#include <cmath>
#include <cstdio>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        int mile = 0, juice = 0, c, ci;
        scanf("%d", &c);
        while (c--) {
            scanf("%d", &ci);
            mile += (ci / 30 + 1) * 10;
            juice += (ci / 60 + 1) * 15;
        }
        printf("Case %d: ", i);
        if (mile < juice)
            printf("Mile %d\n", mile);
        else if (juice < mile)
            printf("Juice %d\n", juice);
        else
            printf("Mile Juice %d\n", mile);
    }
    return 0;
}
