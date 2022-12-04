#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int t, c = 1;
    while (cin >> t && t != 0) {
        vector<string> names;
        string name;
        while (t--) {
            cin >> name;
            names.push_back(name);
        }
        int i;
        cout << "SET " << c++ << endl;
        for (i = 0; i < names.size(); i += 2) {
            cout << names[i] << endl;
        }
        if (i == names.size() + 1)
            i -= 3;
        else
            i = names.size() - 1;
        for (; i > 0; i -= 2) {
            cout << names[i] << endl;
        }
    }
    return 0;
}
