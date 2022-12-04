#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    int p, n;
    string s;
    bool paradox = false;
    cin >> p >> n;
    set<string> parts;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        parts.insert(s);
        if (parts.size() == p) {
            paradox = true;
            cout << i;
            break;
        }
    }
    if (!paradox) cout << "paradox avoided";
    cout << endl;
    return 0;
}
