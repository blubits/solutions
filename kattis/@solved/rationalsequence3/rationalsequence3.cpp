#include <bitset>
#include <stack>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int c, k, n = 1, d = 1;
        stack<int> bits;
        scanf("%d %d", &c, &k);
        while (k != 1) {
            bits.push(k % 2);
            k >>= 1;
        }
        while (!bits.empty()) {
            if (bits.top() == 1) {
                n = n + d;
            } else {
                d = n + d;
            }
            bits.pop();
        }
        printf("%d %d/%d\n", c, n, d);
    }
    return 0;
}
