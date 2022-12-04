#include <iostream>
#include <string>

using namespace std;

int main() {
    int r, c, zr, zc;
    cin >> r >> c >> zr >> zc;
    while (r--) {
        string s;
        cin >> s;
        for (int a = 0; a < zr; a++) {
            for (int i = 0; i < c; i++) {
                for (int b = 0; b < zc; b++) {
                    cout << s[i];
                }
            }
            cout << endl;
        }
    }
    return 0;
}
