#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    while (cin >> t && t != 0) {
        string s;
        cin >> s;
        int g = s.size() / t;
        for (int i = 0; i < t; i++) {
            int b = i * g;
            for (int j = 0; j < g / 2; j++) {
                swap(s[b + j], s[b + (g - j - 1)]);
            }
        }
        cout << s << endl;
    }
}
