#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string n;
        int sum = 0;
        getline(cin, n);
        for (int i = 1; i <= n.size(); i++) {
            int d = n[n.size() - i] - '0';
            if (i % 2 == 0) {
                d *= 2;
                if (d >= 10) d -= 9;
            }
            sum += d;
        }
        if (sum % 10 == 0)
            cout << "PASS";
        else
            cout << "FAIL";
        cout << endl;
    }
}
