#include <bits/stdc++.h>
using namespace std;

bool col[3000];

int main() {
    int n, m, ans = 1;
    scanf("%d %d\n", &n, &m);
    for (int i = 0; i < m; i++) col[i] = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            scanf("%c ", &c);
            if (c == '$') col[j] = false;
        }
    }
    for (int i = 0; i < m; i++) if (col[i]) ans++;
    printf("%d\n", ans);
    return 0;
}