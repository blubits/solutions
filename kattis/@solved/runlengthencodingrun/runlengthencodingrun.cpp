#include <iostream>
#include <string>

using namespace std;

int main() {
    char c;
    string text, mod;
    cin >> c >> text;
    if (c == 'E') {
        char curr = text[0];
        int n = 0;
        for (char c : text) {
            if (curr == c)
                n++;
            else {
                mod += curr;
                mod += char('0' + n);
                curr = c;
                n = 1;
            }
        }
        mod += curr;
        mod += char('0' + n);
    } else {
        char curr;
        int n;
        for (char c : text) {
            if ('0' <= c && c <= '9') {
                n = int(c - '0');
                for (int i = 0; i < n; i++) {
                    mod += curr;
                }
            } else {
                curr = c;
            }
        }
    }
    cout << mod << endl;
    return 0;
}
