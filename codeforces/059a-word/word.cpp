#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int lo = 0, up = 0;
    for (auto c : s) {
        if ('A' <= c && c <= 'Z')
            up++;
        else
            lo++;
    }
    if (up > lo) {
        for (auto c : s) cout << char(toupper(c));
    } else {
        for (auto c : s) cout << char(tolower(c));
    }
    cout << endl;
}
