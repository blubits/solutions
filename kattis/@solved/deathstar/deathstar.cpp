#include <iostream>
using namespace std;

int main() {
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int ans = 0;
        for (int j = 0; j < k; j++) {
            int n;
            cin >> n;
            ans |= n;
        }
        cout << ans << " ";
    }
    cout << endl;
}