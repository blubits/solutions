#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int t, n, xi;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        vector<int> nums;
        while (n--) {
            scanf("%d", &xi);
            nums.push_back(xi);
        }
        int maxmin = *max_element(nums.begin(), nums.end()) -
                     *min_element(nums.begin(), nums.end());
        printf("%d\n", 2 * maxmin);
    }
    return 0;
}
