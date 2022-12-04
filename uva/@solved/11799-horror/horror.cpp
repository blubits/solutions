#include <iostream>

using namespace std;

int main() {
    int t, c = 1;
    cin >> t;
    while (t--) {
        int n, max = 0;
        cin >> n;
        while (n--) {
            int i;
            cin >> i;
            if (max < i) max = i;
        }
        cout << "Case " << c++ << ": " << max << endl;
    }
}
