#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    for (auto c : s) {
        if (isupper(c)) cout << c;
    }
    cout << endl;
    return 0;
}
