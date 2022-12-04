#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int t;
    vector<int> group;
    scanf("%d", &t);
    while (t--) {
        int n, i;
        scanf("%d", &n);
        while (n--) {
            scanf("%d", &i);
            group.push_back(i);
        }
        int comp = group[0] + 1;
        for (int i = 1; i < group.size() - 1; i++) {
            if (comp != group[i]) {
                printf("%d\n", i + 1);
                break;
            }
            comp++;
        }
        group.clear();
    }
    return 0;
}
