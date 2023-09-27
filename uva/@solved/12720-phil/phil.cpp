#include <iostream>
#include <string>
using namespace std;

#define MOD 1000000007

int main() {
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {
        printf("Case #%d: ", i + 1);
        string s;
        getline(cin, s);
        long long int ans = 0, hi, lo;
        if (s.size() & 1) {
            ans = s[s.size() / 2] - '0';
            lo = s.size() / 2 - 1;
            hi = lo + 2;
        } else {
            lo = s.size() / 2 - 1;
            hi = lo + 1;
        }
        while (lo >= 0) {
            ans *= 4;
            ans %= MOD;
            if (s[lo] == s[hi]) {
                if (s[lo] == '1') ans += 3;
            } else {
                ans += 2;
            }
            lo--;
            hi++;
        }
        ans %= MOD;
        printf("%lld\n", ans);
    }
}