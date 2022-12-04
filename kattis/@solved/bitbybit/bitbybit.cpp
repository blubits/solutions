#include <iostream>
using namespace std;

int r[32];

int main() {
    int t;
    while (cin >> t && t != 0) {
        for (int i = 0; i < 32; i++) r[i] = -1;
        while (t--) {
            string command;
            cin >> command;
            if (command == "SET") {
                int b;
                cin >> b;
                r[b] = 1;
            } else if (command == "CLEAR") {
                int b;
                cin >> b;
                r[b] = 0;
            } else if (command == "OR") {
                int i, j;
                cin >> i >> j;
                if (r[i] == 1 || r[j] == 1) {
                    r[i] = 1;
                } else if (r[i] == 0 && r[j] == 0) {
                    r[i] = 0;
                } else {
                    r[i] = -1;
                }
            } else if (command == "AND") {
                int i, j;
                cin >> i >> j;
                if (r[i] == 0 || r[j] == 0) {
                    r[i] = 0;
                } else if (r[i] == 1 && r[j] == 1) {
                    r[i] = 1;
                } else {
                    r[i] = -1;
                }
            }
        }
        for (int i = 31; i >= 0; i--) {
            if (r[i] == -1)
                cout << "?";
            else
                cout << r[i];
        }
        cout << endl;
    }
}
