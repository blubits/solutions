#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int c = 1; c <= t; c++) {
        printf("Case #%d:\n", c);
        bool b1[10001] = {false}, b2[10001] = {false}, b3[10001] = {false};
        vector<int> p1, p2, p3;
        int s[4] = {0, 0, 0, 0};
        int k, p;
        // 1
        scanf("%d", &k);
        while (k--) {
            scanf("%d", &p);
            b1[p] = true;
        }
        // 2
        scanf("%d", &k);
        while (k--) {
            scanf("%d", &p);
            b2[p] = true;
        }
        // 3
        scanf("%d", &k);
        while (k--) {
            scanf("%d", &p);
            b3[p] = true;
        }
        for (int i = 0; i <= 10000; i++) {
            if (b1[i] && !b2[i] && !b3[i]) {
                s[1]++;
                p1.push_back(i);
            } else if (!b1[i] && b2[i] && !b3[i]) {
                s[2]++;
                p2.push_back(i);
            } else if (!b1[i] && !b2[i] && b3[i]) {
                s[3]++;
                p3.push_back(i);
            }
        }
        // find max
        int mx = 0;
        for (int i = 1; i <= 3; i++) {
            if (mx < s[i]) mx = s[i];
        }
        for (int i = 1; i <= 3; i++) {
            if (s[i] == mx) {
                vector<int> v;
                if (i == 1)
                    v = p1;
                else if (i == 2)
                    v = p2;
                else if (i == 3)
                    v = p3;
                printf("%d %d", i, s[i]);
                for (auto vi : v) printf(" %d", vi);
                printf("\n");
            }
        }
    }
    return 0;
}
