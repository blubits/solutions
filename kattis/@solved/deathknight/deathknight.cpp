#include <iostream>
#include <string>

using namespace std;

int main() {
    int t, c = 0;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        if (s.find("CD") == std::string::npos) c++;
    }
    cout << c << endl;
    return 0;
}
