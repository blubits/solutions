#include <cstdio>

using namespace std;

int main() {
    double Eg = 0, Ee = 0;
    int a1, b1, a2, b2, c1, d1, c2, d2;
    scanf("%d %d %d %d\n%d %d %d %d", &a1, &b1, &a2, &b2, &c1, &d1, &c2, &d2);
    for (int i = a1; i <= b1; i++) {
        for (int j = a2; j <= b2; j++) {
            Eg += i + j;
        }
    }
    for (int i = c1; i <= d1; i++) {
        for (int j = c2; j <= d2; j++) {
            Ee += i + j;
        }
    }
    Eg /= (b1 - a1 + 1) * (b2 - a2 + 1);
    Ee /= (d1 - c1 + 1) * (d2 - c2 + 1);
    if (Eg > Ee)
        printf("Gunnar");
    else if (Eg < Ee)
        printf("Emma");
    else
        printf("Tie");
    printf("\n");
    return 0;
}
