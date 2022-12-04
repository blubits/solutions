#include <iostream>

using namespace std;

int main() {
    int n, i, j;
    while (cin >> n >> i >> j) {
        int ans = 0;
        i--;
        j--;
        while (i != j) {
            ans++;
            i /= 2;
            j /= 2;
        }
        cout << ans << endl;
    }
}
