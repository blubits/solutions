#include <iostream>
#include <string>

using namespace std;

int main() {
    bool start = true;
    string s;
    while (getline(cin, s)) {
        for (auto c : s) {
            if (c == '"') {
                if (start)
                    cout << "``";
                else
                    cout << "''";
                start = !start;
            } else {
                cout << c;
            }
        }
        cout << endl;
    }
    return 0;
}
