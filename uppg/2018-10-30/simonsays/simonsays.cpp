#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    string s;
    cin >> t;
    // absorb \n
    getline(cin, s);
    while (t--) {
        getline(cin, s);
        if (s.substr(0, 10) == "Simon says") {
            cout << s.substr(10, s.size()) << endl;
        }
    }
    return 0;
}
