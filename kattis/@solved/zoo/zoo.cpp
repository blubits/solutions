#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

int main() {
    int k, c = 1;
    while (cin >> k && k != 0) {
        cin.ignore();
        string line, token;
        map<string, int> zoo;
        while (k--) {
            getline(cin, line);
            stringstream ss(line);
            while (ss >> token)
                ;
            transform(token.begin(), token.end(), token.begin(), ::tolower);
            if (zoo.find(token) != zoo.end()) {
                zoo[token] += 1;
            } else {
                zoo[token] = 1;
            }
        }
        cout << "List " << c++ << ":" << endl;
        for (auto p : zoo) {
            cout << p.first << " | " << p.second << endl;
        }
    }
    return 0;
}
