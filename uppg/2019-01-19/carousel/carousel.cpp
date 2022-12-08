#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int n, k;
    while (cin >> n >> k && !(n == 0 && k == 0)) {
        int a, b, ma = -1, mb = -1;
        double mr = 1000000;
        while (n--) {
            cin >> a >> b;
            double r = double(b) / double(a);
            if (a <= k && ((r < mr) || ((r == mr && a > ma)))) {
                mr = r;
                ma = a;
                mb = b;
            }
        }
        if (ma == mb && ma == -1)
            printf("No suitable tickets offered\n");
        else
            printf("Buy %d tickets for $%d\n", ma, mb);
    }
    return 0;
}
