#include <algorithm>
#include <cstdio>

using namespace std;

char adrian(int n) {
    if (n % 3 == 0)
        return 'A';
    else if (n % 3 == 1)
        return 'B';
    else
        return 'C';
}

char bruno(int n) {
    if (n % 2 == 0)
        return 'B';
    else if (n % 4 == 1)
        return 'A';
    else
        return 'C';
}

char goran(int n) {
    if ((n / 2) % 3 == 0)
        return 'C';
    else if ((n / 2) % 3 == 1)
        return 'A';
    else
        return 'B';
}

int main() {
    int t;
    scanf("%d\n", &t);
    int a = 0, b = 0, g = 0;
    for (int i = 0; i < t; i++) {
        char c;
        scanf("%c", &c);
        if (adrian(i) == c) a++;
        if (bruno(i) == c) b++;
        if (goran(i) == c) g++;
    }
    int m = max(a, max(b, g));
    printf("%d\n", m);
    if (a == m) printf("Adrian\n");
    if (b == m) printf("Bruno\n");
    if (g == m) printf("Goran\n");
    return 0;
}
