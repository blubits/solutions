#include <iostream>
using namespace std;

int main() {
    int t = 10, sum = 0, x;
    int a[42] = {0};
    while (t--) {
        cin >> x;
        a[x % 42] = 1;
    }
    for (int i = 0; i < 42; i++) {
        sum += a[i];
    }
    cout << sum << endl;
    return 0;
}
