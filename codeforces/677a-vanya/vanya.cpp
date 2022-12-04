#include <iostream>

using namespace std;

int main() {
    int n, h, ans = 0;
    cin >> n >> h;
    while (n--) {
        int i;
        cin >> i;
        if (i > h) ans++;
        ans++;
    }
    cout << ans << endl;
}
