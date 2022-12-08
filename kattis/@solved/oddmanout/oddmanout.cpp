#include <cstdio>
#include <map>

using namespace std;

int main() {
    int t, c = 1;
    scanf("%d", &t);
    while (t--) {
        int k;
        scanf("%d", &k);
        map<int, int> id;
        while (k--) {
            int a;
            scanf("%d", &a);
            if (id.find(a) == id.end()) {
                id[a] = 1;
            } else {
                id[a]++;
            }
        }
        for (auto a : id) {
            if (a.second == 1) {
                printf("Case #%d: %d\n", c++, a.first);
                break;
            }
        }
    }
    return 0;
}
