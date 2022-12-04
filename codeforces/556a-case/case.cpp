#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int z = 0, o = 0, t;
    cin >> t;
    while (t--) {
        char x;
        cin >> x;
        if (x == '0')
            z++;
        else
            o++;
    }
    cout << abs(z - o) << endl;
}
