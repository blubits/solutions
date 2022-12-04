#include <cstdio>

using namespace std;

int main() {
    bool d[366] = {false};
    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b;
        scanf("%d %d", &a, &b);
        for (int i = a; i <= b; i++) d[i] = true;
    }
    int c = 0;
    for (int i = 1; i <= 365; i++)
        if (d[i]) c++;
    printf("%d\n", c);
    return 0;
}
