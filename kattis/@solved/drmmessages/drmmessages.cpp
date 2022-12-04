#include <iostream>
#include <string>

using namespace std;

int main() {
    string s, l, r, m;
    getline(cin, s);
    int lv = 0, rv = 0, h = s.size() / 2;
    for (int i = 0; i < h; i++) {
        lv += s[i] - 'A';
        rv += s[h + i] - 'A';
    }
    for (int i = 0; i < h; i++) {
        l += char('A' + ((s[i] - 'A' + lv) % 26));
        r += char('A' + ((s[h + i] - 'A' + rv) % 26));
    }
    for (int i = 0; i < h; i++) {
        m += char('A' + (((l[i] - 'A') + (r[i] - 'A')) % 26));
    }
    cout << m << endl;
    return 0;
}
