#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int cup = 1;
    for (auto c : s) {
        if (c == 'A') {
            if (cup == 1)
                cup = 2;
            else if (cup == 2)
                cup = 1;
        } else if (c == 'B') {
            if (cup == 2)
                cup = 3;
            else if (cup == 3)
                cup = 2;
        } else if (c == 'C') {
            if (cup == 3)
                cup = 1;
            else if (cup == 1)
                cup = 3;
        }
    }
    cout << cup << endl;
    return 0;
}
