#include <bitset>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int max_l;
        // maximum possible length
        for (int i = 1; i <= 10; i++) {
            if (i * exp2(i) > s.size()) {
                max_l = i - 1;
                break;
            }
        }
        for (int i = 0; i < max_l; i++) {
            return;
        }
    }
    return 0;
}
