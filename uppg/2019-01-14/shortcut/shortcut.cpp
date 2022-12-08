#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int b, k;
        scanf("%d %d", &b, &k);
        int a = b - 1, p = 2;
        vector<int> factors;
        factors.push_back(a);
        factors.push_back(1);
        while (p <= sqrt(a)) {
            if (a % p == 0) {
                factors.push_back(p);
                if (p != a / p) factors.push_back(a / p);
            }
            p++;
        }
        sort(factors.begin(), factors.end());
        int i;
        for (i = 0; i < factors.size(); i++) {
            if (factors[i] > k) {
                cout << factors[i - 1] << endl;
                break;
            }
        }
        if (i == factors.size()) cout << factors[factors.size() - 1] << endl;
    }
}
