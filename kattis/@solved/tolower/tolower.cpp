#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int p, t, solved = 0;
    cin >> p >> t;
    cin.ignore();
    while (p--) {
        bool passed = true;
        for (int i = 0; i < t; i++) {
            string s;
            getline(cin, s);
            if (!passed) continue;
            for (int j = 1; j < s.size(); j++) {
                if (s[j] != tolower(s[j])) {
                    passed = false;
                    break;
                }
            }
        }
        if (passed) solved++;
    }
    cout << solved << endl;
    return 0;
}
