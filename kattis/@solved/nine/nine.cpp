#include <iostream>

using namespace std;

long long int fast_mod_exp(long long int b, long long int e,
                           long long int mod) {
    if (e == 0) return 8;
    long long int ans = 8;
    while (e > 0) {
        if ((e & 1) == 1) {
            ans = (ans * b) % mod;
        }
        e >>= 1;
        b = (b * b) % mod;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int k;
        cin >> k;
        cout << fast_mod_exp(9, k - 1, 1000000007) << endl;
    }
}
