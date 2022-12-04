#include <iostream>
#include <string>

using namespace std;

int main() {
    int t, n1;
    string n;
    cin >> t;
    while (t--) {
        cin >> n;
        if (n.size() == 5) {
            n1 = 3;
        } else if ((n[0] == 'o' && n[1] == 'n') ||
                   (n[0] == 'o' && n[2] == 'e') ||
                   (n[1] == 'n' && n[2] == 'e')) {
            n1 = 1;
        } else {
            n1 = 2;
        }
        cout << n1 << endl;
    }
    return 0;
}
