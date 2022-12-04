#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n, c;
    scanf("%d %d", &n, &c);
    vector<int> fruits(n);
    for (int i = 0; i < n; i++) scanf("%d", &fruits[i]);
    int max_no_fruit = -1;
    for (int i = 0; i < n; i++) {
        int no_fruit = 0, wt = 0;
        for (int j = i; j < n; j++) {
            if (wt + fruits[j] <= c) {
                no_fruit++;
                wt += fruits[j];
            }
        }
        max_no_fruit = max(no_fruit, max_no_fruit);
    }
    printf("%d\n", max_no_fruit);
    return 0;
}
