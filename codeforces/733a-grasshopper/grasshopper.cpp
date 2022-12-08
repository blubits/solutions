#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int mx = 1, ix = -1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'O' || s[i] == 'I' ||
            s[i] == 'U' || s[i] == 'Y') {
            mx = max(mx, i - ix);
            ix = i;
        }
    }
    mx = max(mx, int(s.size()) - ix);
    cout << mx << endl;
    return 0;
}
