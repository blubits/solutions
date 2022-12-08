#include <cstdio>

using namespace std;

int main() {
    int a, b, c;
    char op1, op2;
    scanf("%d %d %d", &a, &b, &c);
    if (a + b == c) {
        op1 = '+';
        op2 = '=';
    } else if (a - b == c) {
        op1 = '-';
        op2 = '=';
    } else if (a * b == c) {
        op1 = '*';
        op2 = '=';
    } else if (a % b == 0 && a / b == c) {
        op1 = '/';
        op2 = '=';
    } else if (a == b + c) {
        op1 = '=';
        op2 = '+';
    } else if (a == b - c) {
        op1 = '=';
        op2 = '-';
    } else if (a == b * c) {
        op1 = '=';
        op2 = '*';
    } else if (b % c == 0 && a == b / c) {
        op1 = '=';
        op2 = '/';
    }
    printf("%d%c%d%c%d\n", a, op1, b, op2, c);
    return 0;
}
