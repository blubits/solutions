#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int t, i, num, denom;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d/%d", &i, &num, &denom);
        vector<int> pos;
        while (num != 1 || denom != 1) {
            if (num > denom) {
                // is a right child
                pos.push_back(1);
                num -= denom;
            } else {
                // is a left child
                pos.push_back(0);
                denom -= num;
            }
        }
        pos.push_back(1);
        int n = 0;
        for (int i = 0; i < pos.size(); i++) {
            n += pos[i] * exp2(i);
        }
        printf("%d %d\n", i, n);
    }
}
