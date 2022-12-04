#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int prob[a + b + 1];
    for (int i = 0; i <= a + b; i++) {
        prob[i] = 0;
    }
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            prob[i + j]++;
        }
    }
    int m = *max_element(prob, prob + a + b + 1);
    for (int i = 1; i <= a + b; i++) {
        if (prob[i] == m) printf("%d\n", i);
    }
    return 0;
}
