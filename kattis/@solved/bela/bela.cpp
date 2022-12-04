#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<char, int> dom = {{'A', 11}, {'K', 4},  {'Q', 3}, {'J', 20},
                          {'T', 10}, {'9', 14}, {'8', 0}, {'7', 0}};
    map<char, int> sub = {{'A', 11}, {'K', 4}, {'Q', 3}, {'J', 2},
                          {'T', 10}, {'9', 0}, {'8', 0}, {'7', 0}};
    int n, s = 0;
    char b;
    string c;
    cin >> n >> b;
    n *= 4;
    while (n--) {
        cin >> c;
        if (c[1] == b)
            s += dom[c[0]];
        else
            s += sub[c[0]];
    }
    cout << s << endl;
    return 0;
}
