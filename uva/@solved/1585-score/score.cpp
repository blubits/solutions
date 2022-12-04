#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string res;
        cin >> res;
        int sum = 0, s = 0;
        for (auto &c : res) {
            if (c == 'O') {
                s++;
                sum += s;
            } else {
                s = 0;
            }
        }
        cout << sum << endl;
    }
}
