#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (1) {
        string name;
        string recipient;
        int recipients;
        int total;
        map<string, int> bal;
        vector<string> names;
        for (int i = 0; i < t; i++) {
            cin >> name;
            bal[name] = 0;
            names.push_back(name);
        }
        for (int i = 0; i < t; i++) {
            cin >> name >> total >> recipients;
            int to_give;
            if (recipients != 0)
                to_give = total / recipients;
            else
                to_give = 0;
            bal[name] -= to_give * recipients;
            for (int j = 0; j < recipients; j++) {
                cin >> recipient;
                bal[recipient] += to_give;
            }
        }
        for (auto name : names) {
            cout << name << " " << bal[name] << endl;
        }
        if (cin >> t)
            cout << endl;
        else
            break;
    }
    return 0;
}
