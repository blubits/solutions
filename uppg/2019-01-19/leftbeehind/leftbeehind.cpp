#include <iostream>

using namespace std;

int main() {
    int x, y;
    while (cin >> x >> y && !(x == 0 && y == 0)) {
        if (x + y == 13)
            cout << "Never speak again.";
        else if (x > y)
            cout << "To the convention.";
        else if (x < y)
            cout << "Left beehind.";
        else
            cout << "Undecided.";
        cout << endl;
    }
    return 0;
}
