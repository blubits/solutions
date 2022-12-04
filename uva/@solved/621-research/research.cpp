#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        char v;
        string s;
        cin >> s;
        if (s == "1" || s == "4" || s == "78") {
            v = '+';
        } else if (s[s.size() - 1] == '5' && s[s.size() - 2] == '3') {
            v = '-';
        } else if (s[0] == '9' && s[s.size() - 1] == '4') {
            v = '*';
        } else if (s[0] == '1' && s[1] == '9' && s[2] == '0') {
            v = '?';
        }
        cout << v << endl;
    }
    return 0;
}
