#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    int c = 1;
    while (1) {
        cin >> s;
        if (s == "*") break;
        if (s == "Hajj") {
            cout << "Case " << c << ": Hajj-e-Akbar" << endl;
        } else {
            cout << "Case " << c << ": Hajj-e-Asghar" << endl;
        }
        c++;
    }
    return 0;
}
