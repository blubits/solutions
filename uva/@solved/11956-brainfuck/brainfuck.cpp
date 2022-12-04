#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int t, c = 1;
    cin >> t;
    while (t--) {
        unsigned char memory[100];
        for (int i = 0; i < 100; i++) memory[i] = 0;
        int p = 0;
        string code;
        cin >> code;
        for (char c : code) {
            if (c == '+')
                memory[p]++;
            else if (c == '-')
                memory[p]--;
            else if (c == '>') {
                p = p + 1;
                if (p == 100) p = 0;
            } else if (c == '<') {
                p = p - 1;
                if (p == -1) p = 99;
            }
        }
        cout << "Case " << c++ << ":";
        for (int i = 0; i < 100; i++) printf(" %02X", memory[i]);
        cout << endl;
    }
    return 0;
}
