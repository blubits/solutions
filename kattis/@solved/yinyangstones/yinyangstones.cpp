#include <cstdio>

using namespace std;

int main() {
    int w = 0, b = 0;
    char s;
    while (scanf("%c", &s) == 1) {
        if (s == 'W')
            w++;
        else if (s == 'B')
            b++;
    }
    printf("%d\n", w == b);
    return 0;
}
