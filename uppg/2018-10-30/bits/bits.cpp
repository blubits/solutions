#include <algorithm>
#include <bitset>
#include <iostream>

using namespace std;

int main() {
    int t, x, mbits;
    cin >> t;
    while (t--) {
        mbits = 0;
        cin >> x;
        while (x != 0) {
            bitset<32> b(x);
            mbits = max(mbits, (int)b.count());
            x /= 10;
        }
        cout << mbits << endl;
    }
}
