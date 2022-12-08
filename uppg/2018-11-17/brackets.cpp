#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    while (cin >> t) {
        cin.ignore();
        string s;
        getline(cin, s);
        for (auto c : s) {
            if (('!' <= c && c <= '*') || ('[' <= c && c <= ']')) {
                for (int i = 1; i < (1 << t); i++) {
                    cout << '\\';
                }
            }
            cout << c;
        }
        cout << endl;
    }
}
