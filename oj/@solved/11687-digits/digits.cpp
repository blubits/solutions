#include <iostream>

using namespace std;

string digits(string k) {
    string l = to_string(k.size());
    if (k == l) return "-1";
    return to_string(k.size());
}

int main() {
    string s;
    while (cin >> s && s != "END") {
        int i = 0;
        string k = s;
        while (1) {
            if (k == "-1") {
                cout << i << endl;
                break;
            }
            i++;
            k = digits(k);
        }
    }
    return 0;
}
