#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int t, c = 1;
    cin >> t;
    while (t--) {
        int n, m = 0;
        cin >> n;
        while (n--) {
            int i;
            cin >> i;
            m = max(m, i);
        }
        cout << "Case " << c++ << ": " << m << endl;
    }
}
