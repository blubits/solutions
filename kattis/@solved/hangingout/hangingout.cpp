#include <iostream>
#include <string>

using namespace std;

int main() {
    int l, x;
    cin >> l >> x;
    int k = 0, grps = 0;
    while (x--) {
        string c;
        int p;
        cin >> c >> p;
        if (c == "enter") {
            if (k + p > l)
                grps++;
            else
                k += p;
        } else {
            k -= p;
        }
    }
    cout << grps << endl;
    return 0;
}
