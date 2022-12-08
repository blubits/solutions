#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    bool hiss = false;
    cin >> s;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == s[i + 1] and s[i] == 's') {
            hiss = true;
            break;
        }
    }
    if (hiss)
        cout << "hiss" << endl;
    else
        cout << "no hiss" << endl;
    return 0;
}
