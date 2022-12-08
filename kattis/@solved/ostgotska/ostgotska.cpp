#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string token;
    int lw = 0, lwae = 0;
    while (cin >> token) {
        lw++;
        if (token.find("ae") != string::npos) {
            lwae++;
        }
    }
    if (lwae >= 0.4 * lw)
        cout << "dae ae ju traeligt va";
    else
        cout << "haer talar vi rikssvenska";
    cout << endl;
    return 0;
}
