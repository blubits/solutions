#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    int k;
    cin >> k;
    cin.ignore();
    while (k--) {
        string s;
        getline(cin, s);
        if (s == "P=NP")
            cout << "skipped";
        else {
            stringstream ss(s);
            int a, b;
            char x;
            ss >> a >> x >> b;
            cout << a + b;
        }
        cout << endl;
    }
}
