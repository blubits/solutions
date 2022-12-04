#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int i;
        cin >> i;
        map<string, int> m;
        while (i--) {
            string item, type;
            cin >> item >> type;
            if (m.find(type) != m.end()) {
                m[type]++;
            } else {
                m[type] = 2;
            }
        }
        int x = 1;
        for (auto s : m) {
            x *= s.second;
        }
        cout << x - 1 << endl;
    }
    return 0;
}
