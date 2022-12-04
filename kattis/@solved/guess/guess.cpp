#include <iostream>

using namespace std;

int main() {
    int l = 1, h = 1001, m = (l + h) / 2;
    string response;
    do {
        if (response == "lower") {
            h = m;
        } else if (response == "higher") {
            l = m;
        }
        m = (l + h) / 2;
        cout << m << endl;
    } while (cin >> response && response != "correct");
    return 0;
}
