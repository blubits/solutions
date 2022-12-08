#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int k;
    cin >> k;
    cin.ignore();
    while (k--) {
        string s;
        getline(cin, s);
        int side = sqrt(s.size());
        for (int i = 0; i < s.size(); i++) {
            int col = (side - 1) - (i / side);
            int row = i % side;
            int pos = (row * side) + col;
            cout << s[pos];
        }
        cout << endl;
    }
}
