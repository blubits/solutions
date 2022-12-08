#include <cstdio>

using namespace std;

int main() {
    int trucks[101] = {0};
    int cost = 0, a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    for (int i = 0; i < 3; i++) {
        int s, e;
        scanf("%d %d", &s, &e);
        for (int a = s; a < e; a++) trucks[a]++;
    }
    for (int i = 1; i <= 100; i++) {
        if (trucks[i] == 1)
            cost += a;
        else if (trucks[i] == 2)
            cost += b * 2;
        else if (trucks[i] == 3)
            cost += c * 3;
    }
    printf("%d\n", cost);
    return 0;
}
