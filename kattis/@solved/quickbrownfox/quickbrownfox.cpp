#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    bool alpha[26];
    cin >> t;
    cin.ignore();
    while (t--) {
        for (int i = 0; i < 26; i++) alpha[i] = false;
        string line;
        getline(cin, line);
        for (char c : line) {
            if ('a' <= tolower(c) && tolower(c) <= 'z') {
                alpha[tolower(c) - 'a'] = true;
            }
        }
        string missing;
        for (int i = 0; i < 26; i++) {
            if (!alpha[i]) missing += char('a' + i);
        }
        if (missing.size() == 0)
            cout << "pangram";
        else
            cout << "missing " << missing;
        cout << endl;
    }
    return 0;
}
