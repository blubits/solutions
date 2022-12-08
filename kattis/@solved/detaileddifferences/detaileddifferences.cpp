#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s, t;
        cin >> s >> t;
        cout << s << endl << t << endl;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == t[i])
                cout << ".";
            else
                cout << "*";
        }
        cout << endl << endl;
    }
}
