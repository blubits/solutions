#include <iostream>
#include <string>

using namespace std;

int main() {
    int x = 0;
    string s = "PER", t;
    cin >> t;
    for (int i = 0; i < t.size(); i++) {
        if (t[i] != s[i % 3]) x++;
    }
    cout << x << endl;
    return 0;
}
