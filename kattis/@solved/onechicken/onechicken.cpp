#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int k = b - a;
    if (k > 0) {
        string word = (k == 1) ? " piece " : " pieces ";
        cout << "Dr. Chaz will have " << k << word << "of chicken left over!";
    } else {
        string word = (k == -1) ? " piece " : " pieces ";
        cout << "Dr. Chaz needs " << -k << " more" << word << "of chicken!";
    }
    cout << endl;
    return 0;
}
