#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    while (getline(cin, s) && s != "#") {
        if (next_permutation(s.begin(), s.end())) {
            cout << s << endl;
        } else {
            cout << "No Successor" << endl;
        }
    }
    return 0;
}
